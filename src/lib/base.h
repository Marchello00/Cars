#ifndef CARS_BASE_H
#define CARS_BASE_H

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

    template<class T>
    int summarize() const;

public:
    template<class T>
    void initialize();

    const ECarType carType;
    explicit CBase(ECarType carType) :
            carType(carType), maxSpeed(0),
            acceleration(0), deceleration(0), weight(0),
            lives(0), armor(0), ammo(0), damage(0) {}

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

    int getMaxSpeed() const;

    int getAcceleration() const;

    int getDeceleration() const;

    int getWeight() const;

    int getLives() const;

    int getArmor() const;

    int getAmmo() const;

    int getDamage() const;

    void modifyAll(double c);

protected:

    void addBase(std::shared_ptr<CBase> b);

    void delBase(std::shared_ptr<CBase> b);

};

#endif //CARS_BASE_H
