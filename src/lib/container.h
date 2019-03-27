#ifndef CARS_CONTAINER_H
#define CARS_CONTAINER_H

#include <vector>
#include "base.h"

class CarHolder {
private:
    std::vector<CCar *> cars;
};

class PartHolder {
private:
    std::vector<CPart *> part;
};

#endif //CARS_CONTAINER_H
