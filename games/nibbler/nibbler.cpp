/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** nibbler
*/

#include "nibbler.hpp"

nibbler::nibbler()
{
    std::cout << "NIBBLER -> created" << std::endl;
}

nibbler::~nibbler()
{
    std::cout << "NIBBLER -> game destroyed" << std::endl;
}

void nibbler::MoveForward()
{
    std::cout << "NIBBLER -> move forward" << std::endl;
}

void nibbler::MoveBackward()
{
    std::cout << "NIBBLER -> move backward" << std::endl;
}

void nibbler::MoveLeft()
{
    std::cout << "NIBBLER -> move left" << std::endl;
}

void nibbler::MoveRight()
{
    std::cout << "NIBBLER -> move right" << std::endl;
}

void nibbler::moveEnemy()
{
    std::cout << "NIBBLER -> enemy mooved" << std::endl;
}

void nibbler::update()
{
}

size_t nibbler::getScore() const
{
    return (this->_score);
}

game::state nibbler::getState() const
{
    return (this->_state);
}

std::vector<std::string> nibbler::getMap() const
{
    return (this->_map);
}

void nibbler::setState()
{
}

extern "C" AbstractGame *create()
{
    return new nibbler();
}

extern "C" void destroy(AbstractGame *object)
{
    delete object;
}