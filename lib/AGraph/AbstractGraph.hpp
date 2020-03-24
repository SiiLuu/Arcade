/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** abstract graph class
*/
#include "../IModuleGraph.hpp"

#ifndef ABSTRACTGRAPH_HPP_
#define ABSTRACTGRAPH_HPP_

class AbstractGraph : public IModuleGraph {

    public:
        AbstractGraph();
        virtual ~AbstractGraph();
        virtual void getCh() = 0;
        virtual void createWindow() = 0;
        virtual void display() = 0;

    protected:
    private:
};

typedef AbstractGraph *createGraphical_t();
typedef void destroyGraphical_t(AbstractGraph *);

#endif /* !ABSTRACTGRAPH_HPP_ */
