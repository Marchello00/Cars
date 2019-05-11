#include "ground.h"

double CBaseGround::getSlow() const {
    return slow;
}

void CBaseGround::setSlow(double n_slow) {
    CBaseGround::slow = n_slow;
}

double CBaseGround::getSlippy() const {
    return slippy;
}

void CBaseGround::setSlippy(double n_slippy) {
    CBaseGround::slippy = n_slippy;
}

int CBaseGround::getDamage() const {
    return damage;
}

void CBaseGround::setDamage(int n_damage) {
    CBaseGround::damage = n_damage;
}

double CBaseGround::getDamageInterval() const {
    return damage_interval;
}

void CBaseGround::setDamageInterval(double n_damageInterval) {
    damage_interval = n_damageInterval;
}
