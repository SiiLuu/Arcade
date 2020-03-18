/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** Arcade
*/

#include "errorGestion/errorGestion.hpp"

int main(int ac, char **argv)
{
    std::vector<std::string> av(argv, argv + ac);
    errorGestion error(ac, av);
    return (0);
}