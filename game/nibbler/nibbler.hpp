/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** nibbler
*/
#include "../AGame/AbstractGame.hpp"
#include <iostream>

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

class nibbler : public AbstractGame
{
    private:
        /* data */
    public:
        nibbler(/* args */);
        ~nibbler();

        void MoveIA();
        void MovePlayer();
        void MoveForward();
        void MoveBackward();
        void MoveLeft();
        void MoveRight();
};

#endif /* !NIBBLER_HPP_ */
