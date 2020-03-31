/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** nibbler
*/

#include "nibbler.hpp"

nibbler::nibbler()
{
    this->init();
    std::cout << "NIBBLER" << std::endl;
}

nibbler::~nibbler()
{
}

void nibbler::init()
{
    std::ifstream input("games/nibbler/nibblerMap.txt");

    for (std::string line; getline(input, line);)
        this->_map.push_back(line);
}

void nibbler::MoveForward()
{
    if (this->_map.at(this->_position.y + 1).at(this->_position.x) == 'o') {
        this->_position.y += 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
    } else if (this->_map.at(this->_position.y + 1).at(this->_position.x) == ' ')
        this->_position.y += 1;
    else if (this->_map.at(this->_position.y + 1).at(this->_position.x) == 'E') {
        this->_hp -= 1;
        if (this->_hp == -1)
            this->_state = game::state::LOOSE;
    }
}

void nibbler::MoveBackward()
{
    if (this->_map.at(this->_position.y - 1).at(this->_position.x) == 'o') {
        this->_position.y -= 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
    } else if (this->_map.at(this->_position.y - 1).at(this->_position.x) == ' ')
        this->_position.y -= 1;
    else if (this->_map.at(this->_position.y - 1).at(this->_position.x) == 'E') {
        this->_hp -= 1;
        if (this->_hp == -1)
            this->_state = game::state::LOOSE;
    }
}

void nibbler::MoveLeft()
{
    if (this->_map.at(this->_position.y).at(this->_position.x - 1) == 'o') {
        this->_position.x -= 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
    } else if (this->_map.at(this->_position.y).at(this->_position.x - 1) == ' ')
        this->_position.x -= 1;
    else if (this->_map.at(this->_position.y).at(this->_position.x - 1) == 'E') {
        this->_hp -= 1;
        if (this->_hp == -1)
            this->_state = game::state::LOOSE;
    }
}

void nibbler::MoveRight()
{
    if (this->_map.at(this->_position.y).at(this->_position.x + 1) == 'o') {
        this->_position.x += 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
    } else if (this->_map.at(this->_position.y).at(this->_position.x + 1) == ' ')
        this->_position.x += 1;
    else if (this->_map.at(this->_position.y).at(this->_position.x + 1) == 'E') {
        this->_hp -= 1;
        if (this->_hp == -1)
            this->_state = game::state::LOOSE;
    }
}

void nibbler::moveEnemy()
{
    std::cout << "NIBBLER -> enemy mooved" << std::endl;
}

void nibbler::update()
{
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
