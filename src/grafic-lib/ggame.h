#ifndef CARS_GGAME_H
#define CARS_GGAME_H

#pragma once

#include "gwindow.h"
#include "glevel.h"

class Game {
public:
    Game();

    ~Game();

    void handleInput();

    void update();

    void render();

    Window *getWindow();

private:
    Window m_window;

    Level m_level;
};

#endif //CARS_GGAME_H
