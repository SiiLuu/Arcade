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
    std::cout << it - this->libPath.begin() << std::endl;
    std::cout << this->libPath.size() << std::endl;
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

void ArcadeCore::eventInSfml()
{
    std::string event = this->_lib->_actual_graphical_lib->registerEvents();

    if (!event.compare("CLOSE"))
        this->_library = ArcadeCore::library::NONE;
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

void ArcadeCore::eventInSdl()
{
    std::string event = this->_lib->_actual_graphical_lib->registerEvents();

    if (event == "CLOSE")
        this->_library = ArcadeCore::library::NONE;
    if (event == "1")
        this->swapLib("1");
    if (event == "3")
        this->swapLib("3");
    if (!event.compare("ESCAPE"))
        this->_scene->sceneNumber = 1;
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
