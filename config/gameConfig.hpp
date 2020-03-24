/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** class game config
*/
#include <map>
#include <vector>
#include <string>
#include "../ArcadeCore.hpp"

#ifndef GAMECONFIG_HPP_
#define GAMECONFIG_HPP_

class gameConfig : public ArcadeCore
{
public:
    gameConfig();
    ~gameConfig();

    void parseEvent();

private:
    std::map<std::string, std::string> configAction;
};

#endif /* !GAMECONFIG_HPP_ */
