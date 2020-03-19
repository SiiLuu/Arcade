/*
** EPITECH PROJECT, 2020
** Entity.hpp
** File description:
** Entity
*/
#pragma once
#include "../AGame/AGame.hpp"

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

class Entity : public AbstractGame {
    public:
        Entity();
        ~Entity();

    protected:
    private:
        int uniqueID;
};

#endif /* !ENTITY_HPP_ */