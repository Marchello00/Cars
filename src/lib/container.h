#ifndef CARS_CONTAINER_H
#define CARS_CONTAINER_H

#include <vector>
#include "cars.h"
#include "parts.h"

class CarHolder {
private:
    std::vector<CCar *> cars;
};

class PartHolder {
private:
    std::vector<CPart *> parts;
};

#endif //CARS_CONTAINER_H
