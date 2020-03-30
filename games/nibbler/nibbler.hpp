/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** nibbler
*/

#include "../AGame/AbstractGame.hpp"

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

class nibbler : public AbstractGame
{
    private:
        size_t _score;
        game::state _state;
        std::vector<std::string> _map;

    public:
        nibbler(/* args */);
        ~nibbler();

        void moveEnemy();
        void MoveForward();
        void MoveBackward();
        void MoveLeft();
        void MoveRight();
        void update();
        size_t getScore() const;
        game::state getState() const;
        void setState();
        std::vector<std::string> getMap() const;
};

#endif /* !NIBBLER_HPP_ */
