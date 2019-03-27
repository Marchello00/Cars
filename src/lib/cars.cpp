#include "cars.h"

void ICarBuilder::create(int carType) {
    switch (carType) {
        case ECarType::STREET: {
            car = std::make_shared<CStreetCar>();
            break;
        }
        case ECarType::RACE: {
            car = std::make_shared<CRaceCar>();
            break;
        }
        case ECarType::SUPER: {
            car = std::make_shared<CSuperCar>();
            break;
        }
        default: {
            break;
        }
    }
}

std::shared_ptr<CPart> ICarBuilder::addPart(std::shared_ptr<CPart> part) {
    auto &place = parts[part->partType];
    auto oldPart = delPart(part->partType);
    if (car->addPart(part)) {
        place = part;
    } else {
        if (oldPart) {
            car->addPart(oldPart);
        }
        oldPart = part;
    }
    return oldPart;
}

std::shared_ptr<CPart> ICarBuilder::delPart(const int partType) {
    auto &place = parts[partType];
    if (place) {
        car->delPart(place);
    }
    auto oldPart = place;
    place = nullptr;
    return oldPart;
}

bool CStreetCar::addPart(std::shared_ptr<CPart> &part) {
    if (part->carType > ECarType::STREET)
        return false;
    addBase(part);
    return true;
}

void CStreetCar::delPart(std::shared_ptr<CPart> &part) {
    delBase(part);
}

bool CRaceCar::addPart(std::shared_ptr<CPart> &part) {
    if (part->carType > ECarType::RACE)
        return false;
    if (part->carType == ECarType::STREET) {
        part->modifyAll(STREET_PART_ON_RACE);
    }
    addBase(part);
    return true;
}

void CRaceCar::delPart(std::shared_ptr<CPart> &part) {
    if (part->carType == ECarType::STREET) {
        part->modifyAll(1.0 / STREET_PART_ON_RACE);
    }
    delBase(part);
}

bool CSuperCar::addPart(std::shared_ptr<CPart> &part) {
    if (part->carType == ECarType::STREET) {
        part->modifyAll(STREET_PART_ON_SUPER);
    }
    if (part->carType == ECarType::RACE) {
        part->modifyAll(RACE_PART_ON_SUPER);
    }
    addBase(part);
    return true;
}

void CSuperCar::delPart(std::shared_ptr<CPart> &part) {
    delBase(part);
    if (part->carType == ECarType::STREET) {
        part->modifyAll(1.0 / STREET_PART_ON_SUPER);
    }
    if (part->carType == ECarType::RACE) {
        part->modifyAll(1.0 / RACE_PART_ON_SUPER);
    }
}