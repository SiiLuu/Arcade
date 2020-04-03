/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** nibbler
*/

#include "../AGame/AbstractGame.hpp"

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

class nibbler : public AbstractGame
{
    class Position
    {
        public:
            unsigned int x;
            unsigned int y;
    };

    private:
        std::string _highScore;
        size_t _score;
        game::state _state;
        std::vector<std::string> _map;
        Position _position;
        Position _posfruit;
        int _tailSize;
        int _hp;
        int _fruits;
        void setFruit();
        void setBodyPos();
        void setNewBody();
        std::vector<std::string> _body;
        std::vector<Position> _posBody;
        std::vector<Position> _posy;
        std::vector<std::string> _saveHighScore;

    public:
        nibbler();
        ~nibbler();

        void moveEnemy();
        void init();
        void MoveForward();
        void MoveBackward();
        void MoveLeft();
        void MoveRight();
        void update();
        size_t getScore() const;
        std::string getHighScore() const;
        game::state getState() const;
        void setState(game::state state);
        std::vector<std::string> getMap() const;
};

#endif /* !NIBBLER_HPP_ */
