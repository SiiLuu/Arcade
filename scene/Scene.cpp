/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Scene
*/

#include "Scene.hpp"

Scene::Scene()
{
    this->_sceneMenu = new SceneMainMenu();
    this->_sceneGame = new SceneMainGame();
}

Scene::~Scene()
{
    this->_sceneMenu->~SceneMainMenu();
    this->_sceneGame->~SceneMainGame();
}

void Scene::display(AbstractGraph *lib, std::vector<std::vector<std::string>> gameInfos)
{
    if (this->sceneNumber == 1)
        this->_sceneMenu->display(lib, gameInfos, this->sceneNumber);
    else if (this->sceneNumber == 2)
        this->_sceneGame->display(lib, gameInfos, this->sceneNumber);
}
