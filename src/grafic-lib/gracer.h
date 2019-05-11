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

    void update(float tm, const CBaseGround &ground);

    void render(sf::RenderWindow &window);

    void setCar(std::shared_ptr<CCar> new_car);

    void setSpeedE(float newSpeedE);

    void leftTurn();

    void rightTurn();

    void moveForward();

    void moveBackward();

private:

    sf::Vector2f position;

    sf::Vector2f speed;
    double speedE = DEFAULT_SPEED_E; // convert constants from enums to real speed
    float angle;
    float acceleration;

    int w = CAR_WIDTH, h = CAR_HEIGHT;
    sf::Texture texture;

    sf::Sprite sprite;

    std::shared_ptr<CCar> car;

    void changeSpeed(float tm, const CBaseGround &ground);

    double getAcceleration(const CBaseGround &ground);

    bool isMoving();
};

#endif //CARS_GRACER_H
