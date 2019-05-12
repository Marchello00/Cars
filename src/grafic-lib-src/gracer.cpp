#include <utility>

#include "../grafic-lib/gracer.h"
#include <cmath>
#include <iostream>
#include <sstream>
#include <set>

template<typename T>
std::string to_string(const T a_value, const int n = 2) {
    std::ostringstream out;
    out.precision(n);
    out << std::fixed << a_value;
    return out.str();
}

float toDegrees(float radians) {
    return radians / M_PI * 180.0f;
}

float toRadians(float degrees) {
    return degrees / 180.0f * M_PI;
}

double operator%(const sf::Vector2f &a, const sf::Vector2f &b) {
    return a.x * b.x + a.y * b.y;
}

double operator*(const sf::Vector2f &a, const sf::Vector2f &b) {
    return a.x * b.y - a.y * b.x;
}

sf::Vector2f rotate(const sf::Vector2f &a, float angle) {
    angle = toRadians(angle);
    return {a.x * cos(angle) - a.y * sin(angle),
            a.x * sin(angle) + a.y * cos(angle)};
}

GRacer::GRacer() :
        position({0, 0}), speed(0),
        acceleration(0), lives(0),
        deceleration(0), state(CAR_STATE::STAY),
        wheel(0), direction({1, 0}),
        ground(std::make_shared<CBaseGround>()) {}

void GRacer::update(float tm, float &accumulate_tm, const std::vector<std::shared_ptr<GBonus>> &bonuses) {
    if (state == CAR_STATE::LOSE) {
        return;
    }
    analyseObjects();
    position += direction * speed * tm;
    checkBorders();
    analyseBonuses(bonuses);
    changeSpeed(tm);
    checkDamage(accumulate_tm);
    checkLives();
}

void GRacer::render(sf::RenderWindow &window) {
    sprite.setPosition(position);
    sprite.setRotation(toDegrees(getAngle()));
    if (ground->getDamage()) {
        sprite.setColor(sf::Color::Red);
    } else {
        sprite.setColor(sf::Color::White);
    }
    if (state == CAR_STATE::LOSE) {
        sprite.setColor(sf::Color::Black);
    }
    window.draw(sprite);
}

void GRacer::setPosition(sf::Vector2f newPosition) {
    position = newPosition;
}

void GRacer::setImage(const std::string &path) {
    texture.loadFromFile(path);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.0, texture.getSize().y / 2.0);
    sprite.setScale(1.0 * h / texture.getSize().x, 1.0 * w / texture.getSize().y);
}

void GRacer::setCar(std::shared_ptr<CCar> new_car) {
    car = std::move(new_car);
    lives = car->getLives();
}

void GRacer::changeSpeed(float tm) {
    if (state == CAR_STATE::STAY) {
        return;
    }
    if (state == CAR_STATE::BACKWARD) {
        speed *= -1;
    }
    auto acc = acceleration - deceleration - ground->getResistance();
    speed += acc * tm;
    speed = fmax(speed, 0);
    speed = fmin(speed, car->getMaxSpeed() * (1.0 / ground->getResistance()) * DEFAULT_SPEED_E);

    if (speed == 0) {
        state = CAR_STATE::STAY;
        wheel = 0;
    }

    double wheelHere = wheel;

    if (state == CAR_STATE::BACKWARD) {
        speed *= -1;
        wheelHere = -wheelHere;
    }

    direction = rotate(direction, wheelHere);
}

void GRacer::leftTurn(float tm) {
    if (state == CAR_STATE::STAY) return;
    if (wheel > -STOP_ROTATE) {
        wheel -= WHEEL_ROTATE_SPEED * car->getMaxSpeed() / WHEEL_BUFF * tm;
    }
}


void GRacer::rightTurn(float tm) {
    if (state == CAR_STATE::STAY) return;
    if (wheel < STOP_ROTATE) {
        wheel += WHEEL_ROTATE_SPEED * car->getMaxSpeed() / WHEEL_BUFF * tm;
    }
}

void GRacer::moveForward() {
    if (state == CAR_STATE::STAY) {
        state = CAR_STATE::FORWARD;
    }
    if (state != CAR_STATE::BACKWARD) {
        acceleration = car->getAcceleration() * DEFAULT_ACCELERATION_E;
    } else {
        deceleration = car->getDeceleration() * DEFAULT_ACCELERATION_E;
    }
}

void GRacer::moveBackward() {
    if (state == CAR_STATE::STAY) {
        state = CAR_STATE::BACKWARD;
    }
    if (state != CAR_STATE::FORWARD) {
        acceleration = car->getAcceleration() * DEFAULT_ACCELERATION_E;
    } else {
        deceleration = car->getDeceleration() * DEFAULT_ACCELERATION_E;
    }
}

void GRacer::reactBackward() {
    if (state != CAR_STATE::FORWARD) {
        acceleration = 0;
    }
    if (state != CAR_STATE::BACKWARD) {
        deceleration = 0;
    }
}

void GRacer::reactForward() {
    if (state != CAR_STATE::BACKWARD) {
        acceleration = 0;
    }
    if (state != CAR_STATE::FORWARD) {
        deceleration = 0;
    }
}

void GRacer::reactLeft(float tm) {
    if (wheel < 0) {
        wheel = fmin(0, wheel + WHEEL_BACK_SPEED * car->getMaxSpeed() / WHEEL_BUFF * tm);
    }
}

void GRacer::reactRight(float tm) {
    if (wheel > 0) {
        wheel = fmax(0, wheel - WHEEL_BACK_SPEED * car->getMaxSpeed() / WHEEL_BUFF * tm);
    }
}

float GRacer::getAngle() {
    return atan2(direction.y, direction.x);
}

void GRacer::setDirection(sf::Vector2f dir) {
    direction = dir;
}

void GRacer::addObject(TmxObject &obj) {
    objects.push_back(obj);
}

void GRacer::setField(sf::Vector2f sz) {
    border = sf::FloatRect(0, 0, sz.x, sz.y);
}

void GRacer::analyseObjects() {
    ground = std::make_shared<CBaseGround>();
    walls.clear();
    std::vector<std::shared_ptr<CBaseGround>> v;
    for (auto &object : objects) {
        if (object.type == "wall") {
            walls.push_back(object.rect);
        }
        if (object.name == "Surface") {
            std::string t = object.type, m = object.getPropertyString("material");
            v.push_back(enums::getGround(object.type, object.getPropertyString("material")));
        }
    }
    std::sort(v.begin(), v.end(), [&](const std::shared_ptr<CBaseGround> &a, const std::shared_ptr<CBaseGround> &b) {
        return a->getDamage() < b->getDamage() || (a->getDamage() == b->getDamage() &&
                                                   a->getResistance() < b->getResistance());
    });
    if (!v.empty()) {
        ground = v[0];
    }
    objects.clear();
}

void GRacer::checkDamage(float &accumulate_tm) {
    if (accumulate_tm >= ground->getDamageInterval()) {
        accumulate_tm -= ground->getDamageInterval();
        lives -= ground->getDamage();
    }
    if (ground->getDamageInterval() == 0) {
        accumulate_tm = 0;
    }
}

std::string GRacer::getText() {
    if (mission.empty()) {
        setMissionScore();
    }
    if (state == CAR_STATE::LOSE) {
        return GAME_OVER;
    }
    auto txt = "Lives: " + std::to_string(lives) + "\n" +
               "Speed: " + to_string(speed / DEFAULT_SPEED_E, 2) + "\n" +
               "Score: " + to_string(score) + "\n" +
               mission +
               debug;
    debug.clear();
    return txt;
}

bool GRacer::checkWalls() {
    return true;
}

bool GRacer::checkBorders() {
    auto rect = shape().getGlobalBounds();
    while (!border.contains({rect.left, rect.top})) {
        position += DOWN + RIGHT;
        rect = shape().getGlobalBounds();
    }
    while (!border.contains({rect.left + rect.width, rect.top})) {
        position += DOWN + LEFT;
        rect = shape().getGlobalBounds();
    }
    while (!border.contains({rect.left, rect.top + rect.height})) {
        position += UP + RIGHT;
        rect = shape().getGlobalBounds();
    }
    while (!border.contains({rect.left + rect.width, rect.top + rect.height})) {
        position += UP + LEFT;
        rect = shape().getGlobalBounds();
    }
    return true;
}

sf::ConvexShape GRacer::shape() {
    sf::ConvexShape convex;
    convex.setPointCount(4);
    float x = position.x, y = position.y;
    sf::Vector2f ndir = {-direction.y, direction.x};
    convex.setPoint(0, position + direction * (h / 2.f) - ndir * (h / 2.f));
    convex.setPoint(1, position + direction * (h / 2.f) + ndir * (h / 2.f));
    convex.setPoint(2, position - direction * (h / 2.f) + ndir * (h / 2.f));
    convex.setPoint(3, position - direction * (h / 2.f) - ndir * (h / 2.f));
    return convex;
}

bool GRacer::intersect(const sf::FloatRect &fr) {
    return sprite.getGlobalBounds().intersects(fr);
}

void GRacer::analyseBonuses(const std::vector<std::shared_ptr<GBonus>> &bonuses) {
    for (auto &b : bonuses) {
        if (b->intersects(sprite.getGlobalBounds())) {
            b->applyToRacer(*this);
        }
    }
}

void GRacer::applyPoint(GPoint &point) {
    score += point.getScore();
}

void GRacer::setGoal(int g) {
    goal = g;
}

int GRacer::getScore() const {
    return score;
}

int GRacer::getGoal() const {
    return goal;
}

void GRacer::applyHeal(GHeal &heal) {
    lives += heal.getHeal();
    setMissionScore();
}

void GRacer::setMission(const std::string &m) {
    mission = m;
}

void GRacer::setMissionScore() {
    mission = SCORE_MISSION_BEGIN + to_string(goal) + SCORE_MISSION_END;
}

void GRacer::setPieMessage() {
    mission = PIE_MESSAGE;
}

void GRacer::checkLives() {
    if (lives <= 0) {
        lives = 0;
        state = CAR_STATE::LOSE;
    }
}
