/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Game Interface
*/

#ifndef IMODULEGAME_HPP_
#define IMODULEGAME_HPP_

class IModuleGame {
    public:
        IModuleGame();
        ~IModuleGame();
        void update();
        void init();

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
