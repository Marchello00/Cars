#include <string>
#include "../grafic-lib/genums.h"

int enums::getRotation(std::string &s) {
    enum ROTATION {
        LEFT = 0, UP = 90, RIGHT = 180, DOWN = 270
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
