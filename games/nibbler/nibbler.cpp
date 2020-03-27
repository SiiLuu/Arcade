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
    this->MoveIA();
    this->MovePlayer();
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

void nibbler::MoveIA()
{
    std::cout << "NIBBLER -> move nibbler IA" << std::endl;
}

void nibbler::MovePlayer()
{
    std::cout << "NIBBLER -> move nibbler player" << std::endl;
}

extern "C" AbstractGame *create()
{
    return new nibbler();
}

extern "C" void destroy(AbstractGame *object)
{
    delete object;
}
