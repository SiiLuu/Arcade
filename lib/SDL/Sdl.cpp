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
    this->getCh();
    this->display();
}

Sdl::~Sdl()
{
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
}

void Sdl::display()
{
    std::cout << "SDL -> Game displayed" << std::endl;
}

void Sdl::getCh()
{
    std::cout << "SDL -> Gestion des inputs" << std::endl;
}

void Sdl::createWindow()
{
    std::cout << "SDL -> Window Created" << std::endl;
    SDL_Init(SDL_INIT_VIDEO);
    this->_window = SDL_CreateWindow(
        "Arcade",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
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
