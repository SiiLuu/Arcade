
/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** position class
*/

#include "../AComponent.hpp"

#ifndef POSITION_HPP_
#define POSITION_HPP_

class Position : public AComponent {
    public:
        Position();
        ~Position();

    protected:
    private:
        int x;
        int y;
};

#endif /* !POSITION_HPP_ */
