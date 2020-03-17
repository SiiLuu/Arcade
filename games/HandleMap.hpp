/*
** EPITECH PROJECT, 2020
** HandleMap.hpp
** File description:
** HandleMap
*/

#include "AbstractGame.hpp"

#ifndef HANDLEMAP_HPP_
#define HANDLEMAP_HPP_

class HandleMap : public AbstractGame {
    public:
        PlayerPosition();
        StartPosition();
        ObstaclesPosition();
        HandleMap();
        ~HandleMap();

    protected:
    private:
        std::vector<Entity> entities;
};

#endif /* !HANDLEMAP_HPP_ */
