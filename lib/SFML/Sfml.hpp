/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** sfml class
*/
#include "../AGraph/AbstractGraph.hpp"

#ifndef SFML_HPP_
#define SFML_HPP_


class Sfml : public AbstractGraph
{
    private:
        /* data */
    public:
        Sfml(/* args */);
        virtual ~Sfml ();

        virtual void getCh();

};

extern "C"
    {
        AbstractGraph *create();
    }

#endif /* !SFML_HPP_ */
