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
    this->_scenePause = new ScenePause();
}

Scene::~Scene() {}

void Scene::display(int scene, AbstractGraph *lib)
{
    if (scene == 1)
        this->_sceneMenu->display(lib);
    else if (scene == 2)
        this->_sceneGame->display(lib);
    else if (scene == 3)
        this->_scenePause->display(lib);
}
