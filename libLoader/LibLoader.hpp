/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Lib loader class
*/
#include "../ArcadeCore.hpp"

#ifndef LIBLOADER_HPP_
#define LIBLOADER_HPP_

class LibLoader : public ArcadeCore {
    public:
        LibLoader();
        ~LibLoader();

        void load();
        void unLoad();

    protected:
    private:
};

#endif /* !LIBLOADER_HPP_ */
