#include <iostream>
#include "gracer.h"
#include "TmxLevel.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(1280, 1280), "X_x_level_x_X");

    sf::Clock clock;
    double time;

    sf::Image racerImage;
    racerImage.loadFromFile("images/bv.png");

    GRacer racer(racerImage, 100, 100);

    TmxLevel level;
    level.loadFromFile("maps/map2.tmx");
    while (window.isOpen()) {

        time = clock.getElapsedTime().asMilliseconds();
        clock.restart();

        sf::Event event{};
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed ||
                (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)) {
                window.close();
            }
        }

        window.clear();

        level.draw(window);
        racer.draw(window);

        window.display();
    }
    return 0;
}