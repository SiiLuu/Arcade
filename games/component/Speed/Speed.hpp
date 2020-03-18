/*
** EPITECH PROJECT, 2020
** Vitesse.hpp
** File description:
** Vitesse
*/

#include "Component.hpp"

#ifndef VITESSE_HPP_
#define VITESSE_HPP_

class Speed : public Component {
    public:
        Speed();
        ~Speed();

    protected:
    private:
        int speed;
};

#endif /* !VITESSE_HPP_ */
