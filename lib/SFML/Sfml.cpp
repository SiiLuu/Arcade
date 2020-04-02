/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** sfml functions
*/

#include "Sfml.hpp"

Sfml::Sfml(std::vector<std::vector<std::string>> info)
{
    this->_info = info;
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
                case sf::Keyboard::Z:
                    return ("Z");
                case sf::Keyboard::Q:
                    return ("Q");
                case sf::Keyboard::S:
                    return ("S");
                case sf::Keyboard::D:
                    return ("D");
                case sf::Keyboard::Escape:
                    return ("ESCAPE");
                default:
                    return ("");
            }
        }
    }
    return ("");
}

void Sfml::drawMap()
{
    for (size_t k = 0; k < this->_mapBorder.size(); k++)
        this->_window.draw(this->_mapBorder.at(k));
    for (size_t k = 0; k < this->_mapFood.size(); k++)
        this->_window.draw(this->_mapFood.at(k));
    for (size_t k = 0; k < this->_mapGhost.size(); k++)
        this->_window.draw(this->_mapGhost.at(k));
    for (size_t k = 0; k < this->_mapPlayer.size(); k++)
        this->_window.draw(this->_mapPlayer.at(k));
    for (size_t k = 0; k < this->_mapGGhost.size(); k++)
        this->_window.draw(this->_mapGGhost.at(k));
    for (size_t k = 0; k < this->_mapBonus.size(); k++)
        this->_window.draw(this->_mapBonus.at(k));
    this->_window.draw(this->_txtScoreInGame);
    this->_window.draw(this->_txtHighScoreInGame);
}

void Sfml::setMaptexture(std::vector<std::vector<std::string>> infos)
{
    this->_mapBorder.clear();
    this->_mapGhost.clear();
    this->_mapGGhost.clear();
    this->_mapBonus.clear();
    this->_mapFood.clear();
    this->_mapPlayer.clear();
    for (size_t k = 0; k < infos.at(0).size(); k++) {
        for (size_t i = 0; i < infos.at(0).at(k).size(); i++) {
            if (infos.at(0).at(k).at(i) == '|') {
                this->_mapBorderSprite.setPosition(450 + i * 30, k * 40);
                this->_mapBorder.push_back(this->_mapBorderSprite);
            }
            else if (infos.at(0).at(k).at(i) == 'o') {
                this->_foodSprite.setPosition(460 + i * 30, 10 + k * 40);
                this->_mapFood.push_back(this->_foodSprite);
            }
            else if (infos.at(0).at(k).at(i) == 'E') {
                this->_ghostSprite.setPosition(450 + i * 30, k * 40);
                this->_mapGhost.push_back(this->_ghostSprite);
            }
            else if (infos.at(0).at(k).at(i) == 'P') {
                this->_playerSprite.setPosition(450 + i * 30, 10 + k * 40);
                this->_mapPlayer.push_back(this->_playerSprite);
            }
            else if (infos.at(0).at(k).at(i) == 'A') {
                this->_gGhostSprite.setPosition(450 + i * 30, k * 40);
                this->_mapGGhost.push_back(this->_gGhostSprite);
            }
            else if (infos.at(0).at(k).at(i) == 'O') {
                this->_bonusSprite.setPosition(450 + i * 30, k * 40);
                this->_mapBonus.push_back(this->_bonusSprite);
            }
        }
    }
    this->_txtScoreInGame.setString("SCORE : " + infos.at(1).at(0));
    this->_txtHighScoreInGame.setString("HIGH SCORE : " + infos.at(1).at(0));
}

void Sfml::display(std::vector<std::vector<std::string>> infos, int scene)
{
    this->_window.clear();
    if (scene == 1) {
        this->_window.draw(this->_backgroundSprite);
        this->_window.draw(this->_txtGames);
        this->_window.draw(this->_txtLibs);
        this->_window.draw(this->_txtName);
        this->_window.draw(this->_txtScore);
    }
    else if (scene == 2) {
            this->setMaptexture(infos);
            this->drawMap();
    }
    this->_window.display();
}

void Sfml::setTexture()
{
    this->_background.loadFromFile("assets/arcade.jpg");
    this->_backgroundSprite.setTexture(this->_background);
    this->_player.loadFromFile("assets/player3.png");
    this->_playerSprite.setTexture(this->_player);
    this->_playerSprite.setScale(0.1, 0.1);
    this->_food.loadFromFile("assets/food.png");
    this->_foodSprite.setTexture(this->_food);
    this->_foodSprite.setScale(0.05, 0.05);
    this->_ghost.loadFromFile("assets/enemy2.png");
    this->_ghostSprite.setTexture(this->_ghost);
    this->_ghostSprite.setScale(0.075, 0.075);
    this->_gGhost.loadFromFile("assets/enemy.png");
    this->_gGhostSprite.setTexture(this->_gGhost);
    this->_gGhostSprite.setScale(0.075, 0.075);
    this->_bonus.loadFromFile("assets/bonus.png");
    this->_bonusSprite.setTexture(this->_bonus);
    this->_bonusSprite.setScale(0.05, 0.05);
    this->_mapBorderTexture.loadFromFile("assets/carre.png");
    this->_mapBorderSprite.setTexture(this->_mapBorderTexture);
    this->_mapBorderSprite.setScale(0.075, 0.1);
}

void Sfml::setText()
{
    this->getLists();
    this->_font.loadFromFile("assets/arial.ttf");
    this->_txtGames.setFont(this->_font);
    this->_txtGames.setString(this->_listGames);
    this->_txtGames.setCharacterSize(25);
    this->_txtGames.setPosition(130, 115);

    this->_txtLibs.setFont(this->_font);
    this->_txtLibs.setString(this->_listLibs);
    this->_txtLibs.setCharacterSize(25);
    this->_txtLibs.setPosition(930, 115);

    this->_txtName.setFont(this->_font);
    this->_txtName.setString(this->_name);
    this->_txtName.setCharacterSize(25);
    this->_txtName.setPosition(930, 660);

    this->_txtScore.setFont(this->_font);
    this->_txtScore.setString(this->_score);
    this->_txtScore.setCharacterSize(25);
    this->_txtScore.setPosition(130, 660);

    this->_txtScoreInGame.setFont(this->_font);
    this->_txtScoreInGame.setCharacterSize(25);
    this->_txtScoreInGame.setPosition(220, 100);

    this->_txtHighScoreInGame.setFont(this->_font);
    this->_txtHighScoreInGame.setCharacterSize(25);
    this->_txtHighScoreInGame.setPosition(150, 200);
}

void Sfml::getLists()
{
    for (int i = 0; i < this->_info.at(1).size(); i++)
        this->_listGames.append("-> " + this->_info.at(1).at(i) + "\n");
    for (int i = 0; i < this->_info.at(0).size(); i++)
        this->_listLibs.append("-> " + this->_info.at(0).at(i) + "\n");
    this->_listLibs.append("\n\nACTUAL LIBRARY : SFML");
    this->_name = "-> " + this->_info.at(2).at(0);
    for (int i = 1; i < this->_info.at(2).size(); i++)
        this->_score.append(("-> " + this->_info.at(2).at(i) + "\n"));
}

void Sfml::createWindow()
{
    this->_window.create(sf::VideoMode(1600, 900), "Arcade");
    this->_window.setFramerateLimit(60);
    this->setTexture();
    this->setText();
}

extern "C" AbstractGraph *create(std::vector<std::vector<std::string>> name)
{
    return new Sfml(name);
}

extern "C" void destroy(AbstractGraph *object)
{
    delete object;
}
