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

Sfml::~Sfml() {}

std::string Sfml::registerEvents()
{
    while (this->_window.pollEvent(this->_event))
    {
        if (this->_event.type == sf::Event::Closed)
                return ("CLOSE");
        switch (this->_event.key.code) {
            case sf::Keyboard::Left:
                return ("KEYLEFT");
            case sf::Keyboard::Right:
                return ("KEYRIGHT");
            case sf::Keyboard::Down:
                return ("KEYDOWN");
            case sf::Keyboard::Up:
                return ("KEYUP");
            case sf::Keyboard::Escape:
                return ("ESCAPE");
            default:
                break;
        }
    }
    return ("");
}

void Sfml::displayGame(std::string game)
{
    this->_window.clear();
    if (!game.compare("PACMAN")) {
        this->_window.draw(this->_pacmanSprite);
    }
    else if (!game.compare("NIBBLER")) {
        this->_window.draw(this->_nibblerSprite);
    }
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
    this->_nibbler.loadFromFile("assets/snake.png");
    this->_nibblerSprite.setTexture(this->_nibbler);
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
