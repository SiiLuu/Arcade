/*
** EPITECH PROJECT, 2020
** errorGestion.cpp
** File description:
** Arcade
*/

#include "error.hpp"
#include <iostream>
#include <vector>
#include <dlfcn.h>
#include <dirent.h>

#ifndef ERRORGESTION_HPP_
#define ERRORGESTION_HPP_

class errorGestion : public Error
{
    private:
        void argsGestion(int ac, std::vector<std::string> av);
        void readDir(int ac, std::vector<std::string> av);
        void help();
        std::vector<std::string> vector;
        bool check;

    public:
        int _error;
        errorGestion(int ac, std::vector<std::string> av);
        ~errorGestion();
};


#endif /* !ERRORGESTION_HPP_ */
