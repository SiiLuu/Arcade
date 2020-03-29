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

nCurses::~nCurses()
{
    std::cout << "NCURSES destroyed" << std::endl;
}

void nCurses::display(std::vector<std::vector<std::string>> infos, int scene)
{
    clear();
    if (!game.compare("PACMAN"))
        mvprintw(LINES / 2, COLS / 2, "Pacman");
    else if (!game.compare("NIBBLER"))
        mvprintw(LINES / 2, COLS / 2, "Nibbler");
    else if (!game.compare("QIX"))
        mvprintw(LINES / 2, COLS / 2, "Qix");
}

void nCurses::set_legend()
{
    WINDOW *legend;

    legend = subwin(stdscr, LINES / 6, COLS / 3 + COLS / 15, LINES / 2 + LINES / 3, COLS / 2 + COLS / 10);
    box(legend, ACS_VLINE, ACS_HLINE);
    wattron(legend, A_BOLD);
    mvwprintw(legend, 1, 1, "To select a library press number (1 to 9)");
    mvwprintw(legend, 3, 1, "To select a game press 'p' for Pacman");
    mvwprintw(legend, 5, 1, "To select a game press 'n' for nibbler");
    mvwprintw(legend, 7, 1, "To quit the window press 'q'");
}

std::string nCurses::registerEvents()
{
    char c;

    c = getch();
    switch (c) {
        case 'p':
            return ("P");
        case 'n':
            return ("N");
        case 'w':
            return ("Z");
        case 's':
            return ("S");
        case 'a':
            return ("Q");
        case 'd':
            return ("D");
        case '1':
            return ("1");
        case '2':
            return ("2");
        case 27:
            return ("ESCAPE");
        case 'q':
            endwin();
            return ("QUIT");
        default:
            break;
    }
    return ("");
}

void nCurses::displayMenu(std::vector<std::vector<std::string>> info)
{
    char c;

    initscr();
    while (1) {
        clear();
        set_legend();
    }
}

void nCurses::createWindow()
{
    initscr();
    noecho();
    refresh();
    getch();
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