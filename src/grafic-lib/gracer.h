#ifndef CARS_GRACER_H
#define CARS_GRACER_H

#pragma once

class GBonus;
class GPoint;
class GHeal;

#include <SFML/Graphics.hpp>
#include "genums.h"
#include "ground.h"
#include "cars.h"
#include "gbonus.h"
#include <src/helpers-lib/TmxLevel.h>

class GRacer {
public:

    GRacer();

    void setPosition(sf::Vector2f newPosition);

    void setDirection(sf::Vector2f dir);

    void setImage(const std::string &path);

    void update(float tm, float &accumulate_tm, const std::vector<std::shared_ptr<GBonus>> &bonuses);

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

    void setField(sf::Vector2f sz);

    void addObject(TmxObject &obj);

    void applyPoint(GPoint &point);

    void applyHeal(GHeal &heal);

    void setGoal(int g);

    int getGoal() const;

    int getScore() const;

    std::string getText();

    sf::ConvexShape shape();

    bool intersect(const sf::FloatRect &fr);

    void setMission(const std::string &m);

    void setMissionScore();

    void setPieMessage();

private:
    std::string mission;

    int goal = 0;

    int score = 0;

    CAR_STATE state;

    sf::Vector2f direction;

    sf::Vector2f position;
    float speed;
    float acceleration;

    float deceleration;

    int lives;

    float wheel;
    int w = CAR_WIDTH, h = CAR_HEIGHT;
    sf::FloatRect border;

    sf::Texture texture;

    sf::Sprite sprite;

    std::shared_ptr<CCar> car;

    void changeSpeed(float tm);

    float getAngle();

    void analyseObjects();

    void checkDamage(float &accumulate_tm);

    bool checkWalls();

    bool checkBorders();

    void checkLives();

    void analyseBonuses(const std::vector<std::shared_ptr<GBonus>> &bonuses);

    std::vector<TmxObject> objects;
    std::vector<sf::FloatRect> walls;
    std::shared_ptr<CBaseGround> ground;

    std::string debug;
};

#endif //CARS_GRACER_H
