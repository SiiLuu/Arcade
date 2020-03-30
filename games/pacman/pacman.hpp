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
        size_t _score;
        game::state _state;
        std::vector<std::string> _map;
        Position _position;
        int _hp;

    public:
        Pacman(/* args */);
        ~Pacman();

        void moveEnemy();
        void update();
        void init();
        void MoveForward();
        void MoveBackward();
        void MoveLeft();
        void MoveRight();
        size_t getScore() const;
        game::state getState() const;
        void setState();
        std::vector<std::string> getMap() const;
};

#endif /* !PACMAN_HPP_ */
