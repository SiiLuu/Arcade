/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** sfml functions
*/

#include "Sfml.hpp"

Sfml::Sfml(/* args */)
{
}

Sfml::~Sfml()
{
}

void Sfml::getCh()
{
    std::cout << "je suis dans sfml" << std::endl;
}

extern "C" AbstractGraph *create()
{
        return new Sfml();
}
