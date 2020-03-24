/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** Arcade
*/
#include <iostream>
#include "ArcadeCore.hpp"
#include "errorGestion/errorGestion.hpp"

int main(int ac, char **argv)
{
    std::vector<std::string> av(argv, argv + ac);
    errorGestion error(ac, av);
    ArcadeCore arcade(av);
    return (0);
}
