#include <string>

#include "../grafic-lib/genums.h"

int enums::getRotation(std::string &s) {
    enum ROTATION {
        RIGHT = 0, DOWN = 90, LEFT = 180, UP = 270
    };

    if (s == "left") {
        return LEFT;
    } else if (s == "down") {
        return DOWN;
    } else if (s == "right") {
        return RIGHT;
    } else if (s == "up") {
        return UP;
    }

    return 0;
}

sf::Vector2f enums::getDirection(std::string &s) {
    if (s == "left") {
        return {-1, 0};
    } else if (s == "down") {
        return {0, 1};
    } else if (s == "right") {
        return {1, 0};
    } else if (s == "up") {
        return {0, -1};
    }

    return {0, 0};
}

std::shared_ptr<CBaseGround> enums::getGround(const std::string &type, const std::string &material) {
    if (type == "slow") {
        if (material == "grass") {
            return std::make_shared<CSlowGround>(SLOW_GRASS_RESISTANCE);
        }
        if (material == "sand") {
            return std::make_shared<CSlowGround>(SLOW_SAND_RESISTANCE);
        }
    }
    if (type == "damage") {
        if (material == "dirt") {
            return std::make_shared<CDamageGround>(DAMAGE_DIRT_DAMAGE,
                                                   DAMAGE_DIRT_INTERVAL);
        }
    }
    return std::make_shared<CBaseGround>();
}
