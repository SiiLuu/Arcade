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
#include <curses.h>

#ifndef ABSTRACTGRAPH_HPP_
#define ABSTRACTGRAPH_HPP_

class AbstractGraph : public IModuleGraph {

    public:
        AbstractGraph();
        virtual ~AbstractGraph();
        virtual void createWindow() = 0;
        virtual void display() = 0;
        virtual std::string registerEvents() = 0;

    protected:
    private:
};

typedef AbstractGraph *createGraphical_t();
typedef void destroyGraphical_t(AbstractGraph *);

#endif /* !ABSTRACTGRAPH_HPP_ */
