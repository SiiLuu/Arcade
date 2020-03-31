/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** pacman class
*/

#include "../AGame/AbstractGame.hpp"

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
        std::vector<std::string> _map;
        Position _position;
        Position _positionG1;
        Position _positionG2;
        Position _positionG3;
        Position _positionG4;
        int _hp;
        int _score;

    public:
        Pacman(/* args */);
        ~Pacman();

        bool gameWon();
        void moveGhosts(int i, char &tmp, Position &pos);
        void moveRand();
        void moveEnemy();
        void update();
        void init();
        void MoveForward();
        void MoveBackward();
        void MoveLeft();
        void MoveRight();
        size_t getScore() const;
        game::state getState() const;
        void setState(game::state state);
        std::vector<std::string> getMap() const;
        char tmp1;
        char tmp2;
        char tmp3;
        char tmp4;
};

#endif /* !PACMAN_HPP_ */
