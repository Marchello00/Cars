#ifndef CARS_GCOMMAND_H
#define CARS_GCOMMAND_H

class Game;

#include <SFML/Graphics/RenderWindow.hpp>
#include "ggame.h"

class ICommand {
public:
    virtual void execute(Game &game) = 0;
};

class GeneratePointCommand : public ICommand {
    void execute(Game &game) override;
};

class GenerateHealCommand: public ICommand {
    void execute(Game &game) override;
};

#endif //CARS_GCOMMAND_H
