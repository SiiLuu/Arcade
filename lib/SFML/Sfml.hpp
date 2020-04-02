/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** sfml class
*/
#include "../AGraph/AbstractGraph.hpp"

#ifndef SFML_HPP_
#define SFML_HPP_
class Sfml : public AbstractGraph
{
    public:
        Sfml(std::vector<std::vector<std::string>>);
        ~Sfml();

        void createWindow();
        void display(std::vector<std::vector<std::string>>, int);
        std::string registerEvents();

    private:
        std::vector<std::vector<std::string>> _info;
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Texture _background;
        sf::Sprite _backgroundSprite;
        sf::Texture _mapBorderTexture;
        sf::Sprite _mapBorderSprite;
        sf::Texture _player;
        sf::Sprite _playerSprite;
        sf::Texture _ghost;
        sf::Sprite _ghostSprite;
        sf::Texture _gGhost;
        sf::Sprite _gGhostSprite;
        sf::Texture _food;
        sf::Sprite _foodSprite;
        sf::Texture _bonus;
        sf::Sprite _bonusSprite;
        sf::Clock _clock;
        bool _setTexture;

        sf::Font _font;
        sf::Text _txtGames;
        sf::Text _txtLibs;
        sf::Text _txtName;
        sf::Text _txtScore;
        std::string _listGames;
        std::string _listLibs;
        std::string _score;
        std::string _name;
        std::vector<sf::Sprite> _mapBorder;
        std::vector<sf::Sprite> _mapFood;
        std::vector<sf::Sprite> _mapPlayer;
        std::vector<sf::Sprite> _mapGhost;
        std::vector<sf::Sprite> _mapGGhost;
        std::vector<sf::Sprite> _mapBonus;
        void setTexture();
        void setMaptexture(std::vector<std::vector<std::string>> infos);
        void setText();
        void getLists();
        void drawMap();
};

#endif /* !SFML_HPP_ */
