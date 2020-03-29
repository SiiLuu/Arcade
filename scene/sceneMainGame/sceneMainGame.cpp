/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** scene for the main game
*/

#include "sceneMainGame.hpp"

SceneMainGame::SceneMainGame(/* args */)
{
}

SceneMainGame::~SceneMainGame()
{
}

void SceneMainGame::display(AbstractGraph *lib, std::vector<std::vector<std::string>> gameInfos, int scene)
{
    lib->display(gameInfos, scene);
}
