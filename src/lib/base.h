#ifndef CARS_BASE_H
#define CARS_BASE_H

#pragma once

#include "enums.h"

class CBase {
protected:
    int maxSpeed;
    int acceleration;
    int deceleration;
    int weight;
    int lives;
    int armor;
    int ammo;
    int damage;

public:
    template<class T>
    int summarize() const;

    template<class T>
    void initialize();

    void modifyAll(double c);

    const ECarType carType;

    explicit CBase(ECarType carType) :
            carType(carType), maxSpeed(0),
            acceleration(0), deceleration(0), weight(0),
            lives(0), armor(0), ammo(0), damage(0) {}

protected:

    void setMaxSpeed(int maxSpeed);

    void setAcceleration(int acceleration);

    void setDeceleration(int deceleration);

    void setWeight(int weight);

    void setLives(int lives);

    void setArmor(int armor);

    void setAmmo(int ammo);

    void setDamage(int damage);

    void addMaxSpeed(int maxSpeed);

    void addAcceleration(int acceleration);

    void addDeceleration(int deceleration);

    void addWeight(int weight);

    void addLives(int lives);

    void addArmor(int armor);

    void addAmmo(int ammo);

    void addDamage(int damage);

public:

    int getMaxSpeed() const;

    int getAcceleration() const;

    int getDeceleration() const;

    int getWeight() const;

    int getLives() const;

    int getArmor() const;

    int getAmmo() const;

    int getDamage() const;

protected:

    void addBase(std::shared_ptr<CBase> b);

    void delBase(std::shared_ptr<CBase> b);

};


template<class T>
int CBase::summarize() const {
    int sum = 0;
    sum += maxSpeed * (int) T::MAX_SPEED;
    sum += acceleration * (int) T::ACCELERATION;
    sum += deceleration * (int) T::DECELERATION;
    sum += weight * (int) T::WEIGHT;
    sum += lives * (int) T::LIVES;
    sum += armor * (int) T::ARMOR;
    sum += ammo * (int) T::AMMO;
    sum += damage * (int) T::DAMAGE;
    return sum;
}

template<class T>
void CBase::initialize() {
    setMaxSpeed((int) T::MAX_SPEED);
    setAcceleration((int) T::ACCELERATION);
    setDeceleration((int) T::DECELERATION);
    setArmor((int) T::ARMOR);
    setLives((int) T::LIVES);
    setAmmo((int) T::AMMO);
    setWeight((int) T::WEIGHT);
    setDamage((int) T::DAMAGE);
}


#endif //CARS_BASE_H
