/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Absract Class for game
*/

#include "ArcadeCore.hpp"
#include "IModuleGame.hpp"
#include "Entity.hpp"
#include <vector>

#ifndef ABSTRACTGAME_HPP_
#define ABSTRACTGAME_HPP_

class AbstractGame : public IModuleGame {
    public:
        AbstractGame();
        ~AbstractGame();
        void saveScore();
        void initGame();

        void initGame();

    protected:
    private:
        std::vector<Entity> ent;
        ArcadeCore *ptr;
};

#endif /* !ABSTRACTGAME_HPP_ */
