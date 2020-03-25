/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Graph Interface
*/
#include "iostream"
//#include "../ArcadeCore.hpp"

#ifndef IMODULEGRAPH_HPP_
#define IMODULEGRAPH_HPP_

class IModuleGraph {
    public:
        virtual ~IModuleGraph() = default;

        virtual void getCh() = 0;
        virtual void createWindow() = 0;
        virtual std::string display() = 0;
        //virtual void registerEvent() = 0;
        //virtual void destructWindow() = 0;

    protected:
    private:
};

#endif /* !IMODULEGRAPH_HPP_ */
