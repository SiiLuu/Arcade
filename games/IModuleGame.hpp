/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Game Interface
*/

#include <vector>
#include <string>
#include <iostream>

#ifndef IMODULEGAME_HPP_
#define IMODULEGAME_HPP_

namespace game {

    enum state
        {
            WIN,
            LOOSE,
            RUNNING
        };

    class IModuleGame {
        public:
            virtual ~IModuleGame() = default;

            virtual void moveEnemy() = 0;
            virtual void init() = 0;
            virtual void MoveForward() = 0;
            virtual void MoveBackward() = 0;
            virtual void MoveLeft() = 0;
            virtual void MoveRight() = 0;
            virtual void update() = 0;
            virtual size_t getScore() const = 0;
            virtual game::state getState() const = 0;
            virtual void setState() = 0;
            virtual std::vector<std::string> getMap() const = 0;

        protected:
        private:
    };
}

#endif /* !IMODULEGRAPH_HPP_ */
