/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** pacman class
*/
#include "../AGame/AbstractGame.hpp"
#include <iostream>

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

class Pacman : public AbstractGame
{
    private:
        /* data */
    public:
        Pacman(/* args */);
        ~Pacman();

        void MovePlayer();
        void MoveIA();
        void MoveForward();
        void MoveBackward();
        void MoveLeft();
        void MoveRight();
};

#endif /* !PACMAN_HPP_ */
