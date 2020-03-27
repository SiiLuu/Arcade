/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** pacman class
*/
#include "pacman.hpp"

Pacman::Pacman(/* args */)
{
    std::cout << "PACMAN -> created" << std::endl;
    this->MoveIA();
}

Pacman::~Pacman()
{
    std::cout << "PACMAN -> Game destroyed" << std::endl;
}

void Pacman::MoveIA()
{
    std::cout << "PACMAN -> move IA" << std::endl;
}

void Pacman::MovePlayer()
{
    std::cout << "PACMAN -> player has been mooved" << std::endl;
}

void Pacman::MoveForward()
{
    std::cout << "PACMAN -> player go to the front" << std::endl;
}

void Pacman::MoveBackward()
{
    std::cout << "PACMAN -> player go to the back" << std::endl;
}

void Pacman::MoveLeft()
{
    std::cout << "PACMAN -> player go to the left" << std::endl;
}

void Pacman::MoveRight()
{
    std::cout << "PACMAN -> player go to the right" << std::endl;
}

extern "C" AbstractGame *create()
{
    return new Pacman();
}

extern "C" void destroy(AbstractGame *object)
{
    delete object;
}
