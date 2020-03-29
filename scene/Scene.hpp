/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Scene Class
*/
#include "sceneMainMenu/sceneMainMenu.hpp"
#include "sceneMainGame/sceneMainGame.hpp"
#include <vector>

#ifndef SCENE_HPP_
#define SCENE_HPP_

class Scene {
    public:
        Scene();
        ~Scene();
        void display(AbstractGraph *, std::vector<std::vector<std::string>> gameInfos);
        int sceneNumber;

    protected:
    private:
        SceneMainMenu *_sceneMenu;
        SceneMainGame *_sceneGame;
        AbstractGraph *graphicalLib;
};

#endif /* !SCENE_HPP_ */
