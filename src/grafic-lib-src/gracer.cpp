#include <utility>

#include "../grafic-lib/gracer.h"
#include <cmath>
#include <iostream>

double toDegrees(double radians) {
    return radians / M_PI * 180.0;
}

double operator%(const sf::Vector2f &a, const sf::Vector2f &b) {
    return a.x * b.x + a.y * b.y;
}

double operator*(const sf::Vector2f &a, const sf::Vector2f &b) {
    return a.x * b.y - a.y * b.x;
}

double getAngle(const sf::Vector2f &a, const sf::Vector2f &b) {
    return toDegrees(atan2(a * b, a % b));
}

Racer::Racer() :
        position({0, 0}), speed({0, 0}),
        acceleration(0), angle(0),
        deceleration(0), movingForward(true) {}

void Racer::update(float tm, const std::shared_ptr<CBaseGround> &ground) {
    setPosition({position.x + speed.x * tm,
                 position.y + speed.y * tm});
    changeSpeed(tm, ground);
}

void Racer::render(sf::RenderWindow &window) {
    sprite.setPosition(position);
    if (isMoving()) {
        double spAngle = getMovingAngle();
        if (!movingForward) {
            spAngle += 180;
        }
        sprite.setRotation(spAngle);
    } else {
        sprite.setRotation(angle);
    }
    window.draw(sprite);
}

void Racer::setPosition(sf::Vector2f newPosition) {
    position = newPosition;
}

void Racer::setImage(const std::string &path) {
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

void Racer::changeSpeed(float tm, const std::shared_ptr<CBaseGround> &ground) {
    changeAcceleration(ground);
    auto old = speed;
    speed.x += acc.x * tm;
    speed.y += acc.y * tm;
    if (old % speed < 0 && acceleration == 0 && deceleration == 0) {
        speed.x = 0, speed.y = 0;
    }
    movingForward = (acceleration - deceleration > 0 && acc % speed > 0) ||
                    (acceleration - deceleration < 0 && acc % speed < 0);
    if (hypot(speed.x, speed.y) > car->getMaxSpeed() * DEFAULT_SPEED_E) {
        double mult = car->getMaxSpeed() * DEFAULT_SPEED_E / hypot(speed.x, speed.y);
        speed.x *= mult;
        speed.y *= mult;
    }
}

bool Racer::isMoving() {
    return hypot(speed.x, speed.y) >= EPS;
}

sf::Vector2f Racer::changeAcceleration(const std::shared_ptr<CBaseGround> &ground) {
    float acc_diff = acceleration - deceleration;
    acc = {acc_diff * cos(getRadian()), acc_diff * sin(getRadian())};
    if (isMoving()) {
        auto resist = -speed;
        resist.x /= hypot(speed.x, speed.y);
        resist.y /= hypot(speed.x, speed.y);
        resist.x *= ground->getResistance();
        resist.y *= ground->getResistance();
        acc += resist;
    }
    return acc;
}

void Racer::leftTurn() {
    if (isMoving()) {
        if (acc % speed < 0) {
            if (getAngle(acc, speed) > 90 - STOP_ROTATE) {
                angle -= ANGLE_CHANGE_SPEED;
            }
        } else {
            if (getAngle(acc, speed) < STOP_ROTATE) {
                angle -= ANGLE_CHANGE_SPEED;
            }
        }
    }
}

float Racer::getMovingAngle() {
    if (isMoving()) {
        return toDegrees(atan2(speed.y, speed.x));
    } else {
        return angle;
    }
}

void Racer::rightTurn() {
    if (isMoving()) {
        if (acc % speed < 0) {
            if (getAngle(acc, speed) > 90 - STOP_ROTATE) {
                angle += ANGLE_CHANGE_SPEED;
            }
        } else {
            if (getAngle(acc, speed) < STOP_ROTATE) {
                angle += ANGLE_CHANGE_SPEED;
            }
        }
    }
}

void Racer::moveForward() {
    acceleration = car->getAcceleration() * DEFAULT_ACCELERATION_E;
}

void Racer::moveBackward() {
    deceleration = car->getDeceleration() * DEFAULT_ACCELERATION_E;
}

float Racer::getRadian() {
    return angle / 180.0 * M_PI;
}

void Racer::resetDeceleration() {
    deceleration = 0;
}

void Racer::resetAcceleration() {
    acceleration = 0;
}

void Racer::resetAngle() {
    angle = getMovingAngle();
}
