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
    enum direction
    {
        STOP,
        RIGHT,
        UP,
        LEFT,
        DOWN,
    };

    private:
        std::string _high;
        std::vector<std::string> _highScore;
        size_t _score;
        game::state _state;
        std::vector<std::string> _map;
        Position _position;
        Position _posfruit;
        direction _dir;
        int _tailSize;
        int _hp;
        int _fruits;
        std::vector<std::string> _body;
        std::vector<Position> _posBody;
        std::vector<Position> _posy;
        std::vector<std::string> _saveHighScore;

        //Functions
        void setFruit();
        void setBodyPos();

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
        size_t getHP() const;
        std::string getHighScore() const;
        game::state getState() const;
        void setState(game::state state);
        std::vector<std::string> getMap() const;
};

#endif /* !NIBBLER_HPP_ */
