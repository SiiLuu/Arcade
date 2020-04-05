/*
** EPITECH PROJECT, 2020
** errorGestion.cpp
** File description:
** Arcade
*/

#include "errorGestion.hpp"

errorGestion::errorGestion(int ac, std::vector<std::string> av)
{
    this->_error = 0;
    this->check = false;
    this->readDir(ac, av);
    this->argsGestion(ac, av);
}

errorGestion::~errorGestion()
{
}

void errorGestion::readDir(int ac, std::vector<std::string> av)
{
    DIR *dir;
    struct dirent *dirent;
    std::string name;
    size_t pos;

    if (ac == 2) {
        dir = opendir("lib/");
        while ((dirent = readdir(dir))) {
            name = dirent->d_name;
            if (name.find(".so") != std::string::npos)
                this->vector.push_back("lib/" + name);
        }
        closedir(dir);
        for (int i = 0; i < this->vector.size(); i++)
            if (av[1].compare(this->vector.at(i)) == 0 || av[1].compare("./" + this->vector.at(i)) == 0)
                this->check = true;
    }
}

void errorGestion::help()
{
    std::cout << "USAGE:" << std::endl;
    std::cout << "\t\t./arcade [\"Your graphical shared library\"]" << std::endl;
    std::cout << "DESCRIPTION:" << std::endl;
    std::cout << "\t\tPlay different games on different graphical library" << std::endl;
    std::cout << "\t\ttry to be better at every single one of your games." << std::endl;
    std::cout << "HOW TO PLAY:" << std::endl;
    std::cout << "\t\tKEY_LEFT : Go to the previous graphical library" << std::endl;
    std::cout << "\t\tKEY_RIGHT : Go to the next graphical library" << std::endl;
    std::cout << "\t\tKEY_UP : Go to the previous game" << std::endl;
    std::cout << "\t\tKEY_DOWN : Go to the next game" << std::endl;
    std::cout << "\t\tZ : Go forward (only in game)" << std::endl;
    std::cout << "\t\tQ : Go backward (only in game)" << std::endl;
    std::cout << "\t\tS : Go to the left (only in game)" << std::endl;
    std::cout << "\t\tD : Go to the right (only in game)" << std::endl;
    std::cout << "\t\tESCAPE : Go back to the menu or quit the game" << std::endl;
}

void errorGestion::argsGestion(int ac, std::vector<std::string> av)
{
    void *handle;

    try {
        if (ac != 2)
            throw Error(1, "You need almost add one lib with this binary.");
        if (!av.at(1).compare("-h")) {
            this->_error = 1;
            this->help();
        }
        if (this->check == false  && this->_error == 0) {
            this->_error = 1;
            throw Error(2, "Wrong library.");
        }
        if (!(handle = dlopen(av.at(1).c_str(), RTLD_LAZY)) && this->_error == 0) {
            dlclose(handle);
            throw Error(3, "Cannot open this shared libray");
        }
    }
    catch(std::exception const &error) {
        std::cerr << "Error : " << error.what() << std::endl;
        this->_error = 1;
    }
}
