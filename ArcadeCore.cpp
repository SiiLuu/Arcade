/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Arcade core
*/
#include "ArcadeCore.hpp"

ArcadeCore::ArcadeCore(std::vector<std::string> av)
{
    this->_lib = new LibLoader();
    this->_scene = new Scene();
    this->_library = getLib(av.at(1));
    this->_game = ArcadeCore::games::NOTHING;
    this->_scene->sceneNumber = 1;
    this->_av = av;
    this->gameLoop();
}

ArcadeCore::ArcadeCore() {}

ArcadeCore::~ArcadeCore() {}

ArcadeCore::library ArcadeCore::getLib(std::string lib) const
{
    if (lib.find("sfml") != std::string::npos)
        return (ArcadeCore::library::SFML);
    else if (lib.find("ncurses") != std::string::npos)
        return (ArcadeCore::library::NCURSES);
    else if (lib.find("sdl") != std::string::npos)
        return (ArcadeCore::library::SDL);
    else
        return (ArcadeCore::library::NONE);
}

void ArcadeCore::swapLib(std::string str)
{
    if (!str.compare("1")) {
        this->_lib->destroyGraphical();
        this->_library = ArcadeCore::library::SFML;
        this->_lib->loadGraphical(this->libPath.at(0));
    }
    if (!str.compare("2")) {
        this->_lib->destroyGraphical();
        this->_library = ArcadeCore::library::SDL;
        this->_lib->loadGraphical(this->libPath.at(1));
    }
    if (!str.compare("3")) {
        this->_lib->destroyGraphical();
        this->_library = ArcadeCore::library::NCURSES;
        this->_lib->loadGraphical(this->libPath.at(2));
    }
}

void ArcadeCore::swapGame(std::string str)
{
    if (!str.compare("p")) {
        if (this->_game != ArcadeCore::games::NOTHING)
            this->_lib->destroyGames();
        this->_game = ArcadeCore::games::PACMAN;
        this->_lib->loadGames(this->gamePath.at(0));
    }
    if (!str.compare("n")) {
        if (this->_game != ArcadeCore::games::NOTHING)
            this->_lib->destroyGames();
        this->_game = ArcadeCore::games::NIBBLER;
        this->_lib->loadGames(this->gamePath.at(1));
    }
}
/*
void ArcadeCore::event(std::string event)
{
    if (!event.compare("z"))
        this->_lib->_actual_game_lib->MoveForward();
    if (!event.compare("s"))
        this->_lib->_actual_game_lib->MoveBackward();
    if (!event.compare("q"))
        this->_lib->_actual_game_lib->MoveLeft();
    if (!event.compare("d"))
        this->_lib->_actual_game_lib->MoveRight();
}*/


void ArcadeCore::eventInSfml()
{
    std::string event = this->_lib->_actual_graphical_lib->registerEvents();

    if (!event.compare("CLOSE"))
        this->_library = ArcadeCore::library::NONE;
    if (!event.compare("2"))
        this->swapLib("2");
    if (!event.compare("3"))
        this->swapLib("3");
    if (!event.compare("P")) {
        this->_gameToDisplay = "PACMAN";
        this->_scene->sceneNumber = 2;
        this->swapGame("p");
    }
    if (!event.compare("N")) {
        this->_gameToDisplay = "NIBBLER";
        this->_scene->sceneNumber = 2;
        this->swapGame("n");
    }
}

void ArcadeCore::eventInSdl()
{
    std::string event = this->_lib->_actual_graphical_lib->registerEvents();

    if (event == "CLOSE")
        this->_library = ArcadeCore::library::NONE;
}

void ArcadeCore::gameLoop()
{
    this->_lib->loadGraphical(this->_av.at(1));

    while (this->_library != ArcadeCore::library::NONE)
    {
        if (this->_library == ArcadeCore::library::SFML) {
            this->eventInSfml();
            this->_scene->display(this->_lib->_actual_graphical_lib, this->_gameToDisplay);
        }
        if (this->_library == ArcadeCore::library::SDL) {
            this->eventInSdl();
            this->_scene->display(this->_lib->_actual_graphical_lib, this->_gameToDisplay);
        }
        //std::getline(std::cin, str);
        //swapLib(str);
        //swapGame(str);
        //event(str);
    }
}
