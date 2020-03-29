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
    this->_scene->sceneNumber = 1;
    this->_av = av;
    readDir("lib/", this->libPath);
    readDir("games/", this->gamePath);
    this->_actualLibrary = findLib();
    this->_actualGame = -1;
    this->_menu = 1;
    this->info.push_back(libPath);
    this->info.push_back(gamePath);
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
    this->_lib->loadGraphical(this->libPath.at(this->_actualLibrary), this->info);
}

void ArcadeCore::swapGame(std::string str)
{
    if (!str.compare("KEYUP")) {
        if (this->_menu != 1)
            this->_lib->destroyGames();
        (this->_actualGame + 1 > this->gamePath.size() - 1) ? this->_actualGame = 0 : this->_actualGame++;
        this->_menu = 0;
    }
    else if (!str.compare("KEYDOWN")) {
        if (this->_menu != 1)
            this->_lib->destroyGames();
        (this->_actualGame - 1 < 0) ? this->_actualGame = this->gamePath.size() - 1 : this->_actualGame--;
        this->_menu = 0;
    }
    this->_lib->loadGames(this->gamePath.at(this->_actualGame));
}

void ArcadeCore::events()
{
    std::string event = this->_lib->_actual_graphical_lib->registerEvents();

    if (!event.compare("CLOSE"))
        this->_state = ArcadeCore::arcadeState::CLOSED;
    else if (!event.compare("KEYLEFT"))
        this->swapLib("KEYLEFT");
    else if (!event.compare("KEYRIGHT"))
        this->swapLib("KEYRIGHT");
    else if (!event.compare("ESCAPE"))
        (this->_scene->sceneNumber == 1) ? this->_state = ArcadeCore::arcadeState::CLOSED : this->_scene->sceneNumber = 1;
    else if (!event.compare("KEYUP")) {
        this->_scene->sceneNumber = 2;
        this->swapGame("KEYUP");
    }
    else if (!event.compare("KEYDOWN")) {
        this->_scene->sceneNumber = 2;
        this->swapGame("KEYDOWN");
    }
}

void ArcadeCore::gameLoop()
{
    std::cout << "Enter a user name :" << std::endl;
    std::getline(std::cin, this->_name);
    this->nameScore.push_back(_name);
    this->info.push_back(nameScore);
    this->_lib->loadGraphical(this->_av.at(1), this->info);
    this->_state = ArcadeCore::arcadeState::RUNNING;
    while (this->_state != ArcadeCore::arcadeState::CLOSED)
    {
        this->events();
        (this->_menu != 1) ? this->_scene->display(this->_lib->_actual_graphical_lib, this->gamePath.at(this->_actualGame), this->info) : this->_scene->display(this->_lib->_actual_graphical_lib, "menu", this->info);
    }
}
