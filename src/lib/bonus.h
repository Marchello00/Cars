#ifndef CARS_BONUS_H
#define CARS_BONUS_H

#include "base.h"
#include "enums.h"

class CBaseBonus : CBase {
private:
    double liveTm;
    double startTm;
public:
    explicit CBaseBonus(ECarType carType) :
            CBase(carType), liveTm(0), startTm(0) {}
};

class CHealthBonus : CBaseBonus {

};

#endif //CARS_BONUS_H
