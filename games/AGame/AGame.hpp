/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Absract Class for game
*/

#include "../../ArcadeCore.hpp"
#include "../IModuleGame.hpp"
#include "../entity/Entity.hpp"
#include <vector>
#include <string>

#ifndef ABSTRACTGAME_HPP_
#define ABSTRACTGAME_HPP_

class AbstractGame : public IModuleGame {
    public:
        void saveScore();
        void initGame();

    protected:
    private:
        std::vector<std::string> ent;
        ArcadeCore *ptr;
};

#endif /* !ABSTRACTGAME_HPP_ */
