#include <iostream>
#include "../grafic-lib/glevel.h"

void GLevel::addRacer(GRacer *racer) {
    racers.push_back(racer);
}

void GLevel::notify() {
    for (auto object : m_objects) {
        for (const auto& racer : racers) {
            if (racer->intersect(object.rect) || object.type == "wall") {
                racer->addObject(object);
            }
        }
    }
}
