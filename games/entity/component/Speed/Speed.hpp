/*
** EPITECH PROJECT, 2020
** Vitesse.hpp
** File description:
** Vitesse
*/

#include "../AComponent.hpp"

#ifndef VITESSE_HPP_
#define VITESSE_HPP_

class Speed : public AComponent {
    public:
        Speed();
        ~Speed();

    protected:
    private:
        int speed;
};

#endif /* !VITESSE_HPP_ */
