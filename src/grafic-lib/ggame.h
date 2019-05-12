#ifndef CARS_GGAME_H
#define CARS_GGAME_H

#pragma once

class ICommand;

#include "gwindow.h"
#include "glevel.h"
#include "gracer.h"
#include "gbonus.h"
#include "gcommand.h"

class TextShow {
public:
    void draw(sf::RenderWindow &window);

    void addText(const std::string &ntext);

    bool setFont(const std::string &path);

    void clear();

private:
    std::string text;

    sf::Font font;
};

class Game {
public:
    Game();

    ~Game();

    void handleInput();

    void update();

    void render();

    Window *getWindow();

    sf::Time getElapsed();

    float &getAccumulateElapsed();

    void restartClock();

    void addBonus(const std::shared_ptr<GBonus>& b);

private:
    Window m_window;

    GLevel m_level;
    GRacer m_player;

    sf::Clock m_clock;
    sf::Time m_elapsed;
    float m_accumulate_elapsed;

    TextShow m_textShow;

    std::vector<std::shared_ptr<GBonus>> bonus;

    std::vector<std::shared_ptr<ICommand>> commands;

    void generatePoints(int n = DEFAULT_POINTS_NUMBER);
    void generateHeal();
};

#endif //CARS_GGAME_H
