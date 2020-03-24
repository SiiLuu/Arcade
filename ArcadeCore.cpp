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
    this->_library = getLib(av.at(1));
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
        this->_lib->destroyLib();
        this->_library = ArcadeCore::library::SFML;
        this->_lib->load(this->libPath.at(0));
    }
    if (!str.compare("2")) {
        this->_lib->destroyLib();
        this->_library = ArcadeCore::library::SDL;
        this->_lib->load(this->libPath.at(1));
    }
    if (!str.compare("3")) {
        this->_lib->destroyLib();
        this->_library = ArcadeCore::library::NCURSES;
        this->_lib->load(this->libPath.at(2));
    }
}

void ArcadeCore::gameLoop()
{
    std::string str;
    this->_lib->load(this->_av.at(1));
    std::cout << this->_library << std::endl;

    while (1)
    {
        std::getline(std::cin, str);
        swapLib(str);
    }
}
