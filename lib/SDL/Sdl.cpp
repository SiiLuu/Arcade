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
    SDL_DestroyRenderer(this->renderer);
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
        case SDLK_ESCAPE:
            return ("ESCAPE");
        default:
            break;
        }
    }
    return ("");
}

void Sdl::displayGame(std::string game)
{
    SDL_RenderClear(renderer);
    if (!game.compare("PACMAN")) {
        SDL_RenderCopy(renderer, tpacman, NULL, NULL);
    }
    else if (!game.compare("NIBBLER")) {
        SDL_RenderCopy(renderer, tnibbler, NULL, NULL);
    }
    SDL_RenderPresent(renderer);
}

void Sdl::displayMenu()
{
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, tbg, NULL, NULL);
    SDL_RenderPresent(renderer);
}

void Sdl::setTexture()
{
    this->bg = IMG_Load("assets/arcade.jpg");
    this->tbg = SDL_CreateTextureFromSurface(this->renderer, this->bg);
    SDL_FreeSurface(bg);
    this->spacman = IMG_Load("assets/pacman.png");
    this->tpacman = SDL_CreateTextureFromSurface(this->renderer, this->spacman);
    SDL_FreeSurface(spacman);
    this->snibbler = IMG_Load("assets/snake.png");
    this->tnibbler = SDL_CreateTextureFromSurface(this->renderer, this->snibbler);
    SDL_FreeSurface(snibbler);
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
    this->renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
    setTexture();
}

extern "C" AbstractGraph *create()
{
    return new Sdl();
}

extern "C" void destroy(AbstractGraph *object)
{
    delete object;
}
