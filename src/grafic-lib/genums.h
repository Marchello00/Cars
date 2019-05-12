#ifndef CARS_GENUMS_H
#define CARS_GENUMS_H

#pragma once

#include <SFML/System.hpp>
#include "ground.h"

const int CAR_WIDTH = 42;
const int CAR_HEIGHT = 90;

const float WHEEL_ROTATE_SPEED = 0.1;
const float WHEEL_BACK_SPEED = 0.6;
const float WHEEL_BUFF = 80;
const float DEFAULT_SPEED_E = 2;
const float DEFAULT_ACCELERATION_E = 3;

const float STOP_ROTATE = 25;

enum class CAR_STATE {BACKWARD, STAY, FORWARD};
const float SLOW_GRASS_RESISTANCE = 5;
const float SLOW_SAND_RESISTANCE = 3;
const float DAMAGE_DIRT_DAMAGE = 1;

const float DAMAGE_DIRT_INTERVAL = 1;

const int FONT_SIZE = 25;

namespace enums {
    int getRotation(std::string &s);

    sf::Vector2f getDirection(std::string &s);

    std::shared_ptr<CBaseGround> getGround(const std::string& type, const std::string& material);
}

#endif //CARS_GENUMS_H
