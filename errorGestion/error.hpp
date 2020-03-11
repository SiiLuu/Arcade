/*
** EPITECH PROJECT, 2020
** error
** File description:
** std::exeptions
*/
#include <exception>
#include <string>

#ifndef ERROR_HPP_
#define ERROR_HPP_

class Error : public std::exception
{
    public:
        Error(int number=0, const std::string error="");
        ~Error();
        virtual const char *what() const throw();

    private:
        std::string errorType;
        int errorNumber;
};


#endif /* !ERROR_HPP_ */
