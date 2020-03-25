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

        void getCh();
        void createWindow();
        std::string display();

        private:
};

#endif /* !NCURSES_HPP_ */
