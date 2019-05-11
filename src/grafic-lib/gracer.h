#ifndef CARS_GRACER_H
#define CARS_GRACER_H

#pragma once

#include <SFML/Graphics.hpp>
#include "genums.h"
#include "ground.h"
#include "cars.h"

class Racer {
public:

    Racer();

    void setPosition(sf::Vector2f newPosition);

    void setDirection(sf::Vector2f dir);

    void setImage(const std::string &path);

    void update(float tm, const std::shared_ptr<CBaseGround> &ground);

    void render(sf::RenderWindow &window);

    void setCar(std::shared_ptr<CCar> new_car);

    void leftTurn(float tm);

    void reactLeft(float tm);

    void rightTurn(float tm);

    void reactRight(float tm);

    void moveForward();

    void moveBackward();

    void reactBackward();

    void reactForward();


private:

    CAR_STATE state;

    sf::Vector2f direction;

    sf::Vector2f position;
    float speed;
    float acceleration;

    float deceleration;

    float wheel;
    int w = CAR_WIDTH, h = CAR_HEIGHT;

    sf::Texture texture;

    sf::Sprite sprite;

    std::shared_ptr<CCar> car;

    void changeSpeed(float tm, const std::shared_ptr<CBaseGround> &ground);

    sf::Vector2f getAcceleration(const std::shared_ptr<CBaseGround> &ground);

    float getAngle();
};

#endif //CARS_GRACER_H
