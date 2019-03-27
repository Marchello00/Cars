#ifndef CARS_CARS_H
#define CARS_CARS_H

#include <memory>
#include <map>
#include "enums.h"
#include "base.h"

class CStreetCar: public CCar {
public:
    bool addPart(std::shared_ptr<CPart> &part) override;
    void delPart(std::shared_ptr<CPart> &part) override;

    CStreetCar(): CCar(ECarType::STREET) { }
};

class CRaceCar: public CCar {
public:
    bool addPart(std::shared_ptr<CPart> &part) override;
    void delPart(std::shared_ptr<CPart> &part) override;

    CRaceCar(): CCar(ECarType::RACE) { }
};

class CSuperCar: public CCar {
public:
    bool addPart(std::shared_ptr<CPart> &part) override;
    void delPart(std::shared_ptr<CPart> &part) override;

    CSuperCar(): CCar(ECarType::SUPER) { }
};

class ICarBuilder {
private:
    std::shared_ptr<CCar> car;
    std::map<int, std::shared_ptr<CPart>> parts;
public:
    void create(int carType);

    std::shared_ptr<CPart> addPart(std::shared_ptr<CPart> part);
    std::shared_ptr<CPart> delPart(int partType);
};

#endif //CARS_CARS_H
