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

        void getCh();
        void createWindow();
        void display();

    private:
};

#endif /* !SDL_HPP_ */
