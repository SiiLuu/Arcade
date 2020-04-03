/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Arcade core
*/

#include "ArcadeCore.hpp"
#include <chrono>
#include <ctime> 

ArcadeCore::ArcadeCore(std::vector<std::string> av)
{
    this->_lib = new LibLoader();
    this->_scene = new Scene();
    this->_scene->sceneNumber = 1;
    this->_av = av;
    this->readDir("lib/", this->libPath);
    this->readDir("games/", this->gamePath);
    this->_actualLibrary = findLib();
    this->_actualGame = -1;
    this->_menu = 1;
    this->info.push_back(libPath);
    this->info.push_back(gamePath);
    this->gameLoop();
    this->defaultmove = 0;
    this->_clock = 0;
    this->_lastMoveEvent = "D";
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
        (this->_actualLibrary + 1 > (this->libPath.size() - 1)) ? this->_actualLibrary = 0 : this->_actualLibrary++;
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
    this->_gamesInfos.push_back(this->_lib->_actual_game_lib->getMap());
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
        if (this->_scene->sceneNumber == 1) {
            this->_state = ArcadeCore::arcadeState::CLOSED;
        } else {
            this->_lib->destroyGames();
            this->_menu = 1;
            this->_actualGame = -1;
            this->_scene->sceneNumber = 1;
        }
    else if (!event.compare("KEYUP")) {
        this->_scene->sceneNumber = 2;
        this->swapGame("KEYUP");
    } else if (!event.compare("KEYDOWN")) {
        this->_scene->sceneNumber = 2;
        this->swapGame("KEYDOWN");
    }
    if (this->_scene->sceneNumber == 2) {
        if (!event.empty())
            this->_lastMoveEvent = event;
        if (this->_clock >= 1) {
            this->_clock = 0;
            this->_lib->_actual_game_lib->moveEnemy();
            if (!this->_lastMoveEvent.compare("Z"))
                this->_lib->_actual_game_lib->MoveForward();
            else if (!this->_lastMoveEvent.compare("Q"))
                this->_lib->_actual_game_lib->MoveLeft();
            else if (!this->_lastMoveEvent.compare("S"))
                this->_lib->_actual_game_lib->MoveBackward();
            else if (!this->_lastMoveEvent.compare("D"))
                this->_lib->_actual_game_lib->MoveRight();
        }
    }
}

void ArcadeCore::gameLoop()
{
    std::ifstream input("Scores.txt");
    std::cout << "Enter a user name :" << std::endl;
    std::getline(std::cin, this->_name);
    this->nameScore.push_back(_name);
    for (std::string line; getline(input, line);)
        this->nameScore.push_back(line);
    input.close();
    this->info.push_back(nameScore);
    this->_lib->loadGraphical(this->_av.at(1), this->info);
    this->_state = ArcadeCore::arcadeState::RUNNING;

    while (this->_state != ArcadeCore::arcadeState::CLOSED)
    {
        this->events();
        if (this->_scene->sceneNumber == 2) {
            static auto start = std::chrono::system_clock::now();
            auto end = std::chrono::system_clock::now();
            std::chrono::duration<double> elapsed_seconds = start-end;
            if (elapsed_seconds.count() <= -0.32500) {
                this->_clock += 1;
                start = std::chrono::system_clock::now();
            }
            this->_gamesInfos.push_back(this->_lib->_actual_game_lib->getMap());
            this->_score.push_back(std::to_string(this->_lib->_actual_game_lib->getScore()).c_str());
            this->_highScore.push_back(this->_lib->_actual_game_lib->getHighScore().c_str());
            this->_gamesInfos.push_back(this->_score);
            if (this->_lib->_actual_game_lib->getState() != game::state::RUNNING) {
                this->_lib->destroyGames();
                this->_menu = 1;
                this->_actualGame = -1;
                this->_scene->sceneNumber = 1;
            }
        }
        this->_scene->display(this->_lib->_actual_graphical_lib, this->_gamesInfos);
        this->_gamesInfos.clear();
        this->_score.clear();
        this->_highScore.clear();
    }
}
