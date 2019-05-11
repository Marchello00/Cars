#ifndef CARS_GROUND_H
#define CARS_GROUND_H

#pragma once

#include <memory>

class CBaseGround {
protected:
    double resistance;
    int damage;
    double damage_interval;

    std::shared_ptr<CBaseGround> wrap;

public:
    CBaseGround() :
            resistance(1), damage(0),
            damage_interval(0) {}

    double getResistance() const;
    int getDamage() const;
    double getDamageInterval() const;

    void setResistance(double n_resistance);
    void setDamage(int n_damage);
    void setDamageInterval(double n_damageInterval);

    bool wrapGround(const std::shared_ptr<CBaseGround>& w) {
        if (!w) {
            return false;
        }
        wrap = w;
        return true;
    }
};

class CSlowGround: public CBaseGround {
public:
    explicit CSlowGround(double resistance) {
        setResistance(resistance);
    }
};

class CSlippyGround: public CBaseGround {
public:
    explicit CSlippyGround(double resistance) {
        setResistance(1 / resistance);
    }
};

class CDamageGround: public CBaseGround {
public:
    explicit CDamageGround(int damage, double interval) {
        setDamage(damage);
        setDamageInterval(interval);
    }
};

#endif //CARS_GROUND_H
