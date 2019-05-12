#ifndef CARS_CARS_H
#define CARS_CARS_H

#pragma once

#include <memory>
#include <map>
#include "enums.h"
#include "base.h"
#include "parts.h"

class CCar : public CBase {
public:
    virtual bool addPart(std::shared_ptr<CPart> &part) = 0;

    virtual void delPart(std::shared_ptr<CPart> &part) = 0;

    explicit CCar(ECarType carType) :
            CBase(carType) {}

    virtual ~CCar() = default;
};

class CStreetCar : public CCar {
public:
    bool addPart(std::shared_ptr<CPart> &part) override;

    void delPart(std::shared_ptr<CPart> &part) override;

    CStreetCar() : CCar(ECarType::STREET) {}
};

class CRaceCar : public CCar {
public:
    bool addPart(std::shared_ptr<CPart> &part) override;

    void delPart(std::shared_ptr<CPart> &part) override;

    CRaceCar() : CCar(ECarType::RACE) {}
};

class CSuperCar : public CCar {
public:
    bool addPart(std::shared_ptr<CPart> &part) override;

    void delPart(std::shared_ptr<CPart> &part) override;

    CSuperCar() : CCar(ECarType::SUPER) {}
};

class ICarBuilder {
protected:
    std::shared_ptr<CCar> car;
    std::map<EPartType, std::shared_ptr<CPart>> parts;
public:
    virtual void create(ECarName name) = 0;

    std::shared_ptr<CPart> addPart(std::shared_ptr<CPart> part);

    std::shared_ptr<CPart> delPart(EPartType partType);

    std::shared_ptr<CCar> getCar();

    virtual ~ICarBuilder() = default;
};

class IStreetCarBuilder : public ICarBuilder {
public:
    void create(ECarName name) override;

    ~IStreetCarBuilder() override = default;
};

class IRaceCarBuilder : public ICarBuilder {
public:
    void create(ECarName name) override;

    ~IRaceCarBuilder() override = default;
};

class ISuperCarBuilder : public ICarBuilder {
public:
    void create(ECarName name) override;

    ~ISuperCarBuilder() override = default;
};

#endif //CARS_CARS_H
