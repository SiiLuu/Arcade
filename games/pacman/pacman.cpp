/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** pacman class
*/

#include "pacman.hpp"

Pacman::Pacman()
{
    this->_hp = 3;
    std::cout << "PACMAN -> created" << std::endl;
}

Pacman::~Pacman()
{
    std::cout << "PACMAN -> Game destroyed" << std::endl;
}

void Pacman::MoveForward()
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

void Pacman::MoveBackward()
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

void Pacman::MoveLeft()
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

void Pacman::MoveRight()
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

void Pacman::moveEnemy()
{
    std::cout << "NIBBLER -> enemy mooved" << std::endl;
}

void Pacman::update()
{

}

void Pacman::init()
{

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

void Pacman::setState()
{
}

extern "C" AbstractGame *create()
{
    return new Pacman();
}

extern "C" void destroy(AbstractGame *object)
{
    delete object;
}
