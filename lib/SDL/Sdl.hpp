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
        std::vector<std::vector<std::string>> _info;
        SDL_Window *_window;
        SDL_Renderer *renderer;
        SDL_Surface *bg;
        SDL_Texture *tbg;
        SDL_Texture *_mapBorderTexture;
        SDL_Surface *_mapBorderSprite;
        SDL_Texture *_player;
        SDL_Surface *_playerSprite;
        SDL_Texture *_ghost;
        SDL_Surface *_ghostSprite;
        SDL_Texture *_gGhost;
        SDL_Surface *_gGhostSprite;
        SDL_Texture *_food;
        SDL_Surface *_foodSprite;
        SDL_Texture *_bonus;
        SDL_Surface *_bonusSprite;
        SDL_Texture *_wall;
        SDL_Surface *_wallSprite;
        SDL_Event _events;
        size_t _actualTime;
        size_t _lastTime;

        TTF_Font *_font;
        SDL_Rect posGames;
        SDL_Rect posLibs;
        SDL_Rect posName;
        SDL_Rect posScore;
        SDL_Rect posScoreInGame;
        SDL_Rect posHighScore;
        SDL_Rect posHP;
        SDL_Rect rectMapBorder;
        SDL_Rect rectWall;
        SDL_Rect rectFood;
        SDL_Rect rectPlayer;
        SDL_Rect rectGhost;
        SDL_Rect rectGGhost;
        SDL_Rect rectBonus;
        SDL_Surface *_txtGames;
        SDL_Texture *_ttxtGames;
        SDL_Surface *_txtLibs;
        SDL_Texture *_ttxtLibs;
        SDL_Surface *_txtName;
        SDL_Texture *_ttxtName;
        SDL_Surface *_txtScore;
        SDL_Texture *_ttxtScore;
        SDL_Surface *_txtScoreInGame;
        SDL_Texture *_ttxtScoreInGame;
        SDL_Surface *_txtHP;
        SDL_Texture *_ttxtHP;
        SDL_Surface *_txtHighScoreInGame;
        SDL_Texture *_ttxtHighScoreInGame;
        std::string _listGames;
        std::string _listLibs;
        std::string _score;
        std::string _scoreInGame;
        std::string _highScore;
        std::string _HP;
        std::string _name;
        std::string _actualScore;
        std::vector<SDL_Rect> _mapBorder;
        std::vector<SDL_Rect> _mapWall;
        std::vector<SDL_Rect> _mapFood;
        std::vector<SDL_Rect> _mapPlayer;
        std::vector<SDL_Rect> _mapGhost;
        std::vector<SDL_Rect> _mapGGhost;
        std::vector<SDL_Rect> _mapBonus;
        void setTexture();
        void setMaptexture(std::vector<std::vector<std::string>> infos);
        void drawMap();
        void setText();
        void getLists();
        void highScore(std::vector<std::vector<std::string>> infos);
        void setRectSprites();
        void destroyTextures();
        void clearVector();
};

#endif /* !SDL_HPP_ */
