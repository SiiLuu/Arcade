/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Graph Interface
*/
#include "../ArcadeCore.hpp"

#ifndef IMODULEGRAPH_HPP_
#define IMODULEGRAPH_HPP_

class IModuleGraph : public ArcadeCore {
    public:
        IModuleGraph();
        ~IModuleGraph();

        void createdWindow();
        void registerEvenet();
        void displayMap();
        void destructWindow();

    protected:
    private:
};

#endif /* !IMODULEGRAPH_HPP_ */
