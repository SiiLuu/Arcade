/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** scene main menu
*/

#include "sceneMainMenu.hpp"

SceneMainMenu::SceneMainMenu(/* args */) {}

SceneMainMenu::~SceneMainMenu() {}

void SceneMainMenu::display(AbstractGraph *lib, std::vector<std::vector<std::string>> info)
{
    lib->displayMenu(info);
}
