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
    this->getCh();
    this->display();
}

Sfml::~Sfml()
{
    std::cout << "SFML Destroyed" << std::endl;
}

void Sfml::checkEvents()
{

}

void Sfml::display()
{
    this->checkEvents();
    this->_window.clear();
    this->_window.draw(this->_backgroundSprite);
    this->_window.display();
}

void Sfml::getCh()
{
    std::cout << "SFML -> Gestion des inputs" << std::endl;
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
