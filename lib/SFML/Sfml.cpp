/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** sfml functions
*/

#include "Sfml.hpp"

Sfml::Sfml()
{
    this->createWindow();
    this->getCh();
    this->display();
}

Sfml::~Sfml()
{
    std::cout << "SFML Destroyed" << std::endl;
}

void Sfml::display()
{
    std::cout << "SFML -> Game displayed" << std::endl;
}

void Sfml::getCh()
{
    std::cout << "SFML -> Gestion des inputs" << std::endl;
}

void Sfml::createWindow()
{
    std::cout << "SFML -> Window Created" << std::endl;
}

extern "C" AbstractGraph *create()
{
    return new Sfml();
}

extern "C" void destroy(AbstractGraph *object)
{
    delete object;
}
