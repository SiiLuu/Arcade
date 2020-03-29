/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Arcade core
*/
#include "scene/Scene.hpp"
#include "libLoader/LibLoader.hpp"
#include "games/AGame/AbstractGame.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <dirent.h>

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
        enum arcadeState
        {
            RUNNING,
            CLOSED
        };

        Scene *_scene;
        AbstractGraph *shared_lib;
        AbstractGame *shared_game;
        LibLoader *_lib;
        std::string _playerName;
        arcadeState _state;
        std::vector<std::string> _av;
        int _menu;
        int _actualLibrary;
        int _actualGame;

        void readDir(const std::string path, std::vector<std::string> &vector);
        void setLibrary();
        void setPlayerName();
        void setGame();
        void setScore();
        void swapLib(std::string str);
        void swapGame(std::string str);
        void events();
        int findLib();
        std::string _score;
        std::string _name;
        std::vector<std::string> libPath;
        std::vector<std::string> gamePath;
        std::vector<std::string> nameScore;
        std::vector<std::vector<std::string>> info;
        std::vector<std::vector<std::string>> _gamesInfos;
};

#endif /* !ARCADECORE_HPP_ */
