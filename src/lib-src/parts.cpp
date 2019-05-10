#ifndef PARTS_ADDED
#define PARTS_ADDED

#include "../lib/parts.h"

int CStreetPart::getCost() const {
    return summarize<EStreetPartCost>();
}

int CRacePart::getCost() const {
    return summarize<ERacePartCost>();
}

int CSuperPart::getCost() const {
    return summarize<ESuperPartCost>();
}

std::shared_ptr<CPart> correctTypeChoiser(ECarType carType, EPartType partType) {
    switch (carType) {
        case ECarType::STREET: {
            return std::make_shared<CStreetPart>(partType);
        }
        case ECarType::RACE: {
            return std::make_shared<CRacePart>(partType);
        }
        case ECarType::SUPER: {
            return std::make_shared<CSuperPart>(partType);
        }
    }
}

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

std::shared_ptr<CPart> CStreetPartsFactory::create(EPartType partType) const {
    return choice_create<EStreetParts>(partType);
}

std::shared_ptr<CPart> CRacePartsFactory::create(EPartType partType) const {
    return choice_create<ERaceParts>(partType);
}

std::shared_ptr<CPart> CSuperPartsFactory::create(EPartType partType) const {
    return choice_create<ESuperParts>(partType);
}

#endif // PARTS_ADDED