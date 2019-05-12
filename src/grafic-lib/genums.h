#ifndef CARS_GENUMS_H
#define CARS_GENUMS_H

#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "ground.h"

const sf::Vector2f UP = {0, -1},
                   DOWN = {0, 1},
                   LEFT = {-1, 0},
                   RIGHT = {1, 0};

const int RANDOM_GENERATOR_BORDERS = 20;

const int CAR_WIDTH = 42;
const int CAR_HEIGHT = 90;

const float WHEEL_ROTATE_SPEED = 0.1;
const float WHEEL_BACK_SPEED = 0.6;
const float WHEEL_BUFF = 80;
const float DEFAULT_SPEED_E = 2;
const float DEFAULT_ACCELERATION_E = 3;

const float STOP_ROTATE = 25;

enum class CAR_STATE {BACKWARD, STAY, FORWARD, LOSE};
const float SLOW_GRASS_RESISTANCE = 5;
const float SLOW_SAND_RESISTANCE = 3;
const float DAMAGE_DIRT_DAMAGE = 1;

const float DAMAGE_DIRT_INTERVAL = 1;

const int FONT_SIZE = 25;

const int POINT_SCORE = 10;
const int POINT_RADIUS = 8;
const sf::Color POINT_COLOR = sf::Color::Green;
const sf::Color POINT_BORDER_COLOR = sf::Color::Black;

const int HEALBONUS_HEAL = 5;
const int HEALBONUS_RADIUS = 10;
const sf::Color HEALBONUS_COLOR = sf::Color::Red;
const sf::Color HEALBONUS_BORDER_COLOR = sf::Color::Black;

const int HEALBONUS_SPAWN_PERIOD = 200;

const int DEFAULT_POINTS_NUMBER = 10;

namespace enums {
    int getRotation(std::string &s);

    sf::Vector2f getDirection(std::string &s);

    std::shared_ptr<CBaseGround> getGround(const std::string& type, const std::string& material);
}

const std::string SCORE_MISSION_BEGIN = "Collect the green dots! Try to score ";
const std::string SCORE_MISSION_END = " points!\n";

const std::string PIE_MESSAGE = "Get a pie!\n";

const std::string GAME_OVER = "You lose.\n";

#endif //CARS_GENUMS_H
