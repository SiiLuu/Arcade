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
    _position.x = 10;
    _position.y = 12;
    for (std::string line; getline(input, line);)
        this->_map.push_back(line);
    for (int i = 0; i < 4; i++) {
        this->_body.push_back("E");
        this->_posBody.push_back(_position);
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
    size_t i = _body.size() - 1;
    int x = _posBody.at(3).x;
    int y = _posBody.at(3).y;

    for (; i > 0; i--) {
        this->_map.at(this->_posBody.at(i).y).at(this->_posBody.at(i).x) = 'E';
        _posBody.at(i).y = _posBody.at(i - 1).y;
        _posBody.at(i).x = _posBody.at(i - 1).x;
    }
    this->_map.at(y).at(x) = ' ';
}

void nibbler::setNewBody()
{
    int i = _body.size();
    unsigned int x = _position.x;
    unsigned int y = _position.y;

    this->_body.push_back("E");
    _position.x = _posBody.at(_body.size() - 1).x;
    _position.y = _posBody.at(_body.size() - 1).y;
    this->_posBody.push_back(_position);
    _position.x = x;
    _position.y = y;
    this->_fruits += 1;
}

void nibbler::MoveForward()
{
    if (this->_map.at(this->_position.y - 1).at(this->_position.x) == 'o') {
        this->_position.y -= 1;
        setFruit();
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y + 1).at(this->_position.x) = 'E';
        setBodyPos();
        setNewBody();
    } else if (this->_map.at(this->_position.y - 1).at(this->_position.x) == ' ') {
        this->_position.y -= 1;
        this->_map.at(this->_position.y + 1).at(this->_position.x) = 'E';
        _posBody.at(0).y = (_position.y + 1);
        setBodyPos();
    } else if ((this->_map.at(this->_position.y - 1).at(this->_position.x) == 'E') || (this->_map.at(this->_position.y - 1).at(this->_position.x) == '|')) {
        this->_hp -= 1;
        if (this->_hp == -1)
            this->_state = game::state::LOOSE;
    }
    this->update();
}

void nibbler::MoveBackward()
{
    if (this->_map.at(this->_position.y + 1).at(this->_position.x) == 'o') {
        this->_position.y += 1;
        setFruit();
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y - 1).at(this->_position.x) = 'E';
        setBodyPos();
        setNewBody();
    } else if (this->_map.at(this->_position.y + 1).at(this->_position.x) == ' ') {
        this->_position.y += 1;
        this->_map.at(this->_position.y - 1).at(this->_position.x) = 'E';
        _posBody.at(0).y = (_position.y - 1);
        setBodyPos();
    } else if ((this->_map.at(this->_position.y + 1).at(this->_position.x) == 'E') || (this->_map.at(this->_position.y + 1).at(this->_position.x) == '|')) {
        this->_hp -= 1;
        if (this->_hp == -1)
            this->_state = game::state::LOOSE;
    }
    this->update();
}

void nibbler::MoveLeft()
{
    if (this->_map.at(this->_position.y).at(this->_position.x - 1) == 'o') {
        this->_position.x -= 1;
        setFruit();
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y).at(this->_position.x + 1) = 'E';
        setBodyPos();
        setNewBody();
    } else if (this->_map.at(this->_position.y).at(this->_position.x - 1) == ' ') {
        this->_position.x -= 1;
        this->_map.at(this->_position.y).at(this->_position.x + 1) = 'E';
        _posBody.at(0).x = (_position.x + 1);
        setBodyPos();
    } else if ((this->_map.at(this->_position.y).at(this->_position.x - 1) == 'E') || (this->_map.at(this->_position.y).at(this->_position.x - 1) == '|')) {
        this->_hp -= 1;
        if (this->_hp == -1)
            this->_state = game::state::LOOSE;
    }
    this->update();
}

void nibbler::MoveRight()
{
    if (this->_map.at(this->_position.y).at(this->_position.x + 1) == 'o') {
        this->_position.x += 1;
        setFruit();
        this->_map.at(this->_position.y).at(this->_position.x) = 'P';
        this->_map.at(this->_position.y).at(this->_position.x - 1) = 'E';
        setBodyPos();
        setNewBody();
    }
    if (this->_map.at(this->_position.y).at(this->_position.x + 1) == ' ') {
        this->_position.x += 1;
        this->_map.at(this->_position.y).at(this->_position.x - 1) = 'E';
        _posBody.at(0).x = (_position.x - 1);
        setBodyPos();
    } else if ((this->_map.at(this->_position.y).at(this->_position.x + 1) == 'E') || (this->_map.at(this->_position.y).at(this->_position.x + 1) == '|')) {
        this->_hp -= 1;
        if (this->_hp == -1)
            this->_state = game::state::LOOSE;
    }
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
