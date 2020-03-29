/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** class for the main game scene
*/
#pragma once
#include "../../lib/AGraph/AbstractGraph.hpp"

#ifndef SCENEMAINGAME_HPP_
#define SCENEMAINGAME_HPP_

class SceneMainGame {

    private:
        /* data */
    public:
        SceneMainGame(/* args */);
        ~SceneMainGame();

        void display(AbstractGraph *,std::vector<std::vector<std::string>> gameInfos, int scene);
};

#endif /* !SCENEMAINGAME_HPP_ */
