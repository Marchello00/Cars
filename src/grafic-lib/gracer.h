#ifndef CARS_GRACER_H
#define CARS_GRACER_H

#pragma once

#include <SFML/Graphics.hpp>
#include "genums.h"

class GRacer {
private:
    double x, y;
    double speed;
    double w = CAR_WIDTH, h = CAR_HEIGHT;
    sf::Texture texture;
    sf::Sprite sprite;

public:
    GRacer(sf::Image &image, double x, double y) :
            x(x), y(y), speed(0) {
        texture.loadFromImage(image);
        sprite.setTexture(texture);
        sprite.setOrigin(w / 2, h / 2);
        sprite.setScale(w / image.getSize().x, h / image.getSize().y);
    }

    void update(double time) {
        sprite.setPosition(x + w / 2, y + h / 2);
    }

    void draw(sf::RenderWindow &window) {
        window.draw(sprite);
    }
};

#endif //CARS_GRACER_H
