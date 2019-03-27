#include <memory>
#include "base.h"

void CBase::setMaxSpeed(int maxSpeed) {
    CBase::maxSpeed = maxSpeed;
}

void CBase::setAcceleration(int acceleration) {
    CBase::acceleration = acceleration;
}

void CBase::setDeceleration(int deceleration) {
    CBase::deceleration = deceleration;
}

void CBase::setWeight(int weight) {
    CBase::weight = weight;
}

void CBase::setLives(int lives) {
    CBase::lives = lives;
}

void CBase::setArmor(int armor) {
    CBase::armor = armor;
}

void CBase::setAmmo(int ammo) {
    CBase::ammo = ammo;
}

void CBase::setDamage(int damage) {
    CBase::damage = damage;
}

void CBase::addMaxSpeed(int maxSpeed) {
    CBase::maxSpeed += maxSpeed;
}

void CBase::addAcceleration(int acceleration) {
    CBase::acceleration += acceleration;
}

void CBase::addDeceleration(int deceleration) {
    CBase::deceleration += deceleration;
}

void CBase::addWeight(int weight) {
    CBase::weight += weight;
}

void CBase::addLives(int lives) {
    CBase::lives += lives;
}

void CBase::addArmor(int armor) {
    CBase::armor += armor;
}

void CBase::addAmmo(int ammo) {
    CBase::ammo += ammo;
}

void CBase::addDamage(int damage) {
    CBase::damage += damage;
}

int CBase::getMaxSpeed() const {
    return maxSpeed;
}

int CBase::getAcceleration() const {
    return acceleration;
}

int CBase::getDeceleration() const {
    return deceleration;
}

int CBase::getWeight() const {
    return weight;
}

int CBase::getLives() const {
    return lives;
}

int CBase::getArmor() const {
    return armor;
}

int CBase::getAmmo() const {
    return ammo;
}

int CBase::getDamage() const {
    return damage;
}

void CBase::addBase(std::shared_ptr<CBase> b) {
    addMaxSpeed(b->getMaxSpeed());
    addAcceleration(b->getAcceleration());
    addDeceleration(b->getDeceleration());
    addArmor(b->getArmor());
    addLives(b->getLives());
    addAmmo(b->getAmmo());
    addWeight(b->getWeight());
    addDamage(b->getDamage());
}

void CBase::delBase(std::shared_ptr<CBase> b) {
    addMaxSpeed(-b->getMaxSpeed());
    addAcceleration(-b->getAcceleration());
    addDeceleration(-b->getDeceleration());
    addArmor(-b->getArmor());
    addLives(-b->getLives());
    addAmmo(-b->getAmmo());
    addWeight(-b->getWeight());
    addDamage(-b->getDamage());
}

void CBase::modifyAll(double c) {
    setMaxSpeed((int) (getMaxSpeed() * c));
    setAcceleration((int) (getAcceleration() * c));
    setDeceleration((int) (getDeceleration() * c));
    setArmor((int) (getArmor() * c));
    setLives((int) (getLives() * c));
    setAmmo((int) (getLives() * c));
    setWeight((int) (getWeight() * c));
    setDamage((int) (getDamage() * c));
}

template<class T>
int CBase::summarize() const {
    int sum = 0;
    sum += maxSpeed * T::MAX_SPEED;
    sum += acceleration * T::ACCELERATION;
    sum += deceleration * T::DECELERATION;
    sum += weight * T::WEIGHT;
    sum += lives * T::LIVES;
    sum += armor * T::ARMOR;
    sum += ammo * T::AMMO;
    sum += damage * T::DAMAGE;
    return sum;
}

template<class T>
void CBase::initialize() {
    setMaxSpeed(T::MAX_SPEED);
    setAcceleration(T::ACCELERATION);
    setDeceleration(T::DECELERATION);
    setArmor(T::ARMOR);
    setLives(T::LIVES);
    setAmmo(T::AMMO);
    setWeight(T::WEIGHT);
    setDamage(T::DAMAGE);
    return 0;
}
