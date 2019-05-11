#ifndef CARS_GENUMS_H
#define CARS_GENUMS_H

#pragma once

const int CAR_WIDTH = 42;
const int CAR_HEIGHT = 90;

const float ANGLE_CHANGE_SPEED = 1;
const float DEFAULT_SPEED_E = 0.5;
const float DEFAULT_ACCELERATION_E = 0.5;

namespace enums {
    int getRotation(std::string &s);
}

#endif //CARS_GENUMS_H
