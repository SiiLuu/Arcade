/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** abstract graph class
*/

#include "../IModuleGraph.hpp"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SDL2/SDL.h>
#include "SDL2/SDL_image.h"
#include <SDL2/SDL_ttf.h>
#include <curses.h>
#include <caca++.h>
#include <vector>

#ifndef ABSTRACTGRAPH_HPP_
#define ABSTRACTGRAPH_HPP_

class AbstractGraph : public IModuleGraph {

    public:
        AbstractGraph();
        virtual ~AbstractGraph();
        virtual void createWindow() = 0;
        virtual void display(std::vector<std::vector<std::string>>, int) = 0;
        virtual std::string registerEvents() = 0;

    protected:
    private:
};

typedef AbstractGraph *createGraphical_t(std::vector<std::vector<std::string>> name);
typedef void destroyGraphical_t(AbstractGraph *);

#endif /* !ABSTRACTGRAPH_HPP_ */
