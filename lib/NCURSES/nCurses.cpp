/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** nCurses functions
*/

#include "nCurses.hpp"

nCurses::nCurses(std::vector<std::vector<std::string>> info)
{
    this->_info = info;
    this->createWindow();
}

nCurses::~nCurses()
{
    caca_free_canvas(this->_canvas);  
    caca_free_display(this->_window);  
}

void nCurses::display(std::vector<std::vector<std::string>> infos, int scene)
{
    if (scene == 1) {
        
    }
    else if (scene == 2) {
    }
}

/*
        caca_get_event_key_utf32(&_event) == 'q')
        caca_get_event_key_utf32(&_event) == 'Q')
        caca_get_event_key_ch(&_event) == CACA_KEY_LEFT);
        caca_get_event_key_utf32(&_event) == 'd')
        caca_get_event_key_utf32(&_event) == 'D')
        caca_get_event_key_ch(&_event) == CACA_KEY_RIGHT);
        caca_get_event_key_utf32(&_event) == 'z')
        caca_get_event_key_utf32(&_event) == 'Z')
        caca_get_event_key_ch(&_event) == CACA_KEY_UP);
        caca_get_event_key_utf32(&_event) == 's')
        caca_get_event_key_utf32(&_event) == 'S')
        caca_get_event_key_ch(&_event) == CACA_KEY_DOWN);
        caca_get_event_key_utf32(&_event) == 'a')
        caca_get_event_key_utf32(&_event) == 'A');
        caca_get_event_key_utf32(&_event) == 'e')
        caca_get_event_key_utf32(&_event) == 'E');
        caca_get_event_key_utf32(&_event) == 'w')
        caca_get_event_key_utf32(&_event) == 'W');
        caca_get_event_key_utf32(&_event) == 'x')
        caca_get_event_key_utf32(&_event) == 'X');
        caca_get_event_key_utf32(&_event) == ' ');
        caca_get_event_key_ch(&_event) == CACA_KEY_ESCAPE);
        caca_get_event_key_utf32(&_event) == 'j')
        caca_get_event_key_utf32(&_event) == 'J');
        caca_get_event_key_utf32(&_event) == 'k')
        caca_get_event_key_utf32(&_event) == 'K');
        caca_get_event_key_utf32(&_event) == 'u')
        caca_get_event_key_utf32(&_event) == 'U');
        caca_get_event_key_utf32(&_event) == 'i')
        caca_get_event_key_utf32(&_event) == 'I');
        caca_get_event_key_utf32(&_event) == 'm')
        caca_get_event_key_utf32(&_event) == 'M');
        caca_get_event_key_utf32(&_event) == 'r')
        caca_get_event_key_utf32(&_event) == 'R');
        caca_get_event_key_ch(&_event) == CACA_KEY_BACKSPACE);
        caca_get_event_key_ch(&_event) == CACA_KEY_RETURN);
}
*/

std::string nCurses::registerEvents()
{
    caca_get_event(this->_window, CACA_EVENT_KEY_PRESS, &_event, -1);
    if (caca_get_event_key_ch(&this->_event) == CACA_KEY_ESCAPE)
        return ("CLOSE");
    return ("");
}

void nCurses::getLists()
{
    for (int i = 0; i < this->_info.at(1).size(); i++)
        this->_listGames.append("->" + this->_info.at(1).at(i) + "\n");
    for (int i = 0; i < this->_info.at(0).size(); i++)
        this->_listLibs.append("-> " + this->_info.at(0).at(i) + "\n");
    this->_listLibs.append("\n\nACTUAL LIBRARY : SDL");
    this->_name = "-> " + this->_info.at(2).at(0);
    this->_score = "-> 10000";
}

void nCurses::createWindow()
{
    this->_canvas = caca_create_canvas(1600 / 8, 900 / 16);
    this->_window = caca_create_display(this->_canvas);
    caca_set_display_time(this->_window, 1000000 / 12);
    caca_set_display_title(this->_window, "Arcade");
    this->_currentColor = CACA_WHITE;
    caca_set_color_ansi(this->_canvas, CACA_BLACK, this->_currentColor);
    caca_refresh_display(this->_window);
}

extern "C" AbstractGraph *create(std::vector<std::vector<std::string>> info)
{
    return new nCurses(info);
}

extern "C" void destroy(AbstractGraph *object)
{
    delete object;
}
