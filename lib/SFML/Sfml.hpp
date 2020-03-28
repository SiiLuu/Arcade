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
        Sfml();
        ~Sfml();

        void createWindow();
        void displayGame(std::string game);
        void displayMenu(std::vector<std::vector<std::string>>);
        std::string registerEvents();

    private:
        std::vector<std::vector<std::string>> _info;
        sf::Font _font;
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Texture _background;
        sf::Sprite _backgroundSprite;
        sf::Texture _pacman;
        sf::Sprite _pacmanSprite;
        sf::Texture _nibbler;
        sf::Sprite _nibblerSprite;
        sf::Clock _clock;

        sf::Text _txtGames;
        sf::Text _txtLibs;
        sf::Text _txtName;
        sf::Text _txtScore;
        std::string _listGames;
        std::string _listLibs;
        std::string _score;
        std::string _name;
        void setTexture();
        void setText();
        void getLists();

};

#endif /* !SFML_HPP_ */
