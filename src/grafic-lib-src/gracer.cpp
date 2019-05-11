#include <utility>

#include "../grafic-lib/gracer.h"
#include <cmath>

Racer::Racer() :
        position({0, 0}), speed({0, 0}), acceleration(0), angle(0) { }

void Racer::update(float tm, const CBaseGround &ground) {
    setPosition({position.x + speed.x * tm,
            position.y + speed.y * tm});
    changeSpeed(tm, ground);
}

void Racer::render(sf::RenderWindow &window) {
    sprite.setPosition(position);
    if (isMoving()) {
        double spAngle = atan2(speed.y, speed.x);
        sprite.setRotation(spAngle);
    } else {
        sprite.setRotation(angle);
    }
    window.draw(sprite);
}

void Racer::setPosition(sf::Vector2f newPosition) {
    position = newPosition;
}

void Racer::setImage(const std::string& path) {
    texture.loadFromFile(path);
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.0, texture.getSize().y / 2.0);
    sprite.setScale(1.0 * h / texture.getSize().x, 1.0 * w / texture.getSize().y);
}

void Racer::setRotation(double alpha) {
    angle = alpha;
}

void Racer::setCar(std::shared_ptr<CCar> new_car) {
    car = std::move(new_car);
}

void Racer::setSpeedE(float newSpeedE) {
    speedE = newSpeedE;
}

void Racer::changeSpeed(float tm, const CBaseGround &ground) {
    auto acc = getAcceleration(ground);
    speed.x += cos(angle) * acc * tm;
    speed.y += sin(angle) * acc * tm;
    if (hypot(speed.x, speed.y) > car->getMaxSpeed() * speedE) {
        double mult = sqrt(car->getMaxSpeed() * speedE) / hypot(speed.x, speed.y);
        speed.x *= mult;
        speed.y *= mult;
    }
}

bool Racer::isMoving() {
    return hypot(speed.x, speed.y) >= EPS;
}

double Racer::getAcceleration(const CBaseGround &ground) {
    return acceleration * ground.getSlow() / ground.getSlippy();
}

void Racer::leftTurn() {
    if (isMoving()) {
        angle -= ANGLE_CHANGE_SPEED;
    }
}

void Racer::rightTurn() {
    if (isMoving()) {
        angle += ANGLE_CHANGE_SPEED;
    }
}

void Racer::moveForward() {
    acceleration = car->getAcceleration() * DEFAULT_ACCELERATION_E;
}

void Racer::moveBackward() {
    acceleration = car->getDeceleration() * DEFAULT_ACCELERATION_E;
}
