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
    while (SDL_PollEvent(&this->_events)) {
        if (this->_events.type == SDL_QUIT)
            return ("CLOSE");
        this->_actualTime = SDL_GetTicks();
        if (this->_actualTime - this->_lastTime > 200)
        {
            this->_lastTime = this->_actualTime;
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
        SDL_RenderCopy(this->renderer, this->tbg, NULL, NULL);
        SDL_RenderCopy(this->renderer, this->_ttxtGames, NULL, &this->posGames);
        SDL_RenderCopy(this->renderer, this->_ttxtLibs, NULL, &this->posLibs);
        SDL_RenderCopy(this->renderer, this->_ttxtName, NULL, &this->posName);
        SDL_RenderCopy(this->renderer, this->_ttxtScore, NULL, &this->posScore);
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
    this->_txtGames = TTF_RenderText_Blended_Wrapped(this->_font, this->_listGames.c_str(), whiteColor, 2000);
    posGames.x = 130;
    posGames.y = 115;
    posGames.h = 100;
    posGames.w = 800;
    this->_ttxtGames = SDL_CreateTextureFromSurface(this->renderer, this->_txtGames);
    SDL_FreeSurface(this->_txtGames);

    this->_txtLibs = TTF_RenderText_Blended_Wrapped(this->_font, this->_listLibs.c_str(), whiteColor, 2000);
    posLibs.x = 930;
    posLibs.y = 115;
    posLibs.h = 200;
    posLibs.w = 800;
    this->_ttxtLibs = SDL_CreateTextureFromSurface(this->renderer, this->_txtLibs);
    SDL_FreeSurface(this->_txtLibs);

    this->_txtName = TTF_RenderText_Blended_Wrapped(this->_font, this->_name.c_str(), whiteColor, 2000);
    posName.x = 930;
    posName.y = 660;
    posName.h = 40;
    posName.w = 200;
    this->_ttxtName = SDL_CreateTextureFromSurface(this->renderer, this->_txtName);
    SDL_FreeSurface(this->_txtName);

    this->_txtScore = TTF_RenderText_Blended_Wrapped(this->_font, this->_score.c_str(), whiteColor, 2000);
    posScore.x = 130;
    posScore.y = 660;
    posScore.h = 40;
    posScore.w = 200;
    this->_ttxtScore = SDL_CreateTextureFromSurface(this->renderer, this->_txtScore);
    SDL_FreeSurface(this->_txtScore);
}

void Sdl::getLists()
{
    for (int i = 0; i < this->_info.at(1).size(); i++)
        this->_listGames.append("->" + this->_info.at(1).at(i) + "\n");
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
        std::cout << "Could not create window Arcade." << std::endl;
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
