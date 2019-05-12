#ifndef CARS_GBONUS_H
#define CARS_GBONUS_H

class GRacer;

#include <SFML/System.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include "gracer.h"


class GBonus {
public:
    virtual void render(sf::RenderWindow &window) =0;
    virtual void update()=0;
    virtual bool outOfDate()=0;
    virtual void applyToRacer(GRacer &racer) =0;
    virtual bool intersects(const sf::FloatRect &fr) =0;
};

class GPoint: public GBonus {
public:
    void render(sf::RenderWindow &window) override;

    void update() override;

    bool outOfDate() override;

    void applyToRacer(GRacer &racer) override;

    void setUsed();

    explicit GPoint(int score = POINT_SCORE);

    void setPosition(sf::Vector2f &pos);

    bool intersects(const sf::FloatRect &fr) override;

    int getScore() const;

private:
    sf::CircleShape circle;

    int score;

    bool used = false;
};

class GHeal: public GBonus {
public:
    void render(sf::RenderWindow &window) override;

    void update() override;

    bool outOfDate() override;

    void applyToRacer(GRacer &racer) override;

    void setUsed();

    explicit GHeal(int heal = HEALBONUS_HEAL);

    void setPosition(sf::Vector2f &pos);

    bool intersects(const sf::FloatRect &fr) override;

    int getHeal() const;

private:
    sf::CircleShape circle;

    int heal;

    bool used = false;
};

#endif //CARS_GBONUS_H
