/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** sdl functions
*/

#include "Sdl.hpp"

Sdl::Sdl(std::vector<std::vector<std::string>> name)
{
    this->createWindow();
    this->_clock = 0;
}

Sdl::~Sdl()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->_window);
    SDL_Quit();
}

std::string Sdl::registerEvents()
{
    this->_clock += 1;
    while (SDL_PollEvent(&this->_events)) {
        if (this->_events.type == SDL_QUIT)
            return ("CLOSE");
        if (this->_clock > 100) {
            this->_clock = 0;
            switch (this->_events.key.keysym.sym) {
                case SDLK_LEFT:
                    return ("KEYLEFT");
                case SDLK_RIGHT:
                    return ("KEYRIGHT");
                case SDLK_DOWN:
                    return ("KEYDOWN");
                case SDLK_UP:
                    return ("KEYUP");
                case SDLK_ESCAPE:
                    return ("ESCAPE");
                default:
                    return ("");
            }
        }
    }
    return ("");
}

void Sdl::display(std::vector<std::vector<std::string>> infos, int scene)
{
    SDL_RenderClear(renderer);
    if (scene == 1) {
        SDL_RenderCopy(renderer, tbg, NULL, NULL);
    }
    else if (scene == 2) {
        SDL_RenderCopy(renderer, tpacman, NULL, NULL);
    }
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

extern "C" AbstractGraph *create(std::vector<std::vector<std::string>> name)
{
    return new Sdl(name);
}

extern "C" void destroy(AbstractGraph *object)
{
    delete object;
}
