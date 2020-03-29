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
        Sdl(std::vector<std::vector<std::string>>);
        ~Sdl();

        void createWindow();
        void display(std::vector<std::vector<std::string>>, int);
        std::string registerEvents();

    private:
        SDL_Window *_window;
        SDL_Renderer *renderer;
        SDL_Surface *bg;
        SDL_Texture *tbg;
        SDL_Surface *spacman;
        SDL_Texture *tpacman;
        SDL_Surface *snibbler;
        SDL_Texture *tnibbler;
        SDL_Event _events;
        size_t _clock;
        size_t _lastTime;
        void setTexture();
};

#endif /* !SDL_HPP_ */
