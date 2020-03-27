/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Absract Class for game
*/
#include "../IModuleGame.hpp"
#include "../entity/Entity.hpp"
#include <vector>
#include <string>

#ifndef ABSTRACTGAME_HPP_
#define ABSTRACTGAME_HPP_

class AbstractGame : public IModuleGame {
    public:
        AbstractGame();
        virtual ~AbstractGame();

        //virtual void saveScore() = 0;
        //virtual void initGame() = 0;
        virtual void MovePlayer() = 0;
        virtual void MoveIA() = 0;
        virtual void MoveForward() = 0;
        virtual void MoveBackward() = 0;
        virtual void MoveLeft() = 0;
        virtual void MoveRight() = 0;

    protected:
    private:
        std::vector<std::string> ent;
};

typedef AbstractGame *createGame_t();
typedef void destroyGame_t(AbstractGame *);

#endif /* !ABSTRACTGAME_HPP_ */
