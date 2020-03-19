/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Game Interface
*/
#include "../ArcadeCore.hpp"

#ifndef IMODULEGAME_HPP_
#define IMODULEGAME_HPP_

class IModuleGame : public ArcadeCore {
    public:
        virtual ~IModuleGame() = default;
        virtual void update() = 0;
        virtual void init() = 0;

        enum state
        {
            WIN,
            LOOSE,
            PAUSE
        };

    protected:
    private:
};

#endif /* !IMODULEGRAPH_HPP_ */
