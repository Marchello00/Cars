#include "ground.h"

double CBaseGround::getResistance() const {
    double ret = resistance;
    if (wrap) {
        ret *= wrap->getResistance();
    }
    return ret;
}

void CBaseGround::setResistance(double n_resistance) {
    CBaseGround::resistance = n_resistance;
}

int CBaseGround::getDamage() const {
    int ret = damage;
    if (wrap) {
        ret += wrap->getDamage();
    }
    return ret;
}

void CBaseGround::setDamage(int n_damage) {
    CBaseGround::damage = n_damage;
}

double CBaseGround::getDamageInterval() const {
    double ret = damage_interval;
    if (wrap) {
        ret += wrap->getDamageInterval();
    }
    return ret;
}

void CBaseGround::setDamageInterval(double n_damageInterval) {
    damage_interval = n_damageInterval;
}
