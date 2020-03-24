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
    void *handle;
    try
    {
        if (ac != 2)
            throw Error(1, "You need almost add one lib with this binary.");
        if ((av[1].compare("./lib/lib_arcade_sfml.so") != 0) &&
            (av[1].compare("./lib/lib_arcade_sdl.so") != 0) &&
            (av[1].compare("./lib/lib_arcade_ncurses.so") != 0) &&
            (av[1].compare("lib/lib_arcade_sdl.so") != 0) &&
            (av[1].compare("lib/lib_arcade_sfml.so") != 0) &&
            (av[1].compare("lib/lib_arcade_ncurses.so") != 0))
            throw Error(1, "Wrong library.");
        if (!(handle = dlopen(av.at(1).c_str(), RTLD_LAZY))) {
            throw Error(2, "Cannot open this shared libray");
            dlclose(handle);
        }
    }
    catch(std::exception const &error) {
        std::cerr << "Error : " << error.what() << std::endl;
        std::exit(84);
    }
}
