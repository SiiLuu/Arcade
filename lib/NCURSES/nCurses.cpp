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

void nCurses::displayGame(std::string game)
{
    if (game.find("pacman") != std::string::npos) {
        attron(A_BOLD);
        printw("PACMAN\n");
        attroff(A_BOLD);
    }
    if (game.find("nibbler") != std::string::npos) {
        attron(A_BOLD);
        printw("NIBBLER\n");
        attroff(A_BOLD);
    }
}

void nCurses::displayMenu()
{
    attron(A_BOLD);
    printw("MENU PRINCIPALE\n");
    attroff(A_BOLD);
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
