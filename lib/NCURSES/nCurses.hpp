/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** nCurses class
*/
#include "../AGraph/AbstractGraph.hpp"

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

class nCurses : public AbstractGraph
{
    public:
        nCurses();
        ~nCurses();

        void createWindow();
        void displayGame(std::string game);
        void displayMenu(std::vector<std::vector<std::string>>);
        std::string registerEvents();

    private:
};

#endif /* !NCURSES_HPP_ */
