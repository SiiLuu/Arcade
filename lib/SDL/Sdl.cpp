/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** sdl functions
*/

#include "Sdl.hpp"

Sdl::Sdl()
{
    this->createWindow();
    this->getCh();
    this->display();
}

Sdl::~Sdl()
{
    std::cout << "SDL Destroyed" << std::endl;
}

void Sdl::display()
{
    std::cout << "SDL -> Game displayed" << std::endl;
}

void Sdl::getCh()
{
    std::cout << "SDL -> Gestion des inputs" << std::endl;
}

void Sdl::createWindow()
{
    std::cout << "SDL -> Window Created" << std::endl;
}

extern "C" AbstractGraph *create()
{
    return new Sdl();
}

extern "C" void destroy(AbstractGraph *object)
{
    delete object;
}
