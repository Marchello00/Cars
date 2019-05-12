#ifndef CARS_PARTS_H
#define CARS_PARTS_H

#pragma once

#include <memory>
#include "enums.h"
#include "base.h"

class CPart : public CBase {
public:
    const EPartType partType;

    virtual int getCost() const = 0;

    CPart(ECarType carType, EPartType partType) :
            CBase(carType), partType(partType) {}

    virtual ~CPart() = default;
};


class CStreetPart : public CPart {
public:
    int getCost() const override;

    explicit CStreetPart(EPartType partType) : CPart(ECarType::STREET, partType) {}

    ~CStreetPart() override = default;
};

class CRacePart : public CPart {
public:
    int getCost() const override;

    explicit CRacePart(EPartType partType) : CPart(ECarType::RACE, partType) {}

    ~CRacePart() override = default;
};

class CSuperPart : public CPart {
public:
    int getCost() const override;

    explicit CSuperPart(EPartType partType) : CPart(ECarType::SUPER, partType) {}

    ~CSuperPart() override = default;
};

class CPartsFactory {
protected:
    template<typename T>
    std::shared_ptr<CPart> choice_create(EPartType partType) const;

public:
    virtual std::shared_ptr<CPart> create(EPartType partType) const = 0;

    virtual ~CPartsFactory() = default;
};

class CStreetPartsFactory : public CPartsFactory {
public:
    std::shared_ptr<CPart> create(EPartType partType) const override;

    ~CStreetPartsFactory() override = default;
};

class CRacePartsFactory : public CPartsFactory {
public:
    std::shared_ptr<CPart> create(EPartType partType) const override;

    ~CRacePartsFactory() override = default;
};

class CSuperPartsFactory : public CPartsFactory {
public:
    std::shared_ptr<CPart> create(EPartType partType) const override;

    ~CSuperPartsFactory() override = default;
};

template<typename T>
std::shared_ptr<CPart> CPartsFactory::choice_create(EPartType partType) const {
    std::shared_ptr<CPart> part = correctTypeChoiser(T::TYPE, partType);
    switch (partType) {
        case EPartType::ENGINE: {
            part->initialize<typename T::ENGINE>();
            break;
        }
        case EPartType::WHEELS: {
            part->initialize<typename T::WHEELS>();
            break;
        }
        case EPartType::BRAKES: {
            part->initialize<typename T::BRAKES>();
            break;
        }
        case EPartType::TRANSMISSION: {
            part->initialize<typename T::TRANSMISSION>();
            break;
        }
        case EPartType::BODY: {
            part->initialize<typename T::BODY>();
            break;
        }
        case EPartType::SHIELD: {
            part->initialize<typename T::SHIELD>();
            break;
        }
        case EPartType::AMMO: {
            part->initialize<typename T::AMMO>();
            break;
        }
        case EPartType::GUN: {
            part->initialize<typename T::GUN>();
            break;
        }
    }
    return part;
}

#endif //CARS_PARTS_H
