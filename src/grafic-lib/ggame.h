#ifndef CARS_GGAME_H
#define CARS_GGAME_H

#include <SFML/Window.hpp>

class Game {
public:
    Game();
    ~Game();

    void handleInput();
    void update();
    void render();
    sf::Window *getWindow();

private:
    sf::Window m_window;
};

#endif //CARS_GGAME_H
