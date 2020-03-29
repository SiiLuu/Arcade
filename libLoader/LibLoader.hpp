/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Lib loader class
*/
//#pragma once
//#include "../game/AGame/AbstractGame.hpp"
#include "../lib/AGraph/AbstractGraph.hpp"
#include "../games/AGame/AbstractGame.hpp"
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
            libCaca
        };

        void loadGraphical(std::string av, std::vector<std::vector<std::string>> infos);
        void loadGames(std::string av);
        void destroyGames();
        void destroyGraphical();

        AbstractGraph *_actual_graphical_lib;
        destroyGraphical_t *destroy__graphical_lib;
        AbstractGame *_actual_game_lib;
        destroyGame_t *destroy_game_lib;

    protected:
    private:
        void *_handle_lib;
        void *_handle_game;
};

#endif /* !LIBLOADER_HPP_ */
