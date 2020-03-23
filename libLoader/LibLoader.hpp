/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Lib loader class
*/
#include "../lib/AGraph/AbstractGraph.hpp"
#include <vector>
#include <iostream>
#include <dlfcn.h>
#include <stdio.h>


#ifndef LIBLOADER_HPP_
#define LIBLOADER_HPP_

class LibLoader {
    public:
        LibLoader();
        ~LibLoader();

        void load();
        void unLoad();

    protected:
    private:
        std::vector<std::string> libPath = {"./lib/lib_arcade_sfml.so",
                                            "./lib/lib_arcade_sdl.so",
                                            "./lib/lib_arcade_ncurses.so"};
};

#endif /* !LIBLOADER_HPP_ */
