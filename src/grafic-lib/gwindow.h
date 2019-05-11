#ifndef CARS_GWINDOW_H
#define CARS_GWINDOW_H

#include <SFML/Graphics.hpp>
#include "TmxLevel.h"

class Window {
public:
    Window();

    Window(const std::string &l_title, const sf::Vector2u &l_size);

    ~Window();

    void beginDraw();
    void endDraw();
    void update();

    bool isDone();

    bool isFullscreen();

    sf::Vector2u getWindowSize();

    void toggleFullscreen();

    void draw(sf::Drawable &l_drawable);

    void draw(TmxLevel &level);

private:
    void setup(const std::string &l_title,
               const sf::Vector2u &l_size);

    void destroy();

    void create();

    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone;
    bool m_isFullscreen;
};

#endif //CARS_GWINDOW_H
