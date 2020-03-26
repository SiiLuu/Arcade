/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** main scene class
*/
#pragma once
#include "../../lib/AGraph/AbstractGraph.hpp"

#ifndef SCENEMAINMENU_HPP_
#define SCENEMAINMENU_HPP_

class SceneMainMenu {

    public:
        SceneMainMenu(/* args */);
        ~SceneMainMenu();

        void display(AbstractGraph *);

    private:
        int test;

};


#endif /* !SCENEMAINMENU_HPP_ */
