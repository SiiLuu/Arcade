/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Arcade core
*/
#include "scene/Scene.hpp"
#include "./lib/AGraph/AbstractGraph.hpp"
#include "libLoader/LibLoader.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <dlfcn.h>

#ifndef ARCADECORE_HPP_
#define ARCADECORE_HPP_

class ArcadeCore {
    public:
        ArcadeCore(std::vector<std::string> av);
        ArcadeCore();
        ~ArcadeCore();

        void gameLoop();
        std::string getPlayerName() const;

    protected:
    private:
        enum library
        {
            NONE,
            SFML,
            SDL,
            NCURSES
        };

        Scene *_scene;
        AbstractGraph *shared_lib;
        LibLoader *_lib;
        std::string _playerName;
        std::string _score;
        library _library;
        std::vector<std::string> _av;

        void setLibrary();
        void setPlayerName();
        void setGame();
        void setScore();
        void swapLib(std::string str);
        library getLib(std::string lib) const;
        std::vector<std::string> libPath = {"./lib/lib_arcade_sfml.so",
                                            "./lib/lib_arcade_sdl.so",
                                            "./lib/lib_arcade_ncurses.so"};
};

#endif /* !ARCADECORE_HPP_ */
