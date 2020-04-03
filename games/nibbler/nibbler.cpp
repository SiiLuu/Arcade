/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** nibbler
*/

#include "nibbler.hpp"

nibbler::nibbler()
{
    this->_state = game::state::RUNNING;
    this->init();
}

nibbler::~nibbler() {}

void nibbler::init()
{
    std::ifstream input("games/nibbler/nibblerMap.txt");

    this->_fruits = 0;
    this->_hp = 0;
    this->_score = 0;
    this->_tailSize = 4;
    this->_position.x = 10;
    this->_position.y = 12;
    for (std::string line; getline(input, line);)
        this->_map.push_back(line);
}

void nibbler::setFruit()
{
    this->_posfruit.x = rand() % 21;
    this->_posfruit.y = rand() % 21;
    if (this->_map.at(this->_posfruit.y).at(this->_posfruit.x) == '|')
        this->setFruit();
    if (this->_map.at(this->_posfruit.y).at(this->_posfruit.x) == 'E')
        this->setFruit();
    if (this->_map.at(this->_posfruit.y).at(this->_posfruit.x) == 'P')
        this->setFruit();
    this->_tailSize++;
    this->_score += 100;
    this->_map.at(this->_posfruit.y).at(this->_posfruit.x) = 'o';
}

void nibbler::setBodyPos()
{
    int x = 0;
    int y = 0;

    if (this->_posBody.size() >= this->_tailSize) {
        x = this->_posBody.at(this->_posBody.size() - this->_tailSize).x;
        y = this->_posBody.at(this->_posBody.size() - this->_tailSize).y;
        this->_map.at(y).at(x) = ' ';
    }
}

void nibbler::MoveForward()
{
    if (this->_map.at(this->_position.y - 1).at(this->_position.x) == 'o') {
        this->_posBody.push_back(this->_position);
        this->_position.y -= 1;
        setFruit();
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y + 1).at(this->_position.x) = 'E';
        setBodyPos();
    } else if (this->_map.at(this->_position.y - 1).at(this->_position.x) == ' ') {
        this->_posBody.push_back(this->_position);
        this->_position.y -= 1;
        this->_map.at(this->_position.y + 1).at(this->_position.x) = 'E';
        setBodyPos();
    } else if ((this->_map.at(this->_position.y - 1).at(this->_position.x) == 'E') || (this->_map.at(this->_position.y - 1).at(this->_position.x) == '|')) {
        this->_hp -= 1;
    }
    this->update();
}

void nibbler::MoveBackward()
{
    if (this->_map.at(this->_position.y + 1).at(this->_position.x) == 'o') {
        this->_posBody.push_back(this->_position);
        this->_position.y += 1;
        this->setFruit();
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y - 1).at(this->_position.x) = 'E';
        this->setBodyPos();
    } else if (this->_map.at(this->_position.y + 1).at(this->_position.x) == ' ') {
        this->_posBody.push_back(this->_position);
        this->_position.y += 1;
        this->_map.at(this->_position.y - 1).at(this->_position.x) = 'E';
        this->setBodyPos();
    } else if ((this->_map.at(this->_position.y + 1).at(this->_position.x) == 'E') ||
                (this->_map.at(this->_position.y + 1).at(this->_position.x) == '|'))
        this->_hp -= 1;
    this->update();
}

void nibbler::MoveLeft()
{
    if (this->_map.at(this->_position.y).at(this->_position.x - 1) == 'o') {
        this->_posBody.push_back(this->_position);
        this->_position.x -= 1;
        this->setFruit();
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y).at(this->_position.x + 1) = 'E';
        this->setBodyPos();
    } else if (this->_map.at(this->_position.y).at(this->_position.x - 1) == ' ') {
        this->_posBody.push_back(this->_position);
        this->_position.x -= 1;
        this->_map.at(this->_position.y).at(this->_position.x + 1) = 'E';
        this->setBodyPos();
    } else if ((this->_map.at(this->_position.y).at(this->_position.x - 1) == 'E') ||
                (this->_map.at(this->_position.y).at(this->_position.x - 1) == '|'))
        this->_hp -= 1;
    this->update();
}

void nibbler::MoveRight()
{
    if (this->_map.at(this->_position.y).at(this->_position.x + 1) == 'o') {
        this->_posBody.push_back(this->_position);
        this->_position.x += 1;
        this->setFruit();
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y).at(this->_position.x - 1) = 'E';
        this->setBodyPos();
    }
    if (this->_map.at(this->_position.y).at(this->_position.x + 1) == ' ') {
        this->_posBody.push_back(this->_position);
        this->_position.x += 1;
        this->_map.at(this->_position.y).at(this->_position.x - 1) = 'E';
        this->setBodyPos();
    } else if ((this->_map.at(this->_position.y).at(this->_position.x + 1) == 'E') ||
                (this->_map.at(this->_position.y).at(this->_position.x + 1) == '|'))
        this->_hp -= 1;
    this->update();
}

void nibbler::moveEnemy()
{

}

void nibbler::update()
{
    this->_map.at(this->_position.y).at(this->_position.x) = 'P';
    if (this->_hp < 0)
        this->_state = game::state::LOOSE;
}

std::string nibbler::getHighScore() const
{
    return (this->_highScore);
}

size_t nibbler::getScore() const
{
    return (this->_score);
}

game::state nibbler::getState() const
{
    return (this->_state);
}

std::vector<std::string> nibbler::getMap() const
{
    return (this->_map);
}

void nibbler::setState(game::state state) {}

extern "C" AbstractGame *create()
{
    return new nibbler();
}

extern "C" void destroy(AbstractGame *object)
{
    delete object;
}
