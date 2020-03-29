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
        nCurses(std::vector<std::vector<std::string>>);
        ~nCurses();

        void createWindow();
        void display(std::vector<std::vector<std::string>>, int);
        std::string registerEvents();

        private:
            std::vector<std::vector<std::string>> _info;
            caca_canvas_t *_canvas;
            caca_display_t *_window;
            caca_event_t _event;
            caca_color _currentColor;
            std::string _listGames;
            std::string _listLibs;
            std::string _score;
            std::string _name;
            void getLists();
            void clear();
            void drawMen();
            void text(int x, int y, std::string str);

};

#endif /* !NCURSES_HPP_ */
