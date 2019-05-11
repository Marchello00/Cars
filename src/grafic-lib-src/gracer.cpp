#include <utility>

#include "../grafic-lib/gracer.h"
#include <cmath>
#include <iostream>

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

//double getAngle(const sf::Vector2f &a, const sf::Vector2f &b) {
//    return toDegrees(atan2(a * b, a % b));
//}

sf::Vector2f rotate(const sf::Vector2f &a, float angle) {
    angle = toRadians(angle);
    return {a.x * cos(angle) - a.y * sin(angle),
            a.x * sin(angle) + a.y * cos(angle)};
}

Racer::Racer() :
        position({0, 0}), speed(0),
        acceleration(0),
        deceleration(0), state(CAR_STATE::STAY),
        wheel(0), direction({1, 0}) {}

void Racer::update(float tm, const std::shared_ptr<CBaseGround> &ground) {
    setPosition(position + direction * speed * tm);
    changeSpeed(tm, ground);
}

void Racer::render(sf::RenderWindow &window) {
    sprite.setPosition(position);
    sprite.setRotation(toDegrees(getAngle()));
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

void Racer::setCar(std::shared_ptr<CCar> new_car) {
    car = std::move(new_car);
}

void Racer::changeSpeed(float tm, const std::shared_ptr<CBaseGround> &ground) {
    if (state == CAR_STATE::STAY) {
        return;
    }
    if (state == CAR_STATE::BACKWARD) {
        speed *= -1;
    }
    auto acc = acceleration - deceleration - ground->getResistance();
    speed += acc * tm;
    speed = fmax(speed, 0);
    speed = fmin(speed, car->getMaxSpeed() * DEFAULT_SPEED_E);

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
    std::cout << "Speed: " << speed <<
              ", State: " << int(state) << ", Wheel :" << wheel << ", Acc: " << acc <<
              ", Dir: {" << direction.x << ", " << direction.y << "}\n";
    /*
    auto acc = getAcceleration(ground);
    auto sp = direction * speed;
    auto old = sp;
    sp.x += acc.x * tm;
    sp.y += acc.y * tm;
    if (old % sp < 0) {
        speed = 0;
        state = CAR_STATE::STAY;
    } else {
        speed = hypot(sp.y, sp.x);
        if (state == CAR_STATE::BACKWARD) {
            speed = -speed;
        }
        sp.x /= speed;
        sp.y /= speed;
        direction = sp;
        speed = fmin(speed, car->getMaxSpeed() * DEFAULT_SPEED_E);
    }
    std::cout << "Speed: " << speed <<
    ", State: " << int(state) << ", Wheel :" << wheel <<
    ", Acc: {" << acc.x << ", " << acc.y << "}, Dir: {" << direction.x << ", " << direction.y << "}\n";*/
}

sf::Vector2f Racer::getAcceleration(const std::shared_ptr<CBaseGround> &ground) {
    float accValue = acceleration - deceleration - ground->getResistance();
    float wheelAngle = wheel;
    auto acc = direction * accValue;
    if (state == CAR_STATE::BACKWARD) {
        acc = -acc;
        wheelAngle = -wheelAngle;
    }
    return rotate(acc, wheelAngle);
}

void Racer::leftTurn(float tm) {
    if (state == CAR_STATE::STAY) return;
    if (wheel > -STOP_ROTATE) {
        wheel -= WHEEL_ROTATE_SPEED * tm;
    }
}


void Racer::rightTurn(float tm) {
    if (state == CAR_STATE::STAY) return;
    if (wheel < STOP_ROTATE) {
        wheel += WHEEL_ROTATE_SPEED * tm;
    }
}

void Racer::moveForward() {
    if (state == CAR_STATE::STAY) {
        state = CAR_STATE::FORWARD;
    }
    if (state != CAR_STATE::BACKWARD) {
        acceleration = car->getAcceleration() * DEFAULT_ACCELERATION_E;
    } else {
        deceleration = car->getDeceleration() * DEFAULT_ACCELERATION_E;
    }
}

void Racer::moveBackward() {
    if (state == CAR_STATE::STAY) {
        state = CAR_STATE::BACKWARD;
    }
    if (state != CAR_STATE::FORWARD) {
        acceleration = car->getAcceleration() * DEFAULT_ACCELERATION_E;
    } else {
        deceleration = car->getDeceleration() * DEFAULT_ACCELERATION_E;
    }
}

void Racer::reactBackward() {
    if (state != CAR_STATE::FORWARD) {
        acceleration = 0;
    }
    if (state != CAR_STATE::BACKWARD) {
        deceleration = 0;
    }
}

void Racer::reactForward() {
    if (state != CAR_STATE::BACKWARD) {
        acceleration = 0;
    }
    if (state != CAR_STATE::FORWARD) {
        deceleration = 0;
    }
}

void Racer::reactLeft(float tm) {
    if (wheel < 0) {
        wheel = fmin(0, wheel + WHEEL_BACK_SPEED * tm);
    }
}

void Racer::reactRight(float tm) {
    if (wheel > 0) {
        wheel = fmax(0, wheel - WHEEL_BACK_SPEED * tm);
    }
}

float Racer::getAngle() {
    return atan2(direction.y, direction.x);
}

void Racer::setDirection(sf::Vector2f dir) {
    direction = dir;
}
