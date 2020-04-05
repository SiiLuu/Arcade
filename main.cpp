/*
** EPITECH PROJECT, 2020
** main.cpp
** File description:
** Arcade
*/

#include <vector>
#include "ArcadeCore.hpp"
#include "errorGestion/errorGestion.hpp"

int main(int ac, char **argv)
{
    std::vector<std::string> av(argv, argv + ac);
    errorGestion error(ac, av);
    if (error._error == 0)
        ArcadeCore arcade(av);
    else if (error._error == 1)
        return (84);
    return (0);
}
