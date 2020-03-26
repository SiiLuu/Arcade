/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** sdl functions
*/

#include "Sdl.hpp"

Sdl::Sdl()
{
    this->createWindow();
}

Sdl::~Sdl()
{
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
}

std::string Sdl::registerEvents()
{
    while (SDL_PollEvent(&this->_events))
    {
        if (this->_events.type == SDL_QUIT)
            return ("CLOSE");
        switch (this->_events.key.keysym.sym) {
        case SDLK_p:
            return ("P");
        case SDLK_n:
            return ("N");
        case SDLK_1:
            return ("1");
        case SDLK_3:
            return ("3");
        case SDLK_z:
            return ("Z");
        case SDLK_q:
            return ("Q");
        case SDLK_s:
            return ("S");
        case SDLK_d:
            return ("D");
        default:
            break;
        }
    }
    return ("");
}

void Sdl::displayGame(std::string game)
{
    
}

void Sdl::displayMenu()
{
    
}

void Sdl::createWindow()
{
    SDL_Init(SDL_INIT_VIDEO);
    this->_window = SDL_CreateWindow(
        "Arcade",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1600,
        900,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    if (this->_window == NULL)
    {
        std::cout << "Could not create window Arcade." << std::endl;
    }
}

extern "C" AbstractGraph *create()
{
    return new Sdl();
}

extern "C" void destroy(AbstractGraph *object)
{
    delete object;
}
