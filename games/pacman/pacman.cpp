/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** pacman class
*/

#include "pacman.hpp"

Pacman::Pacman()
{
    std::cout << "PACMAN -> created" << std::endl;
}

Pacman::~Pacman()
{
    std::cout << "PACMAN -> Game destroyed" << std::endl;
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

void Pacman::moveEnemy()
{
    std::cout << "NIBBLER -> enemy mooved" << std::endl;
}

void Pacman::update()
{
}

size_t Pacman::getScore() const
{
    return (this->_score);
}

game::state Pacman::getState() const
{
    return (this->_state);
}

std::vector<std::string> Pacman::getMap() const
{
    return (this->_map);
}

void Pacman::setState()
{
}

extern "C" AbstractGame *create()
{
    return new Pacman();
}

extern "C" void destroy(AbstractGame *object)
{
    delete object;
}
