#include <iostream>
#include "ggame.h"

int main() {
    Game game;
    while (!game.getWindow()->isDone()) {
        game.handleInput();
        game.update();
        game.render();
    }
    return 0;
}