/*
** EPITECH PROJECT, 2020
** errorGestion.cpp
** File description:
** Arcade
*/
#include "error.hpp"
#include <iostream>

#ifndef ERRORGESTION_HPP_
#define ERRORGESTION_HPP_

class errorGestion : public Error
{
    private:
        void argsGestion(char **av);

    public:
        errorGestion(char **av);
        ~errorGestion();
};


#endif /* !ERRORGESTION_HPP_ */
