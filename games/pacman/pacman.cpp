/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** pacman class
*/

#include "pacman.hpp"

Pacman::Pacman()
{
    this->_hp = 1;
    std::cout << "PACMAN -> created" << std::endl;
}

Pacman::~Pacman()
{
    std::cout << "PACMAN -> Game destroyed" << std::endl;
}

void Pacman::MoveForward()
{
    if (this->_map[this->_position.y + 1][this->_position.x] == 'o') {
        this->_position.y += 1;
        this->_map[this->_position.y][this->_posotion.x] = " ";
    } else if (this->_map[this->_position.y + 1][this->_position.x] == " ")
        this->_position.y += 1;
    else if (this->_map[this->_position.y + 1][this->_position.x] == 'E') {
        this->_hp = 0;
        game::state::LOOSE;
    }
}

void Pacman::MoveBackward()
{
    std::cout << "PACMAN -> player go to the back" << std::endl;
}

void Pacman::MoveLeft()
{
    std::cout << "PACMAN -> player go to the left" << std::endl;
}

void Pacman::MoveRight()
{
    std::cout << "PACMAN -> player go to the right" << std::endl;
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
