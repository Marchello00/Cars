#ifndef CARS_GLEVEL_H
#define CARS_GLEVEL_H

#pragma once

#include "TmxLevel.h"
#include "gracer.h"

class GLevel: public TmxLevel {
public:
    void addRacer(GRacer *racer);

    void notify();
private:
    std::vector<GRacer *> racers;
};

#endif //CARS_GLEVEL_H
