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

    this->_hp = 0;
    int pos = 11;
    _position.x = 10;
    _position.y = 11;
    for (std::string line; getline(input, line);)
        this->_map.push_back(line);
    for (int i = 0; i < 4; i++) {
        this->_body.push_back("E");
        this->_posBody.push_back(_position);
        _position.y -=1;
    }
}

int nibbler::setFruit()
{
    srand(time(NULL));
    this->_posfruit.x = rand()%21;
    if (this->_posfruit.x == 0)
        this->_posfruit.x += 1;
    if (this->_posfruit.x == 21)
        this->_posfruit.x -= 1;
    srand(time(NULL));
    this->_posfruit.y = rand()%21;
    if (this->_posfruit.y == 0)
        this->_posfruit.y += 1;
    if (this->_posfruit.y == 21)
        this->_posfruit.y -= 1;
    this->_map.at(this->_posfruit.y).at(this->_posfruit.x) = 'o';
    return 0;
}

void nibbler::setBodyPos()
{
    int i = 1;

    _posBody.at(0).y = _position.y;
    _posBody.at(0).x = _position.x;
    for (std::vector<std::string>::iterator it; it < _body.end(); it++, i++) {
        this->_map.at(this->_posBody.at(i).y).at(this->_posBody.at(i).x);
        _posBody.at(i).y = _posBody.at(i - 1).y;
        _posBody.at(i).x = _posBody.at(i - 1).x;
    }
}

void nibbler::MoveForward()
{
    if (this->_map.at(this->_position.y + 1).at(this->_position.x) == 'o') {
        this->_position.y += 1;
        setFruit();
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y - 1).at(this->_position.x) = 'E';
        setBodyPos();
    } else if (this->_map.at(this->_position.y + 1).at(this->_position.x) == '|') {
        this->_position.y += 1;
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y - 1).at(this->_position.x) = 'E';
        setBodyPos();
    } else if ((this->_map.at(this->_position.y + 1).at(this->_position.x) == 'E') || (this->_map.at(this->_position.y + 1).at(this->_position.x) == '|')) {
        this->_hp -= 1;
        if (this->_hp == -1)
            this->_state = game::state::LOOSE;
    }
}

void nibbler::MoveBackward()
{
    if (this->_map.at(this->_position.y - 1).at(this->_position.x) == 'o') {
        this->_position.y -= 1;
        setFruit();
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y + 1).at(this->_position.x) = 'E';
        setBodyPos();
    } else if (this->_map.at(this->_position.y - 1).at(this->_position.x) == ' ') {
        this->_position.y -= 1;
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y + 1).at(this->_position.x) = 'E';
        setBodyPos();
    } else if ((this->_map.at(this->_position.y - 1).at(this->_position.x) == 'E') || (this->_map.at(this->_position.y - 1).at(this->_position.x) == '|')) {
        this->_hp -= 1;
        if (this->_hp == -1)
            this->_state = game::state::LOOSE;
    }
}

void nibbler::MoveLeft()
{
    if (this->_map.at(this->_position.y).at(this->_position.x - 1) == 'o') {
        this->_position.x -= 1;
        setFruit();
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y).at(this->_position.x + 1) = 'E';
        setBodyPos();
    } else if (this->_map.at(this->_position.y).at(this->_position.x - 1) == ' ') {
        this->_position.x -= 1;
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y).at(this->_position.x + 1) = 'E';
        setBodyPos();
    } else if ((this->_map.at(this->_position.y).at(this->_position.x - 1) == 'E') || (this->_map.at(this->_position.y).at(this->_position.x - 1) == '|')) {
        this->_hp -= 1;
        if (this->_hp == -1)
            this->_state = game::state::LOOSE;
    }
}

void nibbler::MoveRight()
{
    if (this->_map.at(this->_position.y).at(this->_position.x + 1) == 'o') {
        this->_position.x += 1;
        setFruit();
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y).at(this->_position.x - 1) = 'E';
        setBodyPos();
    } else if (this->_map.at(this->_position.y).at(this->_position.x + 1) == ' ') {
        this->_position.x += 1;
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y).at(this->_position.x - 1) = 'E';
        setBodyPos();
    } else if ((this->_map.at(this->_position.y).at(this->_position.x + 1) == 'E') || (this->_map.at(this->_position.y).at(this->_position.x + 1) == '|')) {
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
