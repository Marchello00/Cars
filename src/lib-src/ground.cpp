//
// Created by Марк Наговицин on 2019-04-16.
//

#include "ground.h"

double CBaseGround::getSlow() const {
    return slow;
}

void CBaseGround::setSlow(double slow) {
    CBaseGround::slow = slow;
}

double CBaseGround::getSlippy() const {
    return slippy;
}

void CBaseGround::setSlippy(double slippy) {
    CBaseGround::slippy = slippy;
}

int CBaseGround::getDamage() const {
    return damage;
}

void CBaseGround::setDamage(int damage) {
    CBaseGround::damage = damage;
}

double CBaseGround::getDamageInterval() const {
    return damage_interval;
}

void CBaseGround::setDamageInterval(double damageInterval) {
    damage_interval = damageInterval;
}
