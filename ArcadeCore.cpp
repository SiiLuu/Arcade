/*
** EPITECH PROJECT, 2020
** Arcade
** File description:
** Arcade core
*/

#include "ArcadeCore.hpp"

ArcadeCore::ArcadeCore()
{
    this->gameLoop();
}

ArcadeCore::~ArcadeCore()
{
}

void ArcadeCore::gameLoop()
{
    this->_lib->load();
}
