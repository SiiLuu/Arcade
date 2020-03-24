/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Arcade core
*/
#include "scene/Scene.hpp"
#include "libLoader/LibLoader.hpp"
#include "lib/AGraph/AbstractGraph.hpp"
#include "game/AGame/AbstractGame.hpp"
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

        enum games
        {
            PACMAN,
            NIBBLER
        };

        Scene *_scene;
        AbstractGraph *shared_lib;
        AbstractGame *shared_game;
        LibLoader *_lib;
        std::string _playerName;
        std::string _score;
        library _library;
        games _game;
        std::vector<std::string> _av;

        void setLibrary();
        void setPlayerName();
        void setGame();
        void setScore();
        void swapLib(std::string str);
        void swapGame(std::string str);
        void event(std::string event);
        library getLib(std::string liba) const;
        std::vector<std::string> libPath = {"./lib/lib_arcade_sfml.so",
                                            "./lib/lib_arcade_sdl.so",
                                            "./lib/lib_arcade_ncurses.so"};
        std::vector<std::string> gamePath = {"./game/lib_arcade_pacman.so",
                                            "./game/lib_arcade_nibbler.so"};
};

#endif /* !ARCADECORE_HPP_ */
