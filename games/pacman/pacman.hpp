/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** pacman class
*/

#include "../AGame/AbstractGame.hpp"
#include <chrono>

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

class Pacman : public AbstractGame
{
    class Position
    {
        public:
            unsigned int x;
            unsigned int y;
    };

    private:
        game::state _state;
        int _bonus;
        std::vector<std::string> _map;
        Position _position;
        Position _positionG1;
        Position _positionG2;
        Position _positionG3;
        Position _positionG4;
        int _hp;
        int _score;
        std::string _high;
        std::vector<std::string> _highScore;
        bool _clockE;
        char tmp1;
        char tmp2;
        char tmp3;
        char tmp4;

        //Functions
        bool gameWon();
        void moveGhosts(int i, char &tmp, Position &pos);
        void moveGhostsUp(char &tmp, Position &pos);
        void moveGhostsDown(char &tmp, Position &pos);
        void moveGhostsRight(char &tmp, Position &pos);
        void moveGhostsLeft(char &tmp, Position &pos);
        void moveRand();
        void respawnEnemy();

    public:
        Pacman();
        ~Pacman();

        void moveEnemy();
        void update();
        void init();
        void MoveForward();
        void MoveBackward();
        void MoveLeft();
        void MoveRight();
        size_t getScore() const;
        std::string getHighScore() const;
        size_t getHP() const;
        game::state getState() const;
        void setState(game::state state);
        std::vector<std::string> getMap() const;
};

#endif /* !PACMAN_HPP_ */
