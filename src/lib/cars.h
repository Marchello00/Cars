#ifndef CARS_CARS_H
#define CARS_CARS_H

#include <memory>
#include <map>
#include "enums.h"
#include "base.h"

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
    virtual void create() = 0;

    std::shared_ptr<CPart> addPart(std::shared_ptr<CPart> part);

    std::shared_ptr<CPart> delPart(EPartType partType);
};

class IStreetCarBuilder: public ICarBuilder {
    void create() override;
};

class IRaceCarBuilder: public ICarBuilder {
    void create() override;
};

class ISuperCarBuilder: public ICarBuilder {
    void create() override;
};

#endif //CARS_CARS_H
