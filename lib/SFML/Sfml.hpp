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
        std::string display();

    private:
        sf::RenderWindow _window;
        sf::Event _event;
        sf::Texture _background;
        sf::Sprite _backgroundSprite;
        std::string checkEvents();
};

#endif /* !SFML_HPP_ */
