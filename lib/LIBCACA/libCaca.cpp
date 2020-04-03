/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** libCaca functions
*/

#include "libCaca.hpp"

libCaca::libCaca(std::vector<std::vector<std::string>> info)
{
    this->_info = info;
    this->createWindow();
}

libCaca::~libCaca()
{
    caca_free_canvas(this->_canvas);
    caca_free_display(this->_window);
}

void libCaca::display(std::vector<std::vector<std::string>> infos, int scene)
{
    this->clear();
    if (scene == 1) {
        this->drawMen();
    }
    else if (scene == 2) {
        this->drawGame(infos);
    }
    caca_refresh_display(this->_window);
}

std::string libCaca::registerEvents()
{
    if (caca_get_event(this->_window, CACA_EVENT_KEY_PRESS, &_event, 100))
    {
        switch (caca_get_event_key_ch(&this->_event))
        {
        case CACA_KEY_ESCAPE:
            return ("ESCAPE");
        case CACA_KEY_LEFT:
            return ("KEYLEFT");
        case CACA_KEY_RIGHT:
            return ("KEYRIGHT");
        case CACA_KEY_UP:
            return ("KEYUP");
        case CACA_KEY_DOWN:
            return ("KEYDOWN");
        }
        switch (caca_get_event_key_utf32(&this->_event))
        {
        case 'z':
            return ("Z");
        case 'q':
            return ("Q");
        case 's':
            return ("S");
        case 'd':
            return ("D");
        default:
            return ("");
        }
    }
    return ("");
}

void libCaca::clear()
{
    caca_set_color_ansi(this->_canvas, CACA_BLACK, CACA_BLACK);
    caca_clear_canvas(this->_canvas);
    caca_set_color_ansi(this->_canvas, CACA_BLACK, this->_currentColor);
}

void libCaca::drawGame(std::vector<std::vector<std::string>> info)
{
    int pos = 7;

    for (int i = 0; i < info.at(0).size(); i++) {
        this->text(125, pos, info.at(0).at(i));
        pos += 1;
    }
    this->text(75, 6, ("SCORES : " + info.at(1).at(0)));
    if (info.at(1).at(0) < info.at(2).at(0))
        this->text(75, 7, ("HIGHSCORE : " + info.at(2).at(0)));
    else
        this->text(75, 7, ("HIGHSCORE : " + info.at(1).at(0)));
    this->text(75, 8, ("NUMBERS OF LIVES : " + info.at(3).at(0)));
}

void libCaca::drawMen()
{
    int pos = 7;

    caca_draw_box(this->_canvas, 15, 3, 105, 16, ' ');
    this->text(60, 5, "GAMES AVAILABLE");
    for (int i = 0; i < this->_info.at(1).size(); i++)
    {
        this->text(20, pos, ("-> " + this->_info.at(1).at(i)));
        pos += 1.5;
    }
    pos = 7;
    caca_draw_box(this->_canvas, 150, 3, 105, 16, ' ');
    this->text(196, 5, "LIBRARIES AVAILABLE");
    for (int i = 0; i < this->_info.at(0).size(); i++)
    {
        this->text(160, pos, ("-> " + this->_info.at(0).at(i)));
        pos += 1.5;
    }
    pos = 27;
    this->text(160, 16, "CURRENT LIBARRY : LIBCACA");
    this->text(196, 5, "LIBRARIES AVAILABLE");
    caca_draw_box(this->_canvas, 15, 23, 105, 16, ' ');
    this->text(60, 25, "YOUR SCORES");
    for (int i = 1; i < this->_info.at(2).size(); i++)
    {
        this->text(20, pos, this->_info.at(2).at(i));
        pos += 1.5;
    }
    caca_draw_box(this->_canvas, 150, 23, 105, 16, ' ');
    this->text(196, 25, "YOUR NAME");
    this->text(160, 27, ("-> " + this->_info.at(2).at(0)));
}

void libCaca::text(int x, int y, std::string str)
{
    caca_set_color_ansi(this->_canvas, this->_currentColor, CACA_TRANSPARENT);
    caca_put_str(this->_canvas, x, y, str.c_str());
    caca_set_color_ansi(this->_canvas, CACA_BLACK, this->_currentColor);
}

void libCaca::createWindow()
{
    this->_canvas = caca_create_canvas(267, 42);
    this->_window = caca_create_display(this->_canvas);
    caca_set_display_time(this->_window, 1000000 / 12);
    caca_set_display_title(this->_window, "Arcade");
    this->_currentColor = CACA_WHITE;
    caca_set_color_ansi(this->_canvas, CACA_BLACK, this->_currentColor);
    this->drawMen();
    caca_refresh_display(this->_window);
}

extern "C" AbstractGraph *create(std::vector<std::vector<std::string>> info)
{
    return new libCaca(info);
}

extern "C" void destroy(AbstractGraph *object)
{
    delete object;
}
