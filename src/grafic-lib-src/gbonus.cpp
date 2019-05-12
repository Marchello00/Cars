#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <src/grafic-lib/genums.h>
#include "gbonus.h"

void GPoint::render(sf::RenderWindow &window) {
    window.draw(circle);
}

void GPoint::update() { }

bool GPoint::outOfDate() {
    return used;
}

GPoint::GPoint(int score): score(score) {
    circle.setRadius(POINT_RADIUS);
    circle.setFillColor(POINT_COLOR);
    circle.setOutlineColor(POINT_BORDER_COLOR);
}

void GPoint::setPosition(sf::Vector2f &pos) {
    circle.setPosition(pos);
}

void GPoint::setUsed() {
    used = true;
}

void GPoint::applyToRacer(GRacer &racer) {
    setUsed();
    racer.applyPoint(*this);
}

bool GPoint::intersects(const sf::FloatRect &fr) {
    return circle.getGlobalBounds().intersects(fr);
}

int GPoint::getScore() const {
    return score;
}

void GHeal::render(sf::RenderWindow &window) {
    window.draw(circle);
}

void GHeal::update() { }

bool GHeal::outOfDate() {
    return used;
}

void GHeal::applyToRacer(GRacer &racer) {
    setUsed();
    racer.applyHeal(*this);
}

void GHeal::setUsed() {
    used = true;
}

GHeal::GHeal(int heal): heal(heal) {
    circle.setRadius(HEALBONUS_RADIUS);
    circle.setFillColor(HEALBONUS_COLOR);
    circle.setOutlineColor(HEALBONUS_BORDER_COLOR);
}

void GHeal::setPosition(sf::Vector2f &pos) {
    circle.setPosition(pos);
}

bool GHeal::intersects(const sf::FloatRect &fr) {
    return circle.getGlobalBounds().intersects(fr);
}

int GHeal::getHeal() const {
    return heal;
}
