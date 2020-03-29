/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** sdl functions
*/

#include "Sdl.hpp"

Sdl::Sdl(std::vector<std::vector<std::string>> info)
{
    this->_info = info;
    this->_clock = 0;
    this->createWindow();
}

Sdl::~Sdl()
{
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->_window);
    TTF_CloseFont(this->_font);
    TTF_Quit();
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
        SDL_RenderClear(this->renderer);
        SDL_RenderCopy(this->renderer, this->tbg, NULL, NULL);
        SDL_RenderCopy(this->renderer, this->_ttxt, NULL, &this->pos);
        SDL_RenderPresent(this->renderer);
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
    SDL_FreeSurface(this->bg);
    this->spacman = IMG_Load("assets/pacman.png");
    this->tpacman = SDL_CreateTextureFromSurface(this->renderer, this->spacman);
    SDL_FreeSurface(this->spacman);
    this->snibbler = IMG_Load("assets/snake.png");
    this->tnibbler = SDL_CreateTextureFromSurface(this->renderer, this->snibbler);
    SDL_FreeSurface(this->snibbler);
}

void Sdl::setText()
{
    SDL_Color whiteColor = {255, 255, 255};

    this->getLists();
    this->_font = TTF_OpenFont("assets/arial.ttf", 65);
    this->_txt = TTF_RenderText_Blended(this->_font, "oui", whiteColor);
    pos.x = 130;
    pos.y = 115;
    pos.h = 50;
    pos.w = 50;
    this->_ttxt = SDL_CreateTextureFromSurface(this->renderer, this->_txt);
    SDL_FreeSurface(this->_txt);
}

void Sdl::getLists()
{
    for (int i = 0; i < this->_info.at(1).size(); i++)
        this->_listGames.append("-> " + this->_info.at(1).at(i) + "\n");
    for (int i = 0; i < this->_info.at(0).size(); i++)
        this->_listLibs.append("-> " + this->_info.at(0).at(i) + "\n");
    this->_listLibs.append("\n\nACTUAL LIBRARY : SDL");
    this->_name = "-> " + this->_info.at(2).at(0);
    this->_score = "-> 10000";
}

void Sdl::createWindow()
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
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
    this->setTexture();
    this->setText();
}

extern "C" AbstractGraph *create(std::vector<std::vector<std::string>> info)
{
    return new Sdl(info);
}

extern "C" void destroy(AbstractGraph *object)
{
    delete object;
}
