/*
** EPITECH PROJECT, 2020
** error
** File description:
** exeption
*/
#include "error.hpp"

Error::Error(int number, const std::string error) : errorNumber(number), errorType(error)
{
}

Error::~Error()
{
}

const char* Error::what() const throw()
{
    return (this->errorType.c_str());
}
