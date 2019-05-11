#ifndef CARS_GENUMS_H
#define CARS_GENUMS_H

#pragma once

#include <SFML/System.hpp>

const int CAR_WIDTH = 42;
const int CAR_HEIGHT = 90;

const float WHEEL_ROTATE_SPEED = 0.1;
const float WHEEL_BACK_SPEED = 0.6;
const float DEFAULT_SPEED_E = 1;
const float DEFAULT_ACCELERATION_E = 3;
const float STOP_ROTATE = 25;

enum class CAR_STATE {BACKWARD, STAY, FORWARD};

namespace enums {
    int getRotation(std::string &s);

    sf::Vector2f getDirection(std::string &s);
}

#endif //CARS_GENUMS_H
