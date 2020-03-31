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
    } else if (this->_map.at(this->_position.y - 1).at(this->_position.x) == ' ') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.y -= 1;
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

bool Pacman::gameWon()
{
	int i = 0;
    int j = 0;

	while (i != this->_map.size()) {
		while (j != this->_map[i].size()) {
			if (this->_map[i][j] == 'o')
				return (false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}

void Pacman::moveGhosts(int i)
{
    if (i == 1)
		std::cout << "up" << std::endl;
	else if (i == 2)
		std::cout << "down" << std::endl;
	else if (i == 3)
		std::cout << "left" << std::endl;
	else
		std::cout << "right" << std::endl;
}

void Pacman::moveRand()
{
	srand(time(NULL));
	int i = rand()%(4);
	int j = rand()%(4);
	int k = rand()%(4);
	int l = rand()%(4);
    this->moveGhosts(i);
    this->moveGhosts(j);
    this->moveGhosts(k);
    this->moveGhosts(l);
}

void Pacman::moveEnemy()
{
    this->moveRand();
}

void Pacman::update()
{
    this->_map.at(this->_position.y).at(this->_position.x) = 'P';
    if (this->_hp < 0)
        this->_state = game::state::LOOSE;
    if (this->gameWon())
        this->_state = game::state::WIN;
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
