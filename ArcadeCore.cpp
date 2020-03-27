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
    this->_game = ArcadeCore::games::NOTHING;
    this->_scene->sceneNumber = 1;
    this->_av = av;
    readDir("lib/", this->libPath);
    readDir("games/", this->gamePath);
    this->_actualLibrary = findLib();
    this->gameLoop();
}

ArcadeCore::ArcadeCore() {}

ArcadeCore::~ArcadeCore() {}


int ArcadeCore::findLib()
{
    std::vector<std::string>::iterator it;
    if (this->_av.at(1).at(0) == '.' && this->_av.at(1).at(1) == '/')
        this->_av.at(1).erase(0, 2);
    it = std::find(this->libPath.begin(), this->libPath.end(), this->_av.at(1));
    return (it - this->libPath.begin());
}

void ArcadeCore::readDir(const std::string path, std::vector<std::string> &vector)
{
    DIR *dir;
    struct dirent *dirent;
    std::string name;
    size_t pos;

    dir = opendir(path.c_str());
    while ((dirent = readdir(dir))) {
        name = dirent->d_name;
        if (name.find(".so") != std::string::npos)
            vector.push_back(path + name);
    }
    closedir(dir);
}

void ArcadeCore::swapLib(std::string str)
{
    this->_lib->destroyGraphical();
    if (!str.compare("KEYRIGHT"))
        (this->_actualLibrary + 1 > this->libPath.size()) ? this->_actualLibrary = 0 : this->_actualLibrary++;
    else if (!str.compare("KEYLEFT"))
        (this->_actualLibrary - 1 < 0) ? this->_actualLibrary = this->libPath.size() - 1 : this->_actualLibrary--;
    this->_lib->loadGraphical(this->libPath.at(this->_actualLibrary));
}

void ArcadeCore::swapGame(std::string str)
{
    if (!str.compare("KEYUP")) {
        if (this->_game != ArcadeCore::games::NOTHING)
            this->_lib->destroyGames();
        this->_game = ArcadeCore::games::PACMAN;
        this->_lib->loadGames(this->gamePath.at(0));
    }
    if (!str.compare("KEYDOWN")) {
        if (this->_game != ArcadeCore::games::NOTHING)
            this->_lib->destroyGames();
        this->_game = ArcadeCore::games::NIBBLER;
        this->_lib->loadGames(this->gamePath.at(1));
    }
}

void ArcadeCore::events()
{
    std::string event = this->_lib->_actual_graphical_lib->registerEvents();

    if (!event.compare("CLOSE"))
        this->_state = ArcadeCore::arcadeState::CLOSED;
    if (!event.compare("KEYLEFT"))
        this->swapLib("KEYLEFT");
    if (!event.compare("KEYRIGHT"))
        this->swapLib("KEYRIGHT");
    if (!event.compare("ESCAPE"))
        this->_scene->sceneNumber = 1;

    if (!event.compare("KEYUP")) {
        this->_gameToDisplay = "PACMAN";
        this->_scene->sceneNumber = 2;
        this->swapGame("p");
    }
    if (!event.compare("KEYDOWN")) {
        this->_gameToDisplay = "NIBBLER";
        this->_scene->sceneNumber = 2;
        this->swapGame("n");
    }
}

void ArcadeCore::gameLoop()
{
    this->_lib->loadGraphical(this->_av.at(1));
    this->_state = ArcadeCore::arcadeState::RUNNING;

    while (this->_state != ArcadeCore::arcadeState::CLOSED)
    {
        this->events();
        this->_scene->display(this->_lib->_actual_graphical_lib, this->_gameToDisplay);
    }
}
