//
// Created by Марк Наговицин on 2019-04-16.
//

#ifndef CARS_GROUND_H
#define CARS_GROUND_H

#include <memory>

class CBaseGround {
protected:
    double slow;
    double slippy;
    int damage;
    double damage_interval;

    std::shared_ptr<CBaseGround> wrap;

public:
    CBaseGround() :
            slow(1), slippy(1), damage(0),
            damage_interval(1) {}

    double getSlow() const;
    double getSlippy() const;
    int getDamage() const;
    double getDamageInterval() const;

    void setSlow(double slow);
    void setSlippy(double slippy);
    void setDamage(int damage);
    void setDamageInterval(double damageInterval);

    bool wrapGround(const std::shared_ptr<CBaseGround>& w) {
        if (!w) {
            return false;
        }
        wrap = w;
        return true;
    }
};

class CSlowGround: CBaseGround {
public:
    explicit CSlowGround(double slow) {
        setSlow(slow);
    }
};

class CSlippyGround: CBaseGround {
public:
    explicit CSlippyGround(double slippy) {
        setSlippy(slippy);
    }
};

class CDamageGround: CBaseGround {
public:
    explicit CDamageGround(int damage, double interval) {
        setDamage(damage);
        setDamageInterval(interval);
    }
};

#endif //CARS_GROUND_H
