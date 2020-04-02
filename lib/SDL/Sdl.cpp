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
    this->destroyTextures();
    SDL_DestroyTexture(this->_mapBorderTexture);
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->_window);
    TTF_CloseFont(this->_font);
    TTF_Quit();
    SDL_Quit();
}

void Sdl::destroyTextures()
{
    SDL_DestroyTexture(this->tbg);
    SDL_DestroyTexture(this->_ttxtScore);
    SDL_DestroyTexture(this->_ttxtGames);
    SDL_DestroyTexture(this->_ttxtLibs);
    SDL_DestroyTexture(this->_ttxtName);
    SDL_DestroyTexture(this->_mapBorderTexture);
    SDL_DestroyTexture(this->_player);
    SDL_DestroyTexture(this->_ghost);
    SDL_DestroyTexture(this->_gGhost);
    SDL_DestroyTexture(this->_food);
    SDL_DestroyTexture(this->_bonus);
    SDL_DestroyTexture(this->_ttxtGames);
    SDL_DestroyTexture(this->_ttxtLibs);
    SDL_DestroyTexture(this->_ttxtName);
    SDL_DestroyTexture(this->_ttxtScore);
    //SDL_DestroyTexture(this->_ttxtScoreInGame);
    //SDL_DestroyTexture(this->_ttxtHighScoreInGame);
}

std::string Sdl::registerEvents()
{
    while (SDL_PollEvent(&this->_events)) {
        if (this->_events.type == SDL_QUIT)
            return ("CLOSE");
        this->_actualTime = SDL_GetTicks();
        if (this->_actualTime - this->_lastTime > 150)
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
                case SDLK_z:
                    return ("Z");
                case SDLK_q:
                    return ("Q");
                case SDLK_s:
                    return ("S");
                case SDLK_d:
                    return ("D");
                default:
                    return ("");
            }
        }
    }
    return ("");
}

void Sdl::drawMap()
{
    for (size_t k = 0; k < this->_mapBorder.size(); k++)
        SDL_RenderCopy(this->renderer, this->_mapBorderTexture, NULL, &this->_mapBorder.at(k));
    for (size_t k = 0; k < this->_mapPlayer.size(); k++)
        SDL_RenderCopy(this->renderer, this->_player, NULL, &this->_mapPlayer.at(k));
    for (size_t k = 0; k < this->_mapGhost.size(); k++)
        SDL_RenderCopy(this->renderer, this->_ghost, NULL, &this->_mapGhost.at(k));
    for (size_t k = 0; k < this->_mapGGhost.size(); k++)
        SDL_RenderCopy(this->renderer, this->_gGhost, NULL, &this->_mapGGhost.at(k));
    for (size_t k = 0; k < this->_mapFood.size(); k++)
        SDL_RenderCopy(this->renderer, this->_food, NULL, &this->_mapFood.at(k));
    for (size_t k = 0; k < this->_mapBonus.size(); k++)
        SDL_RenderCopy(this->renderer, this->_bonus, NULL, &this->_mapBonus.at(k));
    SDL_RenderCopy(this->renderer, this->_ttxtScoreInGame, NULL, &this->posScoreInGame);
    //SDL_DestroyTexture(this->_ttxtScoreInGame);
    SDL_RenderCopy(this->renderer, this->_ttxtHighScoreInGame, NULL, &this->posHighScore);
}

void Sdl::setMaptexture(std::vector<std::vector<std::string>> infos)
{
    this->_mapBorder.clear();
    this->_mapGhost.clear();
    this->_mapGGhost.clear();
    this->_mapBonus.clear();
    this->_mapFood.clear();
    this->_mapPlayer.clear();
    for (size_t k = 0; k < infos.at(0).size(); k++) {
        for (size_t i = 0; i < infos.at(0).at(k).size(); i++) {
            if (infos.at(0).at(k).at(i) == '|') {
                this->rectMapBorder.x = 450 + i * 30;
                this->rectMapBorder.y = k * 40;
                this->_mapBorder.push_back(this->rectMapBorder);
            }
            else if (infos.at(0).at(k).at(i) == 'o') {
                this->rectFood.x = 455 + i * 30;
                this->rectFood.y = 10 + k * 40;
                this->_mapFood.push_back(this->rectFood);
            }
            else if (infos.at(0).at(k).at(i) == 'E') {
                this->rectGhost.x = 450 + i * 30;
                this->rectGhost.y = 10 + k * 40;
                this->_mapGhost.push_back(this->rectGhost);
            }
            else if (infos.at(0).at(k).at(i) == 'P') {
                this->rectPlayer.x = 450 + i * 30;
                this->rectPlayer.y = 10 + k * 40;
                this->_mapPlayer.push_back(this->rectPlayer);
            }
            else if (infos.at(0).at(k).at(i) == 'A') {
                this->rectGGhost.x = 450 + i * 30;
                this->rectGGhost.y = 10 + k * 40;
                this->_mapGGhost.push_back(this->rectGGhost);
            }
            else if (infos.at(0).at(k).at(i) == 'O') {
                this->rectBonus.x = 455 + i * 30;
                this->rectBonus.y = 10 + k * 40;
                this->_mapBonus.push_back(this->rectBonus);
            }
        }
    }
    this->_scoreInGame = "SCORE : " + infos.at(1).at(0);
    this->_txtScoreInGame = TTF_RenderText_Blended_Wrapped(this->_font, this->_scoreInGame.c_str(), {255,255,255}, 2000);
    this->_ttxtScoreInGame = SDL_CreateTextureFromSurface(this->renderer, this->_txtScoreInGame);
    SDL_FreeSurface(this->_txtScoreInGame);
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
        this->setMaptexture(infos);
        this->drawMap();
    }
    SDL_RenderPresent(renderer);
}

void Sdl::setTexture()
{
    this->bg = IMG_Load("assets/arcade.jpg");
    this->tbg = SDL_CreateTextureFromSurface(this->renderer, this->bg);
    SDL_FreeSurface(this->bg);
    this->_playerSprite = IMG_Load("assets/player3.png");
    this->_player = SDL_CreateTextureFromSurface(this->renderer, this->_playerSprite);
    SDL_FreeSurface(this->_playerSprite);
    this->_ghostSprite = IMG_Load("assets/enemy2.png");
    this->_ghost = SDL_CreateTextureFromSurface(this->renderer, this->_ghostSprite);
    SDL_FreeSurface(this->_ghostSprite);
    this->_gGhostSprite = IMG_Load("assets/enemy.png");
    this->_gGhost = SDL_CreateTextureFromSurface(this->renderer, this->_gGhostSprite);
    SDL_FreeSurface(this->_gGhostSprite);
    this->_foodSprite = IMG_Load("assets/food.png");
    this->_food = SDL_CreateTextureFromSurface(this->renderer, this->_foodSprite);
    SDL_FreeSurface(this->_foodSprite);
    this->_bonusSprite = IMG_Load("assets/bonus.png");
    this->_bonus = SDL_CreateTextureFromSurface(this->renderer, this->_bonusSprite);
    SDL_FreeSurface(this->_bonusSprite);
    this->_mapBorderSprite = IMG_Load("assets/carre.png");
    this->_mapBorderTexture = SDL_CreateTextureFromSurface(this->renderer, this->_mapBorderSprite);
    SDL_FreeSurface(this->_mapBorderSprite);
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
    posScore.h = 90;
    posScore.w = 600;
    this->_ttxtScore = SDL_CreateTextureFromSurface(this->renderer, this->_txtScore);
    SDL_FreeSurface(this->_txtScore);
    this->_txtScoreInGame = TTF_RenderText_Blended_Wrapped(this->_font, this->_scoreInGame.c_str(), whiteColor, 2000);
    posScoreInGame.x = 220;
    posScoreInGame.y = 100;
    posScoreInGame.h = 20;
    posScoreInGame.w = 100;
    this->_ttxtScoreInGame = SDL_CreateTextureFromSurface(this->renderer, this->_txtScoreInGame);
    SDL_FreeSurface(this->_txtScoreInGame);
    this->_txtHighScoreInGame = TTF_RenderText_Blended_Wrapped(this->_font, this->_highScore.c_str(), whiteColor, 2000);
    posHighScore.x = 150;
    posHighScore.y = 200;
    posHighScore.h = 20;
    posHighScore.w = 100;
    this->_ttxtHighScoreInGame = SDL_CreateTextureFromSurface(this->renderer, this->_txtHighScoreInGame);
    SDL_FreeSurface(this->_txtHighScoreInGame);
}

void Sdl::setRect()
{
    this->rectMapBorder.h = 40;
    this->rectMapBorder.w = 30;
    this->rectBonus.h = 20;
    this->rectBonus.w = 20;
    this->rectFood.h = 20;
    this->rectFood.w = 20;
    this->rectPlayer.h = 25;
    this->rectPlayer.w = 25;
    this->rectGGhost.h = 20;
    this->rectGGhost.w = 20;
    this->rectGhost.h = 20;
    this->rectGhost.w = 20;

}

void Sdl::getLists()
{
    for (int i = 0; i < this->_info.at(1).size(); i++)
        this->_listGames.append("-> " + this->_info.at(1).at(i) + "\n");
    for (int i = 0; i < this->_info.at(0).size(); i++)
        this->_listLibs.append("-> " + this->_info.at(0).at(i) + "\n");
    this->_listLibs.append("\n\nACTUAL LIBRARY : SDL");
    this->_name = "-> " + this->_info.at(2).at(0);
    for (int i = 1; i < this->_info.at(2).size(); i++)
        this->_score.append(("-> " + this->_info.at(2).at(i) + "\n"));}

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
        SDL_WINDOW_SHOWN);
    if (this->_window == NULL)
        std::cout << "Could not create window Arcade." << std::endl;
    this->renderer = SDL_CreateRenderer(this->_window, -1, SDL_RENDERER_ACCELERATED);
    this->setTexture();
    this->setText();
    this->setRect();
}

extern "C" AbstractGraph *create(std::vector<std::vector<std::string>> info)
{
    return new Sdl(info);
}

extern "C" void destroy(AbstractGraph *object)
{
    delete object;
}
