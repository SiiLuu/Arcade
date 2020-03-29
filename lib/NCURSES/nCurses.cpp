/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** nCurses functions
*/

#include "nCurses.hpp"

nCurses::nCurses(std::vector<std::vector<std::string>> name)
{
    this->createWindow();
}

nCurses::~nCurses() {}

void nCurses::display(std::vector<std::vector<std::string>> infos, int scene)
{
    if (scene == 1) {
        attron(A_BOLD);
        printw("MENU PRINCIPALE\n");
        attroff(A_BOLD);
    }
    else if (scene == 2) {
        attron(A_BOLD);
        printw("PACMAN\n");
        attroff(A_BOLD);
    }
}

std::string nCurses::registerEvents()
{
    char event = getch();

    timeout(100);
    switch (event) {
    case 27:
        return ("ESCAPE");
    case 37:
        return ("KEYLEFT");
    case 39:
        return ("KEYRIGHT");
    case 40:
        return ("KEYDOWN");
    case 38:
        return ("KEYUP");
    default:
        return("");
    }
}

void nCurses::createWindow()
{
    initscr();
    keypad(stdscr, TRUE);
    refresh();
    endwin();
}

extern "C" AbstractGraph *create(std::vector<std::vector<std::string>> name)
{
    return new nCurses(name);
}

extern "C" void destroy(AbstractGraph *object)
{
    delete object;
}
