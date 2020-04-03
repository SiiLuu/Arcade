/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** libCaca class
*/

#include "../AGraph/AbstractGraph.hpp"

#ifndef libCaca_HPP_
#define libCaca_HPP_

class libCaca : public AbstractGraph
{
    public:
        libCaca(std::vector<std::vector<std::string>>);
        ~libCaca();

        void createWindow();
        void display(std::vector<std::vector<std::string>>, int);
        std::string registerEvents();

        private:
            std::vector<std::vector<std::string>> _info;
            caca_canvas_t *_canvas;
            caca_display_t *_window;
            caca_event_t _event;
            caca_color _currentColor;
            std::vector<std::string> _actualScore;
            std::string _listGames;
            std::string _listLibs;
            std::string _score;
            std::string _name;
            bool check;
            void getLists();
            void clear();
            void drawMen();
            void drawGame(std::vector<std::vector<std::string>>);
            void text(int, int, std::string);

};

#endif /* !libCaca_HPP_ */
