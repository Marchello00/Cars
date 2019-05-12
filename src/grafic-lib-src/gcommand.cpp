#include "genums.h"
#include "bonus.h"
#include "gcommand.h"

sf::Vector2f genPoint(const sf::Vector2u &sz) {
    return {(std::rand() % (sz.x - 2 * RANDOM_GENERATOR_BORDERS) + RANDOM_GENERATOR_BORDERS) * 1.0f,
            (std::rand() % (sz.y - 2 * RANDOM_GENERATOR_BORDERS) + RANDOM_GENERATOR_BORDERS) * 1.0f};
}

void GeneratePointCommand::execute(Game &game) {
    sf::Vector2f pos = genPoint(game.getWindow()->getRenderWindow()->getSize());
    auto bonus = std::make_shared<GPoint>();
    bonus->setPosition(pos);
    game.addBonus(bonus);
}

void GenerateHealCommand::execute(Game &game) {
    sf::Vector2f pos = genPoint(game.getWindow()->getRenderWindow()->getSize());
    auto bonus = std::make_shared<GHeal>();
    bonus->setPosition(pos);
    game.addBonus(bonus);
}
