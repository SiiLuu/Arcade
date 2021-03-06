/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** pacman class
*/

#include "pacman.hpp"

Pacman::Pacman()
{
    this->_position.x = 10;
    this->_position.y = 14;
    this->_positionG1.x = 9;
    this->_positionG1.y = 11;
    this->_positionG2.x = 11;
    this->_positionG2.y = 11;
    this->_positionG3.x = 9;
    this->_positionG3.y = 10;
    this->_positionG4.x = 11;
    this->_positionG4.y = 10;
    this->_score = 0;
    this->_bonus = 0;
    this->_hp = 3;
    this->tmp1 = ' ';
    this->tmp2 = ' ';
    this->tmp3 = ' ';
    this->tmp4 = ' ';
    this->_clockE = false;
    this->_state = game::state::RUNNING;
    this->init();
}

Pacman::~Pacman() {}

void Pacman::init()
{
    std::ifstream input("games/pacman/pacmanMap.txt");
    std::ifstream inp("Scores.txt");
    size_t foundGame;
    size_t foundScore;

    for (std::string lin; getline(inp, lin);) {
        if ((foundGame = lin.find("PACMAN")) != std::string::npos) {
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

void Pacman::respawnEnemy()
{
    if (this->_positionG1.x == this->_position.x && this->_positionG1.y == this->_position.y) {
        this->_positionG1.x = 9;
        this->_positionG1.y = 11;
        this->tmp1 = ' ';
    } else if (this->_positionG2.x == this->_position.x && this->_positionG2.y == this->_position.y) {
        this->_positionG2.x = 11;
        this->_positionG2.y = 11;
        this->tmp2 = ' ';
    } else if (this->_positionG3.x == this->_position.x && this->_positionG3.y == this->_position.y) {
        this->_positionG3.x = 9;
        this->_positionG3.y = 10;
        this->tmp3 = ' ';
    } else if (this->_positionG4.x == this->_position.x && this->_positionG4.y == this->_position.y) {
        this->_positionG4.x = 11;
        this->_positionG4.y = 10;
        this->tmp4 = ' ';
    }
}

void Pacman::MoveForward()
{
    if (this->_map.at(this->_position.y - 1).at(this->_position.x) == 'o') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_score += 10;
        this->_position.y -= 1;
    } else if (this->_map.at(this->_position.y - 1).at(this->_position.x) == 'A') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.y -= 1;
        this->respawnEnemy();
    } else if (this->_map.at(this->_position.y - 1).at(this->_position.x) == 'O') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_bonus = 30;
        this->_score += 100;
        this->_position.y -= 1;
    } else if (this->_map.at(this->_position.y - 1).at(this->_position.x) == ' ') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.y -= 1;
    } else if (this->_map.at(this->_position.y - 1).at(this->_position.x) == 'E') {
        this->_hp -= 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.x = 10;
        this->_position.y = 14;
    }
    if (this->_bonus > 0)
        this->_bonus -= 1;
    this->update();
}

void Pacman::MoveBackward()
{
    if (this->_map.at(this->_position.y + 1).at(this->_position.x) == 'o') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_score += 10;
        this->_position.y += 1;
    } else if (this->_map.at(this->_position.y + 1).at(this->_position.x) == 'A') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.y += 1;
        this->respawnEnemy();
    } else if (this->_map.at(this->_position.y + 1).at(this->_position.x) == 'O') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_bonus = 30;
        this->_score += 100;
        this->_position.y += 1;
    } else if (this->_map.at(this->_position.y + 1).at(this->_position.x) == ' ') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.y += 1;
    } else if (this->_map.at(this->_position.y + 1).at(this->_position.x) == 'E') {
        this->_hp -= 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.x = 10;
        this->_position.y = 14;
    }
    if (this->_bonus > 0)
        this->_bonus -= 1;
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
    } else if (this->_map.at(this->_position.y).at(this->_position.x - 1) == 'A') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.x -= 1;
        this->respawnEnemy();
    } else if (this->_map.at(this->_position.y).at(this->_position.x - 1) == 'O') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_bonus = 30;
        this->_score += 100;
        this->_position.x -= 1;
    } else if (this->_map.at(this->_position.y).at(this->_position.x - 1) == ' ') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.x -= 1;
    } else if (this->_map.at(this->_position.y).at(this->_position.x - 1) == 'E') {
        this->_hp -= 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.x = 10;
        this->_position.y = 14;
    }
    if (this->_bonus > 0)
        this->_bonus -= 1;
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
    } else if (this->_map.at(this->_position.y).at(this->_position.x + 1) == 'A') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.x += 1;
        this->respawnEnemy();
    } else if (this->_map.at(this->_position.y).at(this->_position.x + 1) == 'O') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_bonus = 30;
        this->_score += 100;
        this->_position.x += 1;
    } else if (this->_map.at(this->_position.y).at(this->_position.x + 1) == ' ') {
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.x += 1;
    } else if (this->_map.at(this->_position.y).at(this->_position.x + 1) == 'E') {
        this->_hp -= 1;
        this->_map.at(this->_position.y).at(this->_position.x) = ' ';
        this->_position.x = 10;
        this->_position.y = 14;
    }
    if (this->_bonus > 0)
        this->_bonus -= 1;
    this->update();
}

bool Pacman::gameWon()
{
	int i = 0;
    int j = 0;

	while (i != this->_map.size()) {
		while (j != this->_map[i].size()) {
			if (this->_map[i][j] == 'o' || this->_map[i][j] == 'O')
				return (false);
			j++;
		}
		i++;
		j = 0;
	}
	return (true);
}

void Pacman::moveGhostsUp(char &tmp, Position &pos)
{
    if (this->_map.at(pos.y - 1).at(pos.x) == 'o') {
        this->_map.at(pos.y).at(pos.x) = tmp;
        tmp = 'o';
        pos.y -= 1;
    } else if (this->_map.at(pos.y - 1).at(pos.x) == 'O') {
        this->_map.at(pos.y).at(pos.x) = tmp;
        tmp = 'O';
        pos.y -= 1;
    } else if (this->_map.at(pos.y - 1).at(pos.x) == ' ') {
        this->_map.at(pos.y).at(pos.x) = tmp;
        tmp = ' ';
        pos.y -= 1;
    } else if (this->_map.at(pos.y - 1).at(pos.x) == '-') {
        this->_map.at(pos.y).at(pos.x) = tmp;
        tmp = 'o';
        pos.y -= 2;
    } else if (this->_map.at(pos.y - 1).at(pos.x) == 'P' && this->_bonus < 0) {
        pos.y -= 1;
        tmp = ' ';
        this->_hp -= 1;
        this->_position.x = 10;
        this->_position.y = 14;
    }
}

void Pacman::moveGhostsDown(char &tmp, Position &pos)
{
    if (this->_map.at(pos.y + 1).at(pos.x) == 'o') {
        this->_map.at(pos.y).at(pos.x) = tmp;
        tmp = 'o';
        pos.y += 1;
    } else if (this->_map.at(pos.y + 1).at(pos.x) == 'O') {
        this->_map.at(pos.y).at(pos.x) = tmp;
        tmp = 'O';
        pos.y += 1;
    } else if (this->_map.at(pos.y + 1).at(pos.x) == ' ') {
        this->_map.at(pos.y).at(pos.x) = tmp;
        tmp = ' ';
        pos.y += 1;
    } else if (this->_map.at(pos.y + 1).at(pos.x) == 'P' && this->_bonus < 0) {
        pos.y += 1;
        tmp = ' ';
        this->_hp -= 1;
        this->_position.x = 10;
        this->_position.y = 14;
    }
}

void Pacman::moveGhostsRight(char &tmp, Position &pos)
{
    if (pos.y == 9 && pos.x == 0) {
        this->_map.at(9).at(0) = ' ';
        pos.x = 20;
    }
    else if (this->_map.at(pos.y).at(pos.x - 1) == 'o') {
        this->_map.at(pos.y).at(pos.x) = tmp;
        tmp = 'o';
        pos.x -= 1;
    }
    else if (this->_map.at(pos.y).at(pos.x - 1) == 'O') {
        this->_map.at(pos.y).at(pos.x) = tmp;
        tmp = 'O';
        pos.x -= 1;
    }
    else if (this->_map.at(pos.y).at(pos.x - 1) == ' ') {
        this->_map.at(pos.y).at(pos.x) = tmp;
        tmp = ' ';
        pos.x -= 1;
    }
    else if (this->_map.at(pos.y).at(pos.x - 1) == 'P' && this->_bonus < 0) {
        pos.x -= 1;
        tmp = ' ';
        this->_hp -= 1;
        this->_position.x = 10;
        this->_position.y = 14;
    }
}

void Pacman::moveGhostsLeft(char &tmp, Position &pos)
{
    if (pos.y == 9 && pos.x == 20) {
        this->_map.at(9).at(20) = ' ';
        pos.x = 0;
    }
    else if (this->_map.at(pos.y).at(pos.x + 1) == 'o') {
        this->_map.at(pos.y).at(pos.x) = tmp;
        tmp = 'o';
        pos.x += 1;
    } else if (this->_map.at(pos.y).at(pos.x + 1) == 'O') {
        this->_map.at(pos.y).at(pos.x) = tmp;
        tmp = 'O';
        pos.x += 1;
    } else if (this->_map.at(pos.y).at(pos.x + 1) == ' ') {
        this->_map.at(pos.y).at(pos.x) = tmp;
        tmp = ' ';
        pos.x += 1;
    } else if (this->_map.at(pos.y).at(pos.x + 1) == 'P' && this->_bonus < 0) {
        pos.x += 1;
        tmp = ' ';
        this->_hp -= 1;
        this->_position.x = 10;
        this->_position.y = 14;
    }
}

void Pacman::moveGhosts(int i, char &tmp, Position &pos)
{
    if (i == 1)
        moveGhostsUp(tmp, pos);
    else if (i == 2)
        moveGhostsDown(tmp,pos);
    else if (i == 3)
        moveGhostsRight(tmp, pos);
    else
        moveGhostsLeft(tmp, pos);
}

void Pacman::moveRand()
{
	srand(time(NULL));
	int i = rand()%(4);
	int j = rand()%(4);
	int k = rand()%(4);
	int l = rand()%(4);
    this->moveGhosts(i, this->tmp1, this->_positionG1);
    this->moveGhosts(j, this->tmp2, this->_positionG2);
    this->moveGhosts(k, this->tmp3, this->_positionG3);
    this->moveGhosts(l, this->tmp4, this->_positionG4);
    this->update();
}

void Pacman::moveEnemy()
{
    static auto start = std::chrono::system_clock::now();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = start-end;
    if (elapsed_seconds.count() <= -10.00000 || this->_clockE == true) {
        this->moveRand();
        this->_clockE = true;
        start = std::chrono::system_clock::now();
    }
}

void Pacman::update()
{
    FILE *outfile;
    size_t foundGame;

    this->_map.at(this->_position.y).at(this->_position.x) = 'P';
    ((this->_bonus > 0) ? this->_map.at(this->_positionG1.y).at(this->_positionG1.x) = 'A' : this->_map.at(this->_positionG1.y).at(this->_positionG1.x) = 'E');
    ((this->_bonus > 0) ? this->_map.at(this->_positionG2.y).at(this->_positionG2.x) = 'A' : this->_map.at(this->_positionG2.y).at(this->_positionG2.x) = 'E');
    ((this->_bonus > 0) ? this->_map.at(this->_positionG3.y).at(this->_positionG3.x) = 'A' : this->_map.at(this->_positionG3.y).at(this->_positionG3.x) = 'E');
    ((this->_bonus > 0) ? this->_map.at(this->_positionG4.y).at(this->_positionG4.x) = 'A' : this->_map.at(this->_positionG4.y).at(this->_positionG4.x) = 'E');
    if (this->_hp < 0) {
        if (this->_score > std::stoi(this->_high)) {
            outfile = fopen("Scores.txt", "w");
            for (size_t k = 0; k < this->_highScore.size(); k++)
                if ((foundGame = this->_highScore.at(k).find("PACMAN")) == std::string::npos)
                    fputs(this->_highScore.at(k).c_str(), outfile);
            fputs(("PACMAN  -> " + std::to_string(this->_score)).c_str(), outfile);
            fclose(outfile);
        }
        this->_state = game::state::LOOSE;
    }
    if (this->gameWon()) {
        if (this->_score > std::stoi(this->_high)) {
            outfile = fopen("Scores.txt", "w");
            for (size_t k = 0; k < this->_highScore.size(); k++)
                if ((foundGame = this->_highScore.at(k).find("PACMAN")) == std::string::npos)
                    fputs(this->_highScore.at(k).c_str(), outfile);
            fputs(("PACMAN  -> " + std::to_string(this->_score) + "\n").c_str(), outfile);
            fclose(outfile);
        }
        this->_state = game::state::WIN;
    }
}

std::string Pacman::getHighScore() const
{
    return (this->_high);
}

size_t Pacman::getHP() const
{
    return (this->_hp + 1);
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
