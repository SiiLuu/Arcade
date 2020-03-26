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
    std::cout << "SDL Destroyed" << std::endl;
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
}

void Sdl::displayGame()
{
}

void Sdl::displayMenu()
{
    std::cout << "SDL -> Game displayed" << std::endl;
}

std::string Sdl::registerEvents()
{
    while (SDL_PollEvent(&this->_events))
    {
        switch (this->_events.type)
        {
        case SDL_QUIT:
            return ("CLOSE");
        default:
            break;
        }
    }
    return ("");
}

void Sdl::createWindow()
{
    std::cout << "SDL -> Window Created" << std::endl;
    SDL_Init(SDL_INIT_VIDEO);
    this->_window = SDL_CreateWindow(
        "Arcade",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1920,
        1080,
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
