/*
** EPITECH PROJECT, 2020
** errorGestion.cpp
** File description:
** Arcade
*/

#include "errorGestion.hpp"

errorGestion::errorGestion(int ac, std::vector<std::string> av)
{
    this->check = false;
    this->readDir(ac, av);
    this->argsGestion(ac, av);
}

errorGestion::~errorGestion() {}

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

void errorGestion::argsGestion(int ac, std::vector<std::string> av)
{
    void *handle;

    try
    {
        if (ac != 2)
            throw Error(1, "You need almost add one lib with this binary.");
        if (this->check == false)
            throw Error(2, "Wrong library.");
        handle = dlopen(av.at(1).c_str(), RTLD_LAZY);
        if (!handle) {
            dlclose(handle);
            throw Error(3, "Cannot open this shared libray");
        }
    }
    catch(std::exception const &error) {
        std::cerr << "Error : " << error.what() << std::endl;
        std::exit(84);
    }
}
