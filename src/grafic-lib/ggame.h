#ifndef CARS_GGAME_H
#define CARS_GGAME_H

#pragma once

#include "gwindow.h"
#include "glevel.h"
#include "gracer.h"

class Game {
public:
    Game();

    ~Game();

    void handleInput();

    void update();

    void render();

    Window *getWindow();

    sf::Time getElapsed();

    void restartClock();

private:
    Window m_window;

    Level m_level;
    Racer m_player;

    sf::Clock m_clock;
    sf::Time m_elapsed;
};

#endif //CARS_GGAME_H
