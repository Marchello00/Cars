#ifndef CARS_GGAME_H
#define CARS_GGAME_H

#include "gwindow.h"

class Game {
public:
    Game();
    ~Game();

    void handleInput();
    void update();
    void render();
    sf::Window *getWindow();

private:
     Window m_window;
};

#endif //CARS_GGAME_H
