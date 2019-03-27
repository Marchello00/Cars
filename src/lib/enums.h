#ifndef CARS_ENUMS_H
#define CARS_ENUMS_H

enum class ECarType {
    STREET, RACE, SUPER
};

enum class EPartType: int {
    ENGINE, WHEELS, BRAKES, TRANSMISSION, BODY, SHIELD, AMMO, GUN
};

const double STREET_PART_ON_RACE = 0.6;
const double STREET_PART_ON_SUPER = 0.2;
const double RACE_PART_ON_SUPER = 0.5;

//PartCost

enum class EStreetPartCost: int {
    MAX_SPEED = 50,
    ACCELERATION = 150,
    DECELERATION = 150,
    WEIGHT = 20,
    LIVES = 300,
    ARMOR = 400,
    AMMO = 100,
    DAMAGE = 200
};

enum class ERacePartCost: int {
    MAX_SPEED = 75,
    ACCELERATION = 300,
    DECELERATION = 300,
    WEIGHT = 40,
    LIVES = 600,
    ARMOR = 800,
    AMMO = 75,
    DAMAGE = 400
};

enum class ESuperPartCost: int {
    MAX_SPEED = 150,
    ACCELERATION = 600,
    DECELERATION = 600,
    WEIGHT = 100,
    LIVES = 1000,
    ARMOR = 1000,
    AMMO = 100,
    DAMAGE = 800
};

//PartSettings

class EStreetParts {
public:
    enum class ENGINE {
        MAX_SPEED = 20,
        ACCELERATION = 3,
        DECELERATION = 3,
        WEIGHT = 10,
        LIVES = 1,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class WHEELS {
        MAX_SPEED = 5,
        ACCELERATION = 1,
        DECELERATION = 1,
        WEIGHT = 5,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class BRAKES {
        MAX_SPEED = 0,
        ACCELERATION = 0,
        DECELERATION = 5,
        WEIGHT = 0,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class TRANSMISSION {
        MAX_SPEED = 5,
        ACCELERATION = 5,
        DECELERATION = 3,
        WEIGHT = 10,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class BODY {
        MAX_SPEED = 5,
        ACCELERATION = 1,
        DECELERATION = 1,
        WEIGHT = -40,
        LIVES = 3,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class SHIELD {
        MAX_SPEED = 0,
        ACCELERATION = 0,
        DECELERATION = 0,
        WEIGHT = 5,
        LIVES = 0,
        ARMOR = 5,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class AMMO {
        MAX_SPEED = 0,
        ACCELERATION = 0,
        DECELERATION = 0,
        WEIGHT = 0,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 30,
        DAMAGE = 0
    };

    enum class GUN {
        MAX_SPEED = 0,
        ACCELERATION = 0,
        DECELERATION = 0,
        WEIGHT = 5,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 1
    };
};

class ERaceParts {
public:
    enum class ENGINE {
        MAX_SPEED = 20,
        ACCELERATION = 3,
        DECELERATION = 3,
        WEIGHT = 10,
        LIVES = 3,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class WHEELS {
        MAX_SPEED = 5,
        ACCELERATION = 1,
        DECELERATION = 1,
        WEIGHT = 5,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class BRAKES {
        MAX_SPEED = 0,
        ACCELERATION = 0,
        DECELERATION = 5,
        WEIGHT = 0,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class TRANSMISSION {
        MAX_SPEED = 5,
        ACCELERATION = 5,
        DECELERATION = 3,
        WEIGHT = 10,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class BODY {
        MAX_SPEED = 10,
        ACCELERATION = 1,
        DECELERATION = 1,
        WEIGHT = -50,
        LIVES = 5,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class SHIELD {
        MAX_SPEED = 0,
        ACCELERATION = 0,
        DECELERATION = 0,
        WEIGHT = 10,
        LIVES = 0,
        ARMOR = 10,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class AMMO {
        MAX_SPEED = 0,
        ACCELERATION = 0,
        DECELERATION = 0,
        WEIGHT = 0,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 50,
        DAMAGE = 0
    };

    enum class GUN {
        MAX_SPEED = 0,
        ACCELERATION = 0,
        DECELERATION = 0,
        WEIGHT = 10,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 3
    };
};

class ESuperParts {
public:
    enum class ENGINE {
        MAX_SPEED = 10,
        ACCELERATION = 2,
        DECELERATION = 2,
        WEIGHT = 5,
        LIVES = 4,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class WHEELS {
        MAX_SPEED = 5,
        ACCELERATION = 1,
        DECELERATION = 1,
        WEIGHT = 5,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class BRAKES {
        MAX_SPEED = 0,
        ACCELERATION = 0,
        DECELERATION = 5,
        WEIGHT = 0,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class TRANSMISSION {
        MAX_SPEED = 5,
        ACCELERATION = 5,
        DECELERATION = 3,
        WEIGHT = 10,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class BODY {
        MAX_SPEED = 10,
        ACCELERATION = 1,
        DECELERATION = 1,
        WEIGHT = -50,
        LIVES = 6,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class SHIELD {
        MAX_SPEED = 0,
        ACCELERATION = 0,
        DECELERATION = 0,
        WEIGHT = 10,
        LIVES = 0,
        ARMOR = 15,
        AMMO = 0,
        DAMAGE = 0
    };

    enum class AMMO {
        MAX_SPEED = 0,
        ACCELERATION = 0,
        DECELERATION = 0,
        WEIGHT = 0,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 100,
        DAMAGE = 0
    };

    enum class GUN {
        MAX_SPEED = 0,
        ACCELERATION = 0,
        DECELERATION = 0,
        WEIGHT = 10,
        LIVES = 0,
        ARMOR = 0,
        AMMO = 0,
        DAMAGE = 5
    };
};

#endif //CARS_ENUMS_H
