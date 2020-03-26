/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** sfml functions
*/

#include "Sfml.hpp"

Sfml::Sfml()
{
    this->createWindow();
}

Sfml::~Sfml()
{
}

std::string Sfml::registerEvents()
{
    while (this->_window.pollEvent(this->_event))
    {
        switch (this->_event.type) {
            case sf::Event::Closed:
                this->_window.close();
                return ("CLOSE");
            default:
                break;
        }
        switch (this->_event.key.code) {
            case sf::Keyboard::P:
                return ("P");
            case sf::Keyboard::N:
                return ("N");
            case sf::Keyboard::Num2:
                return ("2");
            case sf::Keyboard::Num3:
                return ("3");
            case sf::Keyboard::Z:
                return ("Z");
            case sf::Keyboard::S:
                return ("S");
            case sf::Keyboard::Q:
                return ("Q");
            case sf::Keyboard::D:
                return ("D");
            default:
                break;
        }
    }
    return ("");
}

void Sfml::displayGame(std::string game)
{
    this->_window.clear();
    this->_window.draw(this->_pacmanSprite);
    this->_window.display();
}

void Sfml::displayMenu()
{
    this->_window.clear();
    this->_window.draw(this->_backgroundSprite);
    this->_window.display();
}

void Sfml::setTexture()
{
    this->_background.loadFromFile("assets/arcade.jpg");
    this->_backgroundSprite.setTexture(this->_background);
    this->_pacman.loadFromFile("assets/pacman.png");
    this->_pacmanSprite.setTexture(this->_pacman);
}

void Sfml::createWindow()
{
    this->_window.create(sf::VideoMode(1600, 900), "Arcade");
    this->_window.setFramerateLimit(60);
    this->setTexture();
}

extern "C" AbstractGraph *create()
{
    return new Sfml();
}

extern "C" void destroy(AbstractGraph *object)
{
    delete object;
}
