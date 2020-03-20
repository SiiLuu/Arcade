/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Graph Interface
*/
#pragma once
#include "../ArcadeCore.hpp"

#ifndef IMODULEGRAPH_HPP_
#define IMODULEGRAPH_HPP_

class IModuleGraph : public ArcadeCore {
    public:
        virtual ~IModuleGraph() = default;

        virtual void getCh() = 0;
        //virtual void createdWindow() = 0;
        //virtual void registerEvenet() = 0;
        //virtual void displayMap() = 0;
        //virtual void destructWindow() = 0;

    protected:
    private:
};

#endif /* !IMODULEGRAPH_HPP_ */
