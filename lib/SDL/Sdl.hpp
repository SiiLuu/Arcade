/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** sdl class
*/
#include "../AGraph/AbstractGraph.hpp"

#ifndef SDL_HPP_
#define SDL_HPP_

class Sdl : public AbstractGraph
{
    public:
        Sdl();
        ~Sdl();

        void createWindow();
        void displayGame();
        void displayMenu();
        std::string registerEvents();

    private:
        SDL_Window *_window;
        SDL_Event _events;
};

#endif /* !SDL_HPP_ */
