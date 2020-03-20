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
        virtual void getCh() = 0;

    protected:
    private:
};

#endif /* !ABSTRACTGRAPH_HPP_ */
