/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Absract Class for game
*/

#include "../IModuleGame.hpp"

#ifndef ABSTRACTGAME_HPP_
#define ABSTRACTGAME_HPP_

class AbstractGame : public game::IModuleGame
{
    public:
        AbstractGame();
        virtual ~AbstractGame();

        virtual void moveEnemy() = 0;
        virtual void init() = 0;
        virtual void MoveForward() = 0;
        virtual void MoveBackward() = 0;
        virtual void MoveLeft() = 0;
        virtual void MoveRight() = 0;
        virtual void update() = 0;
        virtual size_t getScore() const = 0;
        virtual size_t getHP() const = 0;
        virtual std::string getHighScore() const = 0;
        virtual game::state getState() const = 0;
        virtual void setState(game::state) = 0;
        virtual std::vector<std::string> getMap() const = 0;

    protected:
    private:
};

typedef AbstractGame *createGame_t();
typedef void destroyGame_t(AbstractGame *);

#endif /* !ABSTRACTGAME_HPP_ */
