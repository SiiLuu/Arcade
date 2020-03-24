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

        enum library
        {
            NONE,
            SFML,
            SDL,
            NCURSES
        };

        void load(std::string av);
        void unLoad();
        void destroyLib();

        AbstractGraph *_actual_lib;
        destroy_t *destroy_lib;

    protected:
    private:
        void *_handle;
};

#endif /* !LIBLOADER_HPP_ */
