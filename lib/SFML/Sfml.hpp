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
        void displayMenu();
        std::string registerEvents();

    private:
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Texture _background;
        sf::Sprite _backgroundSprite;
        sf::Texture _pacman;
        sf::Sprite _pacmanSprite;
        void setTexture();
};

#endif /* !SFML_HPP_ */
