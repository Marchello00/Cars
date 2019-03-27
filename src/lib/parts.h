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
};


class CStreetPart: public CPart {
public:
    int getCost() const override;

    explicit CStreetPart(EPartType partType): CPart(ECarType::STREET, partType) { }
};

class CRacePart: public CPart {
public:
    int getCost() const override;

    explicit CRacePart(EPartType partType): CPart(ECarType::RACE, partType) { }
};

class CSuperPart: public CPart {
public:
    int getCost() const override;

    explicit CSuperPart(EPartType partType): CPart(ECarType::SUPER, partType) { }
};

class CPartsFactory {
protected:
    template<typename T>
    std::shared_ptr<CPart> choice_create(EPartType partType) const;

public:
    virtual std::shared_ptr<CPart> create(EPartType partType) const = 0;
};

class CStreetPartsFactory: public CPartsFactory {
public:
    std::shared_ptr<CPart> create(EPartType partType) const override;
};

class CRacePartsFactory: public CPartsFactory {
public:
    std::shared_ptr<CPart> create(EPartType partType) const override;
};

class CSuperPartsFactory: public CPartsFactory {
public:
    std::shared_ptr<CPart> create(EPartType partType) const override;
};

#endif //CARS_PARTS_H
