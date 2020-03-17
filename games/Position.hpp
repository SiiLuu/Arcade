/*
** EPITECH PROJECT, 2020
** Position.hpp
** File description:
** Position
*/

#include "Component.hpp"

#ifndef POSITION_HPP_
#define POSITION_HPP_

class Position : public Component {
    public:
        Position();
        ~Position();

    protected:
    private:
        int x;
        int y;
};

#endif /* !POSITION_HPP_ */
