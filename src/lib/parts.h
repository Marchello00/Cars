#ifndef CARS_PARTS_H
#define CARS_PARTS_H

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

#define PARTS_ADDED
#include "parts.cpp"

#endif //CARS_PARTS_H
