#include "gtest/gtest.h"
#include "base.h"
#include "cars.h"
#include "parts.h"
#include "enums.h"

TEST(Base, Constructor) {
    CBase streetBase(ECarType::STREET);
    EXPECT_EQ(streetBase.carType, ECarType::STREET);
    EXPECT_EQ(streetBase.getMaxSpeed(), 0);
    EXPECT_EQ(streetBase.getAcceleration(), 0);
    EXPECT_EQ(streetBase.getDeceleration(), 0);
    EXPECT_EQ(streetBase.getLives(), 0);
    EXPECT_EQ(streetBase.getArmor(), 0);
    EXPECT_EQ(streetBase.getWeight(), 0);
    EXPECT_EQ(streetBase.getAmmo(), 0);
    EXPECT_EQ(streetBase.getDamage(), 0);


    CBase raceBase(ECarType::RACE);
    EXPECT_EQ(raceBase.carType, ECarType::RACE);
    EXPECT_EQ(raceBase.getMaxSpeed(), 0);
    EXPECT_EQ(raceBase.getAcceleration(), 0);
    EXPECT_EQ(raceBase.getDeceleration(), 0);
    EXPECT_EQ(raceBase.getLives(), 0);
    EXPECT_EQ(raceBase.getArmor(), 0);
    EXPECT_EQ(raceBase.getWeight(), 0);
    EXPECT_EQ(raceBase.getAmmo(), 0);
    EXPECT_EQ(raceBase.getDamage(), 0);


    CBase superBase(ECarType::SUPER);
    EXPECT_EQ(superBase.carType, ECarType::SUPER);
    EXPECT_EQ(superBase.getMaxSpeed(), 0);
    EXPECT_EQ(superBase.getAcceleration(), 0);
    EXPECT_EQ(superBase.getDeceleration(), 0);
    EXPECT_EQ(superBase.getLives(), 0);
    EXPECT_EQ(superBase.getArmor(), 0);
    EXPECT_EQ(superBase.getWeight(), 0);
    EXPECT_EQ(superBase.getAmmo(), 0);
    EXPECT_EQ(superBase.getDamage(), 0);
}

TEST(Base, Initialize) {
    CBase base(ECarType::STREET);
    base.initialize<typename EStreetCars::PEPPER>();
    EXPECT_EQ(base.getMaxSpeed(), (int) EStreetCars::PEPPER::MAX_SPEED);
    EXPECT_EQ(base.getAcceleration(), (int) EStreetCars::PEPPER::ACCELERATION);
    EXPECT_EQ(base.getDeceleration(), (int) EStreetCars::PEPPER::DECELERATION);
    EXPECT_EQ(base.getLives(), (int) EStreetCars::PEPPER::LIVES);
    EXPECT_EQ(base.getArmor(), (int) EStreetCars::PEPPER::ARMOR);
    EXPECT_EQ(base.getWeight(), (int) EStreetCars::PEPPER::WEIGHT);
    EXPECT_EQ(base.getAmmo(), (int) EStreetCars::PEPPER::AMMO);
    EXPECT_EQ(base.getDamage(), (int) EStreetCars::PEPPER::DAMAGE);
}

TEST(Base, Summarize) {
    CBase base(ECarType::RACE);
    base.initialize<ERaceParts::ENGINE>();
    int res = base.summarize<ERacePartCost>();
    int need = (int) ERaceParts::ENGINE::MAX_SPEED * (int) ERacePartCost::MAX_SPEED +
               (int) ERaceParts::ENGINE::ACCELERATION * (int) ERacePartCost::ACCELERATION +
               (int) ERaceParts::ENGINE::DECELERATION * (int) ERacePartCost::DECELERATION +
               (int) ERaceParts::ENGINE::LIVES * (int) ERacePartCost::LIVES +
               (int) ERaceParts::ENGINE::ARMOR * (int) ERacePartCost::ARMOR +
               (int) ERaceParts::ENGINE::WEIGHT * (int) ERacePartCost::WEIGHT +
               (int) ERaceParts::ENGINE::AMMO * (int) ERacePartCost::AMMO +
               (int) ERaceParts::ENGINE::DAMAGE * (int) ERacePartCost::DAMAGE;
    EXPECT_EQ(res, need);
}

TEST(Base, ModeifyAll) {
    CBase base(ECarType::SUPER);
    base.initialize<ESuperParts::ENGINE>();
    base.modifyAll(STREET_PART_ON_SUPER);
    EXPECT_EQ(base.getMaxSpeed(), int((int) ESuperParts::ENGINE::MAX_SPEED * STREET_PART_ON_SUPER));
    EXPECT_EQ(base.getAcceleration(), int((int) ESuperParts::ENGINE::ACCELERATION * STREET_PART_ON_SUPER));
    EXPECT_EQ(base.getDeceleration(), int((int) ESuperParts::ENGINE::DECELERATION * STREET_PART_ON_SUPER));
    EXPECT_EQ(base.getLives(), int((int) ESuperParts::ENGINE::LIVES * STREET_PART_ON_SUPER));
    EXPECT_EQ(base.getArmor(), int((int) ESuperParts::ENGINE::ARMOR * STREET_PART_ON_SUPER));
    EXPECT_EQ(base.getWeight(), int((int) ESuperParts::ENGINE::WEIGHT * STREET_PART_ON_SUPER));
    EXPECT_EQ(base.getAmmo(), int((int) ESuperParts::ENGINE::AMMO * STREET_PART_ON_SUPER));
    EXPECT_EQ(base.getDamage(), int((int) ESuperParts::ENGINE::DAMAGE * STREET_PART_ON_SUPER));
}

TEST(StreetPart, Constructor) {
    CStreetPart part(EPartType::ENGINE);
    EXPECT_EQ(part.carType, ECarType::STREET);
    EXPECT_EQ(part.partType, EPartType::ENGINE);
}

TEST(RacePart, Constructor) {
    CRacePart part(EPartType::SHIELD);
    EXPECT_EQ(part.carType, ECarType::RACE);
    EXPECT_EQ(part.partType, EPartType::SHIELD);
}

TEST(SuperPart, Constructor) {
    CSuperPart part(EPartType::GUN);
    EXPECT_EQ(part.carType, ECarType::SUPER);
    EXPECT_EQ(part.partType, EPartType::GUN);
}

TEST(StreetPartsFactory, Create) {
    CStreetPartsFactory stpf;

    auto part = stpf.create(EPartType::ENGINE);
    EXPECT_EQ(part->partType, EPartType::ENGINE);
    EXPECT_EQ(part->getMaxSpeed(), (int) EStreetParts::ENGINE::MAX_SPEED);
    EXPECT_EQ(part->getAcceleration(), (int) EStreetParts::ENGINE::ACCELERATION);
    EXPECT_EQ(part->getDeceleration(), (int) EStreetParts::ENGINE::DECELERATION);
    EXPECT_EQ(part->getLives(), (int) EStreetParts::ENGINE::LIVES);
    EXPECT_EQ(part->getArmor(), (int) EStreetParts::ENGINE::ARMOR);
    EXPECT_EQ(part->getWeight(), (int) EStreetParts::ENGINE::WEIGHT);
    EXPECT_EQ(part->getAmmo(), (int) EStreetParts::ENGINE::AMMO);
    EXPECT_EQ(part->getDamage(), (int) EStreetParts::ENGINE::DAMAGE);

    auto part2 = stpf.create(EPartType::SHIELD);
    EXPECT_EQ(part2->partType, EPartType::SHIELD);
    EXPECT_EQ(part2->getMaxSpeed(), (int) EStreetParts::SHIELD::MAX_SPEED);
    EXPECT_EQ(part2->getAcceleration(), (int) EStreetParts::SHIELD::ACCELERATION);
    EXPECT_EQ(part2->getDeceleration(), (int) EStreetParts::SHIELD::DECELERATION);
    EXPECT_EQ(part2->getLives(), (int) EStreetParts::SHIELD::LIVES);
    EXPECT_EQ(part2->getArmor(), (int) EStreetParts::SHIELD::ARMOR);
    EXPECT_EQ(part2->getWeight(), (int) EStreetParts::SHIELD::WEIGHT);
    EXPECT_EQ(part2->getAmmo(), (int) EStreetParts::SHIELD::AMMO);
    EXPECT_EQ(part2->getDamage(), (int) EStreetParts::SHIELD::DAMAGE);
}

TEST(RacePartsFactory, Create) {
    CRacePartsFactory rcpf;

    auto part = rcpf.create(EPartType::ENGINE);
    EXPECT_EQ(part->getMaxSpeed(), (int) ERaceParts::ENGINE::MAX_SPEED);
    EXPECT_EQ(part->getAcceleration(), (int) ERaceParts::ENGINE::ACCELERATION);
    EXPECT_EQ(part->getDeceleration(), (int) ERaceParts::ENGINE::DECELERATION);
    EXPECT_EQ(part->getLives(), (int) ERaceParts::ENGINE::LIVES);
    EXPECT_EQ(part->getArmor(), (int) ERaceParts::ENGINE::ARMOR);
    EXPECT_EQ(part->getWeight(), (int) ERaceParts::ENGINE::WEIGHT);
    EXPECT_EQ(part->getAmmo(), (int) ERaceParts::ENGINE::AMMO);
    EXPECT_EQ(part->getDamage(), (int) ERaceParts::ENGINE::DAMAGE);

    auto part2 = rcpf.create(EPartType::TRANSMISSION);
    EXPECT_EQ(part2->getMaxSpeed(), (int) ERaceParts::TRANSMISSION::MAX_SPEED);
    EXPECT_EQ(part2->getAcceleration(), (int) ERaceParts::TRANSMISSION::ACCELERATION);
    EXPECT_EQ(part2->getDeceleration(), (int) ERaceParts::TRANSMISSION::DECELERATION);
    EXPECT_EQ(part2->getLives(), (int) ERaceParts::TRANSMISSION::LIVES);
    EXPECT_EQ(part2->getArmor(), (int) ERaceParts::TRANSMISSION::ARMOR);
    EXPECT_EQ(part2->getWeight(), (int) ERaceParts::TRANSMISSION::WEIGHT);
    EXPECT_EQ(part2->getAmmo(), (int) ERaceParts::TRANSMISSION::AMMO);
    EXPECT_EQ(part2->getDamage(), (int) ERaceParts::TRANSMISSION::DAMAGE);
}

TEST(SuperPartsFactory, Create) {
    CSuperPartsFactory sppf;

    auto part = sppf.create(EPartType::ENGINE);
    EXPECT_EQ(part->getMaxSpeed(), (int) ESuperParts::ENGINE::MAX_SPEED);
    EXPECT_EQ(part->getAcceleration(), (int) ESuperParts::ENGINE::ACCELERATION);
    EXPECT_EQ(part->getDeceleration(), (int) ESuperParts::ENGINE::DECELERATION);
    EXPECT_EQ(part->getLives(), (int) ESuperParts::ENGINE::LIVES);
    EXPECT_EQ(part->getArmor(), (int) ESuperParts::ENGINE::ARMOR);
    EXPECT_EQ(part->getWeight(), (int) ESuperParts::ENGINE::WEIGHT);
    EXPECT_EQ(part->getAmmo(), (int) ESuperParts::ENGINE::AMMO);
    EXPECT_EQ(part->getDamage(), (int) ESuperParts::ENGINE::DAMAGE);

    auto part2 = sppf.create(EPartType::BRAKES);
    EXPECT_EQ(part2->getMaxSpeed(), (int) ESuperParts::BRAKES::MAX_SPEED);
    EXPECT_EQ(part2->getAcceleration(), (int) ESuperParts::BRAKES::ACCELERATION);
    EXPECT_EQ(part2->getDeceleration(), (int) ESuperParts::BRAKES::DECELERATION);
    EXPECT_EQ(part2->getLives(), (int) ESuperParts::BRAKES::LIVES);
    EXPECT_EQ(part2->getArmor(), (int) ESuperParts::BRAKES::ARMOR);
    EXPECT_EQ(part2->getWeight(), (int) ESuperParts::BRAKES::WEIGHT);
    EXPECT_EQ(part2->getAmmo(), (int) ESuperParts::BRAKES::AMMO);
    EXPECT_EQ(part2->getDamage(), (int) ESuperParts::BRAKES::DAMAGE);
}

TEST(StreetPart, GetCost) {
    CStreetPartsFactory b;
    auto part = b.create(EPartType::ENGINE);
    int cost = (int) EStreetParts::ENGINE::MAX_SPEED * (int) EStreetPartCost::MAX_SPEED +
               (int) EStreetParts::ENGINE::ACCELERATION * (int) EStreetPartCost::ACCELERATION +
               (int) EStreetParts::ENGINE::DECELERATION * (int) EStreetPartCost::DECELERATION +
               (int) EStreetParts::ENGINE::LIVES * (int) EStreetPartCost::LIVES +
               (int) EStreetParts::ENGINE::ARMOR * (int) EStreetPartCost::ARMOR +
               (int) EStreetParts::ENGINE::WEIGHT * (int) EStreetPartCost::WEIGHT +
               (int) EStreetParts::ENGINE::AMMO * (int) EStreetPartCost::AMMO +
               (int) EStreetParts::ENGINE::DAMAGE * (int) EStreetPartCost::DAMAGE;
    EXPECT_EQ(part->getCost(), cost);

    auto part2 = b.create(EPartType::WHEELS);
    int cost2 = (int) EStreetParts::WHEELS::MAX_SPEED * (int) EStreetPartCost::MAX_SPEED +
                (int) EStreetParts::WHEELS::ACCELERATION * (int) EStreetPartCost::ACCELERATION +
                (int) EStreetParts::WHEELS::DECELERATION * (int) EStreetPartCost::DECELERATION +
                (int) EStreetParts::WHEELS::LIVES * (int) EStreetPartCost::LIVES +
                (int) EStreetParts::WHEELS::ARMOR * (int) EStreetPartCost::ARMOR +
                (int) EStreetParts::WHEELS::WEIGHT * (int) EStreetPartCost::WEIGHT +
                (int) EStreetParts::WHEELS::AMMO * (int) EStreetPartCost::AMMO +
                (int) EStreetParts::WHEELS::DAMAGE * (int) EStreetPartCost::DAMAGE;
    EXPECT_EQ(part2->getCost(), cost2);
}

TEST(RacePart, GetCost) {
    CRacePartsFactory b;
    auto part = b.create(EPartType::ENGINE);
    int cost = (int) ERaceParts::ENGINE::MAX_SPEED * (int) ERacePartCost::MAX_SPEED +
               (int) ERaceParts::ENGINE::ACCELERATION * (int) ERacePartCost::ACCELERATION +
               (int) ERaceParts::ENGINE::DECELERATION * (int) ERacePartCost::DECELERATION +
               (int) ERaceParts::ENGINE::LIVES * (int) ERacePartCost::LIVES +
               (int) ERaceParts::ENGINE::ARMOR * (int) ERacePartCost::ARMOR +
               (int) ERaceParts::ENGINE::WEIGHT * (int) ERacePartCost::WEIGHT +
               (int) ERaceParts::ENGINE::AMMO * (int) ERacePartCost::AMMO +
               (int) ERaceParts::ENGINE::DAMAGE * (int) ERacePartCost::DAMAGE;
    EXPECT_EQ(part->getCost(), cost);

    auto part2 = b.create(EPartType::AMMO);
    int cost2 = (int) ERaceParts::AMMO::MAX_SPEED * (int) ERacePartCost::MAX_SPEED +
                (int) ERaceParts::AMMO::ACCELERATION * (int) ERacePartCost::ACCELERATION +
                (int) ERaceParts::AMMO::DECELERATION * (int) ERacePartCost::DECELERATION +
                (int) ERaceParts::AMMO::LIVES * (int) ERacePartCost::LIVES +
                (int) ERaceParts::AMMO::ARMOR * (int) ERacePartCost::ARMOR +
                (int) ERaceParts::AMMO::WEIGHT * (int) ERacePartCost::WEIGHT +
                (int) ERaceParts::AMMO::AMMO * (int) ERacePartCost::AMMO +
                (int) ERaceParts::AMMO::DAMAGE * (int) ERacePartCost::DAMAGE;
    EXPECT_EQ(part2->getCost(), cost2);
}

TEST(SuperPart, GetCost) {
    CSuperPartsFactory b;
    auto part = b.create(EPartType::ENGINE);
    int cost = (int) ESuperParts::ENGINE::MAX_SPEED * (int) ESuperPartCost::MAX_SPEED +
               (int) ESuperParts::ENGINE::ACCELERATION * (int) ESuperPartCost::ACCELERATION +
               (int) ESuperParts::ENGINE::DECELERATION * (int) ESuperPartCost::DECELERATION +
               (int) ESuperParts::ENGINE::LIVES * (int) ESuperPartCost::LIVES +
               (int) ESuperParts::ENGINE::ARMOR * (int) ESuperPartCost::ARMOR +
               (int) ESuperParts::ENGINE::WEIGHT * (int) ESuperPartCost::WEIGHT +
               (int) ESuperParts::ENGINE::AMMO * (int) ESuperPartCost::AMMO +
               (int) ESuperParts::ENGINE::DAMAGE * (int) ESuperPartCost::DAMAGE;
    EXPECT_EQ(part->getCost(), cost);

    auto part2 = b.create(EPartType::GUN);
    int cost2 = (int) ESuperParts::GUN::MAX_SPEED * (int) ESuperPartCost::MAX_SPEED +
                (int) ESuperParts::GUN::ACCELERATION * (int) ESuperPartCost::ACCELERATION +
                (int) ESuperParts::GUN::DECELERATION * (int) ESuperPartCost::DECELERATION +
                (int) ESuperParts::GUN::LIVES * (int) ESuperPartCost::LIVES +
                (int) ESuperParts::GUN::ARMOR * (int) ESuperPartCost::ARMOR +
                (int) ESuperParts::GUN::WEIGHT * (int) ESuperPartCost::WEIGHT +
                (int) ESuperParts::GUN::AMMO * (int) ESuperPartCost::AMMO +
                (int) ESuperParts::GUN::DAMAGE * (int) ESuperPartCost::DAMAGE;
    EXPECT_EQ(part2->getCost(), cost2);
}

TEST(StreetCar, Constructor) {
    CStreetCar car;
    EXPECT_EQ(car.carType, ECarType::STREET);
}

TEST(RaceCar, Constructor) {
    CRaceCar car;
    EXPECT_EQ(car.carType, ECarType::RACE);
}

TEST(SuperCar, Constructor) {
    CSuperCar car;
    EXPECT_EQ(car.carType, ECarType::SUPER);
}

TEST(StreetCarBuilder, Create) {
    IStreetCarBuilder b;

    b.create(ECarName::PEPPER);
    auto car = b.getCar();
    EXPECT_EQ(car->carType, ECarType::STREET);
    EXPECT_EQ(car->getMaxSpeed(), (int) EStreetCars::PEPPER::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(), (int) EStreetCars::PEPPER::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(), (int) EStreetCars::PEPPER::DECELERATION);
    EXPECT_EQ(car->getLives(), (int) EStreetCars::PEPPER::LIVES);
    EXPECT_EQ(car->getArmor(), (int) EStreetCars::PEPPER::ARMOR);
    EXPECT_EQ(car->getWeight(), (int) EStreetCars::PEPPER::WEIGHT);
    EXPECT_EQ(car->getAmmo(), (int) EStreetCars::PEPPER::AMMO);
    EXPECT_EQ(car->getDamage(), (int) EStreetCars::PEPPER::DAMAGE);
}

TEST(RaceCarBuilder, Create) {
    IRaceCarBuilder b;

    b.create(ECarName::OVERRUNNER);
    auto car = b.getCar();
    EXPECT_EQ(car->carType, ECarType::RACE);
    EXPECT_EQ(car->getMaxSpeed(), (int) ERaceCars::OVERRUNNER::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(), (int) ERaceCars::OVERRUNNER::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(), (int) ERaceCars::OVERRUNNER::DECELERATION);
    EXPECT_EQ(car->getLives(), (int) ERaceCars::OVERRUNNER::LIVES);
    EXPECT_EQ(car->getArmor(), (int) ERaceCars::OVERRUNNER::ARMOR);
    EXPECT_EQ(car->getWeight(), (int) ERaceCars::OVERRUNNER::WEIGHT);
    EXPECT_EQ(car->getAmmo(), (int) ERaceCars::OVERRUNNER::AMMO);
    EXPECT_EQ(car->getDamage(), (int) ERaceCars::OVERRUNNER::DAMAGE);
}

TEST(SuperCarBuilder, Create) {
    ISuperCarBuilder b;

    b.create(ECarName::THUNDERBOLT);
    auto car = b.getCar();
    EXPECT_EQ(car->carType, ECarType::SUPER);
    EXPECT_EQ(car->getMaxSpeed(), (int) ESuperCars::THUNDERBOLT::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(), (int) ESuperCars::THUNDERBOLT::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(), (int) ESuperCars::THUNDERBOLT::DECELERATION);
    EXPECT_EQ(car->getLives(), (int) ESuperCars::THUNDERBOLT::LIVES);
    EXPECT_EQ(car->getArmor(), (int) ESuperCars::THUNDERBOLT::ARMOR);
    EXPECT_EQ(car->getWeight(), (int) ESuperCars::THUNDERBOLT::WEIGHT);
    EXPECT_EQ(car->getAmmo(), (int) ESuperCars::THUNDERBOLT::AMMO);
    EXPECT_EQ(car->getDamage(), (int) ESuperCars::THUNDERBOLT::DAMAGE);
}

TEST(StreetCar, AddStreetPart) {
    IStreetCarBuilder b;
    b.create(ECarName::PEPPER);
    auto car = b.getCar();
    CStreetPartsFactory f;
    auto part = f.create(EPartType::BODY);
    car->addPart(part);
    EXPECT_EQ(car->getMaxSpeed(), (int) EStreetParts::BODY::MAX_SPEED + (int) EStreetCars::PEPPER::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(), (int) EStreetParts::BODY::ACCELERATION + (int) EStreetCars::PEPPER::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(), (int) EStreetParts::BODY::DECELERATION + (int) EStreetCars::PEPPER::DECELERATION);
    EXPECT_EQ(car->getLives(), (int) EStreetParts::BODY::LIVES + (int) EStreetCars::PEPPER::LIVES);
    EXPECT_EQ(car->getArmor(), (int) EStreetParts::BODY::ARMOR + (int) EStreetCars::PEPPER::ARMOR);
    EXPECT_EQ(car->getWeight(), (int) EStreetParts::BODY::WEIGHT + (int) EStreetCars::PEPPER::WEIGHT);
    EXPECT_EQ(car->getAmmo(), (int) EStreetParts::BODY::AMMO + (int) EStreetCars::PEPPER::AMMO);
    EXPECT_EQ(car->getDamage(), (int) EStreetParts::BODY::DAMAGE + (int) EStreetCars::PEPPER::DAMAGE);
}

TEST(StreetCar, AddRacePart) {
    IStreetCarBuilder b;
    b.create(ECarName::PEPPER);
    auto car = b.getCar();
    CRacePartsFactory f;
    auto part = f.create(EPartType::BODY);
    EXPECT_FALSE(car->addPart(part));
}

TEST(StreetCar, AddSuperPart) {
    IStreetCarBuilder b;
    b.create(ECarName::PEPPER);
    auto car = b.getCar();
    CSuperPartsFactory f;
    auto part = f.create(EPartType::BODY);
    EXPECT_FALSE(car->addPart(part));
}

TEST(RaceCar, AddRacePart) {
    IRaceCarBuilder b;
    b.create(ECarName::OVERRUNNER);
    auto car = b.getCar();
    CRacePartsFactory f;
    auto part = f.create(EPartType::AMMO);
    car->addPart(part);
    EXPECT_EQ(car->getMaxSpeed(), (int) ERaceParts::AMMO::MAX_SPEED + (int) ERaceCars::OVERRUNNER::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(), (int) ERaceParts::AMMO::ACCELERATION + (int) ERaceCars::OVERRUNNER::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(), (int) ERaceParts::AMMO::DECELERATION + (int) ERaceCars::OVERRUNNER::DECELERATION);
    EXPECT_EQ(car->getLives(), (int) ERaceParts::AMMO::LIVES + (int) ERaceCars::OVERRUNNER::LIVES);
    EXPECT_EQ(car->getArmor(), (int) ERaceParts::AMMO::ARMOR + (int) ERaceCars::OVERRUNNER::ARMOR);
    EXPECT_EQ(car->getWeight(), (int) ERaceParts::AMMO::WEIGHT + (int) ERaceCars::OVERRUNNER::WEIGHT);
    EXPECT_EQ(car->getAmmo(), (int) ERaceParts::AMMO::AMMO + (int) ERaceCars::OVERRUNNER::AMMO);
    EXPECT_EQ(car->getDamage(), (int) ERaceParts::AMMO::DAMAGE + (int) ERaceCars::OVERRUNNER::DAMAGE);
}

TEST(RaceCar, AddStreetPart) {
    IRaceCarBuilder b;
    b.create(ECarName::OVERRUNNER);
    auto car = b.getCar();
    CStreetPartsFactory f;
    auto part = f.create(EPartType::WHEELS);
    car->addPart(part);
    EXPECT_EQ(car->getMaxSpeed(), int((int) ERaceParts::WHEELS::MAX_SPEED * STREET_PART_ON_RACE) +
                                  (int) ERaceCars::OVERRUNNER::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(), int((int) ERaceParts::WHEELS::ACCELERATION * STREET_PART_ON_RACE) +
                                      (int) ERaceCars::OVERRUNNER::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(), int((int) ERaceParts::WHEELS::DECELERATION * STREET_PART_ON_RACE) +
                                      (int) ERaceCars::OVERRUNNER::DECELERATION);
    EXPECT_EQ(car->getLives(), int((int) ERaceParts::WHEELS::LIVES * STREET_PART_ON_RACE) +
                               (int) ERaceCars::OVERRUNNER::LIVES);
    EXPECT_EQ(car->getArmor(), int((int) ERaceParts::WHEELS::ARMOR * STREET_PART_ON_RACE) +
                               (int) ERaceCars::OVERRUNNER::ARMOR);
    EXPECT_EQ(car->getWeight(), int((int) ERaceParts::WHEELS::WEIGHT * STREET_PART_ON_RACE) +
                                (int) ERaceCars::OVERRUNNER::WEIGHT);
    EXPECT_EQ(car->getAmmo(), int((int) ERaceParts::WHEELS::AMMO * STREET_PART_ON_RACE) +
                              (int) ERaceCars::OVERRUNNER::AMMO);
    EXPECT_EQ(car->getDamage(), int((int) ERaceParts::WHEELS::DAMAGE * STREET_PART_ON_RACE) +
                                (int) ERaceCars::OVERRUNNER::DAMAGE);
}

TEST(RaceCar, AddSuperPart) {
    IRaceCarBuilder b;
    b.create(ECarName::OVERRUNNER);
    auto car = b.getCar();
    CSuperPartsFactory f;
    auto part = f.create(EPartType::BODY);
    EXPECT_FALSE(car->addPart(part));
}

TEST(SuperCar, AddSuperPart) {
    ISuperCarBuilder b;
    b.create(ECarName::THUNDERBOLT);
    auto car = b.getCar();
    CSuperPartsFactory f;
    auto part = f.create(EPartType::AMMO);
    car->addPart(part);
    EXPECT_EQ(car->getMaxSpeed(), (int) ESuperParts::AMMO::MAX_SPEED + (int) ESuperCars::THUNDERBOLT::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(),
              (int) ESuperParts::AMMO::ACCELERATION + (int) ESuperCars::THUNDERBOLT::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(),
              (int) ESuperParts::AMMO::DECELERATION + (int) ESuperCars::THUNDERBOLT::DECELERATION);
    EXPECT_EQ(car->getLives(), (int) ESuperParts::AMMO::LIVES + (int) ESuperCars::THUNDERBOLT::LIVES);
    EXPECT_EQ(car->getArmor(), (int) ESuperParts::AMMO::ARMOR + (int) ESuperCars::THUNDERBOLT::ARMOR);
    EXPECT_EQ(car->getWeight(), (int) ESuperParts::AMMO::WEIGHT + (int) ESuperCars::THUNDERBOLT::WEIGHT);
    EXPECT_EQ(car->getAmmo(), (int) ESuperParts::AMMO::AMMO + (int) ESuperCars::THUNDERBOLT::AMMO);
    EXPECT_EQ(car->getDamage(), (int) ESuperParts::AMMO::DAMAGE + (int) ESuperCars::THUNDERBOLT::DAMAGE);
}

TEST(SuperCar, AddStreetPart) {
    ISuperCarBuilder b;
    b.create(ECarName::THUNDERBOLT);
    auto car = b.getCar();
    CStreetPartsFactory f;
    auto part = f.create(EPartType::WHEELS);
    car->addPart(part);
    EXPECT_EQ(car->getMaxSpeed(), int((int) EStreetParts::WHEELS::MAX_SPEED * STREET_PART_ON_SUPER) +
                                  (int) ESuperCars::THUNDERBOLT::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(), int((int) EStreetParts::WHEELS::ACCELERATION * STREET_PART_ON_SUPER) +
                                      (int) ESuperCars::THUNDERBOLT::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(), int((int) EStreetParts::WHEELS::DECELERATION * STREET_PART_ON_SUPER) +
                                      (int) ESuperCars::THUNDERBOLT::DECELERATION);
    EXPECT_EQ(car->getLives(), int((int) EStreetParts::WHEELS::LIVES * STREET_PART_ON_SUPER) +
                               (int) ESuperCars::THUNDERBOLT::LIVES);
    EXPECT_EQ(car->getArmor(), int((int) EStreetParts::WHEELS::ARMOR * STREET_PART_ON_SUPER) +
                               (int) ESuperCars::THUNDERBOLT::ARMOR);
    EXPECT_EQ(car->getWeight(), int((int) EStreetParts::WHEELS::WEIGHT * STREET_PART_ON_SUPER) +
                                (int) ESuperCars::THUNDERBOLT::WEIGHT);
    EXPECT_EQ(car->getAmmo(), int((int) EStreetParts::WHEELS::AMMO * STREET_PART_ON_SUPER) +
                              (int) ESuperCars::THUNDERBOLT::AMMO);
    EXPECT_EQ(car->getDamage(), int((int) EStreetParts::WHEELS::DAMAGE * STREET_PART_ON_SUPER) +
                                (int) ESuperCars::THUNDERBOLT::DAMAGE);
}

TEST(SuperCar, AddRacePart) {
    ISuperCarBuilder b;
    b.create(ECarName::THUNDERBOLT);
    auto car = b.getCar();
    CRacePartsFactory f;
    auto part = f.create(EPartType::WHEELS);
    car->addPart(part);
    EXPECT_EQ(car->getMaxSpeed(), int((int) ERaceParts::WHEELS::MAX_SPEED * RACE_PART_ON_SUPER) +
                                  (int) ESuperCars::THUNDERBOLT::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(), int((int) ERaceParts::WHEELS::ACCELERATION * RACE_PART_ON_SUPER) +
                                      (int) ESuperCars::THUNDERBOLT::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(), int((int) ERaceParts::WHEELS::DECELERATION * RACE_PART_ON_SUPER) +
                                      (int) ESuperCars::THUNDERBOLT::DECELERATION);
    EXPECT_EQ(car->getLives(), int((int) ERaceParts::WHEELS::LIVES * RACE_PART_ON_SUPER) +
                               (int) ESuperCars::THUNDERBOLT::LIVES);
    EXPECT_EQ(car->getArmor(), int((int) ERaceParts::WHEELS::ARMOR * RACE_PART_ON_SUPER) +
                               (int) ESuperCars::THUNDERBOLT::ARMOR);
    EXPECT_EQ(car->getWeight(), int((int) ERaceParts::WHEELS::WEIGHT * RACE_PART_ON_SUPER) +
                                (int) ESuperCars::THUNDERBOLT::WEIGHT);
    EXPECT_EQ(car->getAmmo(), int((int) ERaceParts::WHEELS::AMMO * RACE_PART_ON_SUPER) +
                              (int) ESuperCars::THUNDERBOLT::AMMO);
    EXPECT_EQ(car->getDamage(), int((int) ERaceParts::WHEELS::DAMAGE * RACE_PART_ON_SUPER) +
                                (int) ESuperCars::THUNDERBOLT::DAMAGE);
}

TEST(StreetCar, DelStreetPart) {
    IStreetCarBuilder b;
    b.create(ECarName::PEPPER);
    auto car = b.getCar();
    CStreetPartsFactory f;
    auto part = f.create(EPartType::BODY);
    car->addPart(part);
    car->delPart(part);
    EXPECT_EQ(car->getMaxSpeed(), (int) EStreetCars::PEPPER::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(), (int) EStreetCars::PEPPER::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(), (int) EStreetCars::PEPPER::DECELERATION);
    EXPECT_EQ(car->getLives(), (int) EStreetCars::PEPPER::LIVES);
    EXPECT_EQ(car->getArmor(), (int) EStreetCars::PEPPER::ARMOR);
    EXPECT_EQ(car->getWeight(), (int) EStreetCars::PEPPER::WEIGHT);
    EXPECT_EQ(car->getAmmo(), (int) EStreetCars::PEPPER::AMMO);
    EXPECT_EQ(car->getDamage(), (int) EStreetCars::PEPPER::DAMAGE);
}

TEST(RaceCar, DelRacePart) {
    IRaceCarBuilder b;
    b.create(ECarName::OVERRUNNER);
    auto car = b.getCar();
    CRacePartsFactory f;
    auto part = f.create(EPartType::AMMO);
    car->addPart(part);
    car->delPart(part);
    EXPECT_EQ(car->carType, ECarType::RACE);
    EXPECT_EQ(car->getMaxSpeed(), (int) ERaceCars::OVERRUNNER::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(), (int) ERaceCars::OVERRUNNER::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(), (int) ERaceCars::OVERRUNNER::DECELERATION);
    EXPECT_EQ(car->getLives(), (int) ERaceCars::OVERRUNNER::LIVES);
    EXPECT_EQ(car->getArmor(), (int) ERaceCars::OVERRUNNER::ARMOR);
    EXPECT_EQ(car->getWeight(), (int) ERaceCars::OVERRUNNER::WEIGHT);
    EXPECT_EQ(car->getAmmo(), (int) ERaceCars::OVERRUNNER::AMMO);
    EXPECT_EQ(car->getDamage(), (int) ERaceCars::OVERRUNNER::DAMAGE);
}

TEST(RaceCar, DelStreetPart) {
    IRaceCarBuilder b;
    b.create(ECarName::OVERRUNNER);
    auto car = b.getCar();
    CStreetPartsFactory f;
    auto part = f.create(EPartType::AMMO);
    car->addPart(part);
    car->delPart(part);
    EXPECT_EQ(car->carType, ECarType::RACE);
    EXPECT_EQ(car->getMaxSpeed(), (int) ERaceCars::OVERRUNNER::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(), (int) ERaceCars::OVERRUNNER::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(), (int) ERaceCars::OVERRUNNER::DECELERATION);
    EXPECT_EQ(car->getLives(), (int) ERaceCars::OVERRUNNER::LIVES);
    EXPECT_EQ(car->getArmor(), (int) ERaceCars::OVERRUNNER::ARMOR);
    EXPECT_EQ(car->getWeight(), (int) ERaceCars::OVERRUNNER::WEIGHT);
    EXPECT_EQ(car->getAmmo(), (int) ERaceCars::OVERRUNNER::AMMO);
    EXPECT_EQ(car->getDamage(), (int) ERaceCars::OVERRUNNER::DAMAGE);
}

TEST(SuperCar, DelSuperPart) {
    ISuperCarBuilder b;
    b.create(ECarName::THUNDERBOLT);
    auto car = b.getCar();
    CSuperPartsFactory f;
    auto part = f.create(EPartType::AMMO);
    car->addPart(part);
    car->delPart(part);
    EXPECT_EQ(car->carType, ECarType::SUPER);
    EXPECT_EQ(car->getMaxSpeed(), (int) ESuperCars::THUNDERBOLT::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(), (int) ESuperCars::THUNDERBOLT::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(), (int) ESuperCars::THUNDERBOLT::DECELERATION);
    EXPECT_EQ(car->getLives(), (int) ESuperCars::THUNDERBOLT::LIVES);
    EXPECT_EQ(car->getArmor(), (int) ESuperCars::THUNDERBOLT::ARMOR);
    EXPECT_EQ(car->getWeight(), (int) ESuperCars::THUNDERBOLT::WEIGHT);
    EXPECT_EQ(car->getAmmo(), (int) ESuperCars::THUNDERBOLT::AMMO);
    EXPECT_EQ(car->getDamage(), (int) ESuperCars::THUNDERBOLT::DAMAGE);
}

TEST(SuperCar, DelRacePart) {
    ISuperCarBuilder b;
    b.create(ECarName::THUNDERBOLT);
    auto car = b.getCar();
    CRacePartsFactory f;
    auto part = f.create(EPartType::AMMO);
    car->addPart(part);
    car->delPart(part);
    EXPECT_EQ(car->carType, ECarType::SUPER);
    EXPECT_EQ(car->getMaxSpeed(), (int) ESuperCars::THUNDERBOLT::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(), (int) ESuperCars::THUNDERBOLT::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(), (int) ESuperCars::THUNDERBOLT::DECELERATION);
    EXPECT_EQ(car->getLives(), (int) ESuperCars::THUNDERBOLT::LIVES);
    EXPECT_EQ(car->getArmor(), (int) ESuperCars::THUNDERBOLT::ARMOR);
    EXPECT_EQ(car->getWeight(), (int) ESuperCars::THUNDERBOLT::WEIGHT);
    EXPECT_EQ(car->getAmmo(), (int) ESuperCars::THUNDERBOLT::AMMO);
    EXPECT_EQ(car->getDamage(), (int) ESuperCars::THUNDERBOLT::DAMAGE);
}

TEST(SuperCar, DelStreetPart) {
    ISuperCarBuilder b;
    b.create(ECarName::THUNDERBOLT);
    auto car = b.getCar();
    CStreetPartsFactory f;
    auto part = f.create(EPartType::AMMO);
    car->addPart(part);
    car->delPart(part);
    EXPECT_EQ(car->carType, ECarType::SUPER);
    EXPECT_EQ(car->getMaxSpeed(), (int) ESuperCars::THUNDERBOLT::MAX_SPEED);
    EXPECT_EQ(car->getAcceleration(), (int) ESuperCars::THUNDERBOLT::ACCELERATION);
    EXPECT_EQ(car->getDeceleration(), (int) ESuperCars::THUNDERBOLT::DECELERATION);
    EXPECT_EQ(car->getLives(), (int) ESuperCars::THUNDERBOLT::LIVES);
    EXPECT_EQ(car->getArmor(), (int) ESuperCars::THUNDERBOLT::ARMOR);
    EXPECT_EQ(car->getWeight(), (int) ESuperCars::THUNDERBOLT::WEIGHT);
    EXPECT_EQ(car->getAmmo(), (int) ESuperCars::THUNDERBOLT::AMMO);
    EXPECT_EQ(car->getDamage(), (int) ESuperCars::THUNDERBOLT::DAMAGE);
}

TEST(CarBuilder, AddGoodPart) {
    ISuperCarBuilder b;
    b.create(ECarName::THUNDERBOLT);
    CSuperPartsFactory pf;
    CRacePartsFactory rpf;
    auto body = pf.create(EPartType::BODY);
    auto trans = pf.create(EPartType::TRANSMISSION);
    EXPECT_FALSE(b.addPart(body));
    EXPECT_FALSE(b.addPart(trans));
    auto nbody = rpf.create(EPartType::BODY);
    EXPECT_EQ(b.addPart(nbody), body);
}

TEST(CarBuilder, AddBadPart) {
    IStreetCarBuilder b;
    b.create(ECarName::PEPPER);
    CStreetPartsFactory pf;
    CRacePartsFactory rpf;
    auto body = pf.create(EPartType::BODY);
    auto trans = pf.create(EPartType::TRANSMISSION);
    EXPECT_FALSE(b.addPart(body));
    EXPECT_FALSE(b.addPart(trans));
    auto nbody = rpf.create(EPartType::BODY);
    EXPECT_EQ(b.addPart(nbody), nbody);
}

TEST(CarBuilder, DelPart) {
    IStreetCarBuilder b;
    b.create(ECarName::PEPPER);
    CStreetPartsFactory pf;
    auto body = pf.create(EPartType::BODY);
    EXPECT_FALSE(b.addPart(body));
    EXPECT_EQ(b.delPart(EPartType::BODY), body);
    EXPECT_FALSE(b.delPart(EPartType::GUN));
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}