/*
** EPITECH PROJECT, 2021
** Errors.hpp
** File description:
** Errors
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>
#include <iostream>
#include <exception>

class NasaError : public std::exception
{
    public:
        NasaError(std::string const &message,
                std::string const &component = "Unknown");
        virtual ~NasaError() throw() {}

        virtual const char *what() const noexcept;
        virtual const std::string &getComponent() const;
    private:
        std::string _componentname;
        std::string _message;
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message,
                std::string const &component = "Unknown");
        virtual ~MissionCriticalError() throw() {}
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message,
                std::string const &component = "Unknown");
        virtual ~LifeCriticalError() throw() {}
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message,
                std::string const &component = "Unknown");
        virtual ~UserError() throw() {}
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
        virtual ~CommunicationError() throw() {}
};

#endif
