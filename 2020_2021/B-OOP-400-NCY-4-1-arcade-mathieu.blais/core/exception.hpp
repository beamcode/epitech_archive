/*
** EPITECH PROJECT, 2021
** exception
** File description:
** arcade
*/

#ifndef exception_hpp
#define exception_hpp

#include <dlfcn.h>
#include <iostream>
#include <string>
#include <iomanip>
#include <string>
#include <exception>

class LoadException : public std::runtime_error
    {
    public:
        LoadException(std::string const &file) : std::runtime_error("can not load " + file) {}
        virtual ~LoadException() throw() {}
    };

    class IncompleteException : public std::runtime_error
    {
    public:
        IncompleteException(std::string const &file) : std::runtime_error("no implemented function " + file) {}
        virtual ~IncompleteException() throw()
        {}
    };

#endif /* !exception */
