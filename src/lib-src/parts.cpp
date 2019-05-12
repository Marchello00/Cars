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



std::shared_ptr<CPart> CStreetPartsFactory::create(EPartType partType) const {
    return choice_create<EStreetParts>(partType);
}

std::shared_ptr<CPart> CRacePartsFactory::create(EPartType partType) const {
    return choice_create<ERaceParts>(partType);
}

std::shared_ptr<CPart> CSuperPartsFactory::create(EPartType partType) const {
    return choice_create<ESuperParts>(partType);
}