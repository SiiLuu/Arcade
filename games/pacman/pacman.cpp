/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** pacman class
*/

#include "pacman.hpp"

Pacman::Pacman()
{
    std::cout << "PACMAN" << std::endl;
    this->_position.x = 10;
    this->_position.y = 14;
    this->_score = 0;
    this->_hp = 3;
    this->_state = game::state::RUNNING;
    this->init();
}

Pacman::~Pacman() {}

void Pacman::init()
{
    std::ifstream input("games/pacman/pacmanMap.txt");

    for (std::string line; getline(input, line);) {
        this->_map.push_back(line);
    }
}

void Pacman::MoveForward()
{
    if (this->_map.at(this->_position.y - 1).at(this->_position.x) == 'o') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_score += 10;
        this->_position.y -= 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->update();
    } else if (this->_map.at(this->_position.y - 1).at(this->_position.x) == ' ') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.y -= 1;
        this->update();
    }
    else if (this->_map.at(this->_position.y - 1).at(this->_position.x) == 'E') {
        this->_hp -= 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.x = 10;
        this->_position.y = 14;
    }
    this->update();
}

void Pacman::MoveBackward()
{
    if (this->_map.at(this->_position.y + 1).at(this->_position.x) == 'o') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_score += 10;
        this->_position.y += 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->update();
    } else if (this->_map.at(this->_position.y + 1).at(this->_position.x) == ' ') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.y += 1;
        this->update();
    }
    else if (this->_map.at(this->_position.y - 1).at(this->_position.x) == 'E') {
        this->_hp -= 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.x = 10;
        this->_position.y = 14;
    }
    this->update();
}

void Pacman::MoveLeft()
{
    if (this->_position.y == 9 && this->_position.x == 0) {
        this->_map.at(9).at(0) = ' ';
        this->_position.x = 20;
    } else if (this->_map.at(this->_position.y).at(this->_position.x - 1) == 'o') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_score += 10;
        this->_position.x -= 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->update();
    } else if (this->_map.at(this->_position.y).at(this->_position.x - 1) == ' ') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.x -= 1;
    }
    else if (this->_map.at(this->_position.y).at(this->_position.x - 1) == 'E') {
        this->_hp -= 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.x = 10;
        this->_position.y = 14;
    }
    this->update();
}

void Pacman::MoveRight()
{
    if (this->_position.y == 9 && this->_position.x == 20) {
        this->_map.at(9).at(20) = ' ';
        this->_position.x = 0;
    } else if (this->_map.at(this->_position.y).at(this->_position.x + 1) == 'o') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_score += 10;
        this->_position.x += 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
    } else if (this->_map.at(this->_position.y).at(this->_position.x + 1) == ' ') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.x += 1;
    } else if (this->_map.at(this->_position.y).at(this->_position.x + 1) == 'E') {
        this->_hp -= 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.x = 10;
        this->_position.y = 14;
    }
    this->update();
}

void Pacman::moveEnemy()
{
    std::cout << "NIBBLER -> enemy mooved" << std::endl;
}

void Pacman::update()
{
    this->_map.at(this->_position.y).at(this->_position.x) = 'P';
    if (this->_hp < 0)
        this->_state = game::state::LOOSE;
}

size_t Pacman::getScore() const
{
    return (this->_score);
}

game::state Pacman::getState() const
{
    return (this->_state);
}

std::vector<std::string> Pacman::getMap() const
{
    return (this->_map);
}

void Pacman::setState(game::state state)
{
    this->_state = state;
}

extern "C" AbstractGame *create()
{
    return new Pacman();
}

extern "C" void destroy(AbstractGame *object)
{
    delete object;
}
