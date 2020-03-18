/*
** EPITECH PROJECT, 2020
** errorGestion.cpp
** File description:
** Arcade
*/

#include "errorGestion.hpp"

errorGestion::errorGestion(int ac, std::vector<std::string> av)
{
    this->argsGestion(ac, av);
}

errorGestion::~errorGestion()
{
}

void errorGestion::argsGestion(int ac, std::vector<std::string> av)
{
    try {
        if (ac != 2)
            throw Error(1, "You need almost add one lib with this binary.");
        if (av[1].compare("OUI") != 0)
            throw Error(1, "Bad library.");
    }
    catch(std::exception const &error) {
        std::cerr << "Error : " << error.what() << std::endl;
        std::exit(84);
    }
}
