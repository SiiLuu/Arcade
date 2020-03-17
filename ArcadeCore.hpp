/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Arcade core
*/
#include "scene/Scene.hpp"
#include <string>

#ifndef ARCADECORE_HPP_
#define ARCADECORE_HPP_

class ArcadeCore {
    public:
        ArcadeCore();
        ~ArcadeCore();

        void gameLoop();
        std::string getPlayerName() const;

    protected:
    private:
        Scene *_scene;
        std::string playerName;
        std::string score;

        void setLibrary();
        void setPlayerName();
        void setGame();
        void setScore();

        enum library
        {
            SFML,
            SDL,
            NCURSES
        };
};

#endif /* !ARCADECORE_HPP_ */
