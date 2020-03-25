/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** sfml functions
*/

#include "Sfml.hpp"

Sfml::Sfml()
{
    std::cout << "SFML Created" << std::endl;
    this->createWindow();
    this->display();
}

Sfml::~Sfml()
{
    std::cout << "SFML Destroyed" << std::endl;
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

void Sfml::display()
{
    this->_window.clear();
    this->_window.draw(this->_backgroundSprite);
    this->_window.display();
}

void Sfml::createWindow()
{
    this->_window.create(sf::VideoMode(800, 600), "My window");
    this->_window.setFramerateLimit(60);
    this->_background.loadFromFile("foret.jpg");
    this->_backgroundSprite.setTexture(this->_background);
}

extern "C" AbstractGraph *create()
{
    return new Sfml();
}

extern "C" void destroy(AbstractGraph *object)
{
    delete object;
}
