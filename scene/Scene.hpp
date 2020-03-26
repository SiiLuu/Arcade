/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Scene Class
*/
#include "sceneMainMenu/sceneMainMenu.hpp"
#include "scenePauseMenu/scenePauseMenu.hpp"
#include "sceneMainGame/sceneMainGame.hpp"

#ifndef SCENE_HPP_
#define SCENE_HPP_

class Scene {
    public:
        Scene();
        ~Scene();
        void display(int, AbstractGraph *);

    protected:
    private:
        SceneMainMenu *_sceneMenu;
        SceneMainGame *_sceneGame;
        ScenePause *_scenePause;
        AbstractGraph *graphicalLib;
        int sceneNumber;
};

#endif /* !SCENE_HPP_ */
