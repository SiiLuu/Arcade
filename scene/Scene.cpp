/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Scene
*/

#include "Scene.hpp"

void Scene::display(int scene, AbstractGraph *actualLib)
{
    if (scene == 1)
        actualLib->display();
}
