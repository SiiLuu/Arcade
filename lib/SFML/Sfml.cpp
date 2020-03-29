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
        if (this->_clock.getElapsedTime().asMilliseconds() > 200) {
            this->_clock.restart();
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
                    return ("");
            }
        }
    }
    return ("");
}

void Sfml::displayGame(std::string game)
{
    this->_window.clear();
    if (game.find("pacman") != std::string::npos) {
        this->_window.draw(this->_pacmanSprite);
    }
    else if (game.find("nibbler") != std::string::npos) {
        this->_window.draw(this->_nibblerSprite);
    }
    this->_window.display();
}

void Sfml::displayMenu(std::vector<std::vector<std::string>> info)
{
    this->_info = info;
    this->setText();
    this->_window.clear();
    this->_window.draw(this->_backgroundSprite);
    this->_window.draw(this->_txtGames);
    this->_window.draw(this->_txtLibs);
    this->_window.draw(this->_txtName);
    this->_window.draw(this->_txtScore);
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

void Sfml::setText()
{
    this->getLists();
    this->_font.loadFromFile("assets/arial.ttf");
    this->_txtGames.setFont(this->_font);
    this->_txtGames.setString(this->_listGames);
    this->_txtGames.setCharacterSize(25);
    this->_txtGames.setStyle(sf::Text::Bold);
    this->_txtGames.setPosition(130, 115);

    this->_txtLibs.setFont(this->_font);
    this->_txtLibs.setString(this->_listLibs);
    this->_txtLibs.setCharacterSize(25);
    this->_txtLibs.setStyle(sf::Text::Bold);
    this->_txtLibs.setPosition(930, 115);

    this->_txtName.setFont(this->_font);
    this->_txtName.setString(this->_name);
    this->_txtName.setCharacterSize(25);
    this->_txtName.setStyle(sf::Text::Bold);
    this->_txtName.setPosition(930, 660);

    this->_txtScore.setFont(this->_font);
    this->_txtScore.setString(this->_score);
    this->_txtScore.setCharacterSize(25);
    this->_txtScore.setStyle(sf::Text::Bold);
    this->_txtScore.setPosition(130, 660);
}

void Sfml::getLists()
{
    if (this->_listGames.empty() == true)
        for (int i = 0; i < this->_info.at(1).size(); i++)
            this->_listGames.append("-> " + this->_info.at(1).at(i) + "\n");
    if (this->_listLibs.empty() == true) {
        for (int i = 0; i < this->_info.at(0).size(); i++)
            this->_listLibs.append("-> " + this->_info.at(0).at(i) + "\n");
        this->_listLibs.append("\n\nACTUAL LIBRARY : SFML");
    }
    this->_name = "-> " + this->_info.at(2).at(0);
    this->_score = "-> 10000";
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
