/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** main scene class
*/
#pragma once
#include "../../lib/AGraph/AbstractGraph.hpp"
#include <vector>

#ifndef SCENEMAINMENU_HPP_
#define SCENEMAINMENU_HPP_

class SceneMainMenu {

    public:
        SceneMainMenu(/* args */);
        ~SceneMainMenu();

        void display(AbstractGraph *, std::vector<std::vector<std::string>>);

    private:
        int test;

};


#endif /* !SCENEMAINMENU_HPP_ */
