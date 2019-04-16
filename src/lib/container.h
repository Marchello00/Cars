#ifndef CARS_CONTAINER_H
#define CARS_CONTAINER_H

#include <vector>
#include "cars.h"
#include "parts.h"
#include "base.h"

class CHolder {
private:
    std::vector<CBase *>
};

class CCarHolder {
private:
    std::vector<CCar *> cars;
};

class CPartHolder {
private:
    std::vector<CPart *> parts;
};

#endif //CARS_CONTAINER_H
