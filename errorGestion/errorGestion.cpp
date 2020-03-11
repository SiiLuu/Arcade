/*
** EPITECH PROJECT, 2020
** errorGestion.cpp
** File description:
** Arcade
*/

#include "errorGestion.hpp"

errorGestion::errorGestion(char **av)
{
    this->argsGestion(av);
}

errorGestion::~errorGestion()
{
}

void errorGestion::argsGestion(char **av)
{
    try {
        if (!av[1])
            throw Error(1, "You need almost one");
    }
    catch(std::exception const &error) {
        std::cerr << "Error : " << error.what() << std::endl;
        std::exit(84);
    }
}
