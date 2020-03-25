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

        void getCh();
        void createWindow();
        void display();

    private:
        sf::RenderWindow _window;
        sf::Texture _background;
        sf::Sprite _backgroundSprite;
        void gameLoop();
};

#endif /* !SFML_HPP_ */
