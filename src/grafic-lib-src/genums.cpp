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
