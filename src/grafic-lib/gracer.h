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

    void setRotation(double alpha);

    void setImage(const std::string &path);

    void update(float tm, const std::shared_ptr<CBaseGround> &ground);

    void render(sf::RenderWindow &window);

    void setCar(std::shared_ptr<CCar> new_car);

    void leftTurn();

    void rightTurn();

    void moveForward();

    void moveBackward();

    void resetDeceleration();

    void resetAcceleration();

    void resetAngle();

private:

    sf::Vector2f position;

    sf::Vector2f speed;
    sf::Vector2f acc;
    float angle;
    float acceleration;
    float deceleration;

    int w = CAR_WIDTH, h = CAR_HEIGHT;
    sf::Texture texture;

    sf::Sprite sprite;

    std::shared_ptr<CCar> car;

    void changeSpeed(float tm, const std::shared_ptr<CBaseGround> &ground);

    sf::Vector2f changeAcceleration(const std::shared_ptr<CBaseGround> &ground);

    bool isMoving();

    float getRadian();

    bool movingForward;

    float getMovingAngle();
};

#endif //CARS_GRACER_H
