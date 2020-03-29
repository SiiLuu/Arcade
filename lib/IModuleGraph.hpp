/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Graph Interface
*/
#include "iostream"
#include <vector>
//#include "../ArcadeCore.hpp"

#ifndef IMODULEGRAPH_HPP_
#define IMODULEGRAPH_HPP_

class IModuleGraph {
    public:
        virtual ~IModuleGraph() = default;

        virtual void createWindow() = 0;
        virtual void display(std::vector<std::vector<std::string>>, int) = 0;
        virtual std::string registerEvents() = 0;
        //virtual void destructWindow() = 0;

    protected:
    private:
};

#endif /* !IMODULEGRAPH_HPP_ */
