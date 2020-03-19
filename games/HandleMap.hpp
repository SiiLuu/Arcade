/*
** EPITECH PROJECT, 2020
** HandleMap.hpp
** File description:
** HandleMap
*/

#include "./AGame/AGame.hpp"

#ifndef HANDLEMAP_HPP_
#define HANDLEMAP_HPP_

class HandleMap : public AbstractGame {
    public:
        void PlayerPosition();
        void StartPosition();
        void ObstaclesPosition();
        HandleMap();
        ~HandleMap();

    protected:
    private:
        std::vector<Entity> entities;
};

#endif /* !HANDLEMAP_HPP_ */
