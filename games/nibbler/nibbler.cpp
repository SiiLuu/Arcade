/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** nibbler
*/

#include "nibbler.hpp"

nibbler::nibbler()
{
    this->_dir = nibbler::direction::STOP;
    this->_fruits = 0;
    this->_hp = 0;
    this->_score = 0;
    this->_tailSize = 4;
    this->_position.x = 10;
    this->_position.y = 12;
    this->_state = game::state::RUNNING;
    this->init();
}

nibbler::~nibbler() {}

void nibbler::init()
{
    std::ifstream input("games/nibbler/nibblerMap.txt");
    std::ifstream inp("Scores.txt");
    size_t foundGame;
    size_t foundScore;

    for (std::string lin; getline(inp, lin);) {
        if ((foundGame = lin.find("NIBBLER")) != std::string::npos) {
            foundScore = lin.find("> ");
            for (size_t i = foundScore + 2; i < lin.size(); i++)
                this->_high.push_back(lin.at(i));
        }
        this->_highScore.push_back(lin + '\n');
    }
    for (std::string line; getline(input, line);)
        this->_map.push_back(line);
    input.close();
    inp.close();
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
    //std::vector<Position>::iterator it = this->_posBody.begin();

    if (this->_posBody.size() >= this->_tailSize) {
        x = this->_posBody.at(this->_posBody.size() - this->_tailSize).x;
        y = this->_posBody.at(this->_posBody.size() - this->_tailSize).y;
        this->_map.at(y).at(x) = ' ';
    }
}

void nibbler::MoveForward()
{
    if (!this->_posBody.empty() && (this->_dir != nibbler::direction::UP &&
                                    this->_dir != nibbler::direction::LEFT &&
                                    this->_dir != nibbler::direction::RIGHT)) {
        if (this->_position.y - 1 == this->_posBody.at(this->_posBody.size() - 1).y) {
            this->_dir = nibbler::direction::DOWN;
            this->MoveBackward();
        }
    }
    else if (this->_dir == nibbler::direction::UP ||
            this->_dir == nibbler::direction::STOP ||
            this->_dir == nibbler::direction::LEFT ||
            this->_dir == nibbler::direction::RIGHT) {
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
        } else if ((this->_map.at(this->_position.y - 1).at(this->_position.x) == 'E') || (this->_map.at(this->_position.y - 1).at(this->_position.x) == '|'))
            this->_hp -= 1;
        this->_dir = nibbler::direction::UP;
        this->update();
    }
}

void nibbler::MoveBackward()
{
    if (!this->_posBody.empty() && (this->_dir != nibbler::direction::DOWN  &&
                                    this->_dir != nibbler::direction::LEFT &&
                                    this->_dir != nibbler::direction::RIGHT)) {
        if (this->_position.y + 1 == this->_posBody.at(this->_posBody.size() - 1).y) {
            this->_dir = nibbler::direction::UP;
            this->MoveForward();
        }
    }
    else if (this->_dir == nibbler::direction::DOWN ||
            this->_dir == nibbler::direction::STOP ||
            this->_dir == nibbler::direction::LEFT ||
            this->_dir == nibbler::direction::RIGHT) {
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
        this->_dir = nibbler::direction::DOWN;
        this->update();
    }
}

void nibbler::MoveLeft()
{
    if (!this->_posBody.empty() && (this->_dir != nibbler::direction::LEFT &&
                                    this->_dir != nibbler::direction::UP &&
                                    this->_dir != nibbler::direction::DOWN)) {
        if (this->_position.x - 1 == this->_posBody.at(this->_posBody.size() - 1).x) {
            this->_dir = nibbler::direction::RIGHT;
            this->MoveRight();
        }
    }
    else if (this->_dir == nibbler::direction::LEFT ||
            this->_dir == nibbler::direction::STOP ||
            this->_dir == nibbler::direction::DOWN ||
            this->_dir == nibbler::direction::UP) {
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
        this->_dir = nibbler::direction::LEFT;
        this->update();
    }
}

void nibbler::MoveRight()
{
    if (!this->_posBody.empty() && (this->_dir != nibbler::direction::RIGHT  &&
                                    this->_dir != nibbler::direction::UP &&
                                    this->_dir != nibbler::direction::DOWN)) {
        if (this->_position.x + 1 == this->_posBody.at(this->_posBody.size() - 1).x) {
            this->_dir = nibbler::direction::LEFT;
            this->MoveLeft();
        }
    }
    else if (this->_dir == nibbler::direction::RIGHT ||
            this->_dir == nibbler::direction::STOP ||
            this->_dir == nibbler::direction::DOWN ||
            this->_dir == nibbler::direction::UP) {
        if (this->_map.at(this->_position.y).at(this->_position.x + 1) == 'o') {
            this->_posBody.push_back(this->_position);
            this->_position.x += 1;
            this->setFruit();
            this->_map.at(this->_position.y).at(this->_position.x) = 'P';
            this->_map.at(this->_position.y).at(this->_position.x - 1) = 'E';
            this->setBodyPos();
        }
        else if (this->_map.at(this->_position.y).at(this->_position.x + 1) == ' ') {
            this->_posBody.push_back(this->_position);
            this->_position.x += 1;
            this->_map.at(this->_position.y).at(this->_position.x - 1) = 'E';
            this->setBodyPos();
        }
        else if ((this->_map.at(this->_position.y).at(this->_position.x + 1) == 'E') ||
                 (this->_map.at(this->_position.y).at(this->_position.x + 1) == '|'))
            this->_hp -= 1;
        this->_dir = nibbler::direction::RIGHT;
        this->update();
    }
}

void nibbler::moveEnemy() {}

void nibbler::update()
{
    FILE *outfile;
    size_t foundGame;

    this->_map.at(this->_position.y).at(this->_position.x) = 'P';
    if (this->_hp < 0) {
        if (this->_score > std::stoi(this->_high)) {
            outfile = fopen("Scores.txt", "w");
            for (size_t k = 0; k < this->_highScore.size(); k++)
                if ((foundGame = this->_highScore.at(k).find("NIBBLER")) == std::string::npos)
                    fputs(this->_highScore.at(k).c_str(), outfile);
            fputs(("NIBBLER -> " + std::to_string(this->_score) + "\n").c_str(), outfile);
            fclose(outfile);
        }
        this->_state = game::state::LOOSE;
    }
}

std::string nibbler::getHighScore() const
{
    return (this->_high);
}

size_t nibbler::getHP() const
{
    return (this->_hp + 1);
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
