#ifndef CARS_ENUMS_H
#define CARS_ENUMS_H

enum ECarType {
    STREET, RACE, SUPER
};

enum EPartType {
    ENGINE, WHEELS, SUSPENSION, BRAKES, TRANSMISSION, BODY
};

const double STREET_PART_ON_RACE = 0.6;
const double STREET_PART_ON_SUPER = 0.2;
const double RACE_PART_ON_SUPER = 0.5;

#endif //CARS_ENUMS_H
