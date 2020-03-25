/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** nCurses functions
*/

#include "nCurses.hpp"

nCurses::nCurses()
{
    this->createWindow();
    this->display();
}

nCurses::~nCurses()
{
    std::cout << "NCURSES destroyed" << std::endl;
}

void nCurses::display()
{
    std::cout << "NCURSES -> Game displayed" << std::endl;
}

std::string nCurses::registerEvents()
{
    std::cout << "NCURSES -> Gestion des inputs" << std::endl;
    return ("");
}

void nCurses::createWindow()
{
    std::cout << "NCURSES -> Window Created" << std::endl;
    initscr();
    printw("Hello World !!!");
    refresh();
    getch();
    endwin();
}

extern "C" AbstractGraph *create()
{
    return new nCurses();
}

extern "C" void destroy(AbstractGraph *object)
{
    delete object;
}
