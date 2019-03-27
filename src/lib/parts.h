#ifndef CARS_PARTS_H
#define CARS_PARTS_H

#include "enums.h"
#include "base.h"

class CStreetPart: CPart {
public:
    explicit CStreetPart(int partType): CPart(ECarType::STREET, partType) { }
};

class CRacePart: CPart {
public:
    explicit CRacePart(int partType): CPart(ECarType::STREET, partType) { }
};

class CSuperPart: CPart {
public:
    explicit CSuperPart(int partType): CPart(ECarType::STREET, partType) { }
};

#endif //CARS_PARTS_H
