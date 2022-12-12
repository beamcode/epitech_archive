/*
** EPITECH PROJECT, 2021
** Errors.cpp
** File description:
** Errors
*/

#include "Errors.hpp"

//Ctors & Dtors
NasaError::NasaError(std::string const &message, std::string const &component)
{
    this->_message = message;
    this->_componentname = component;
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component)
: NasaError(message, component) {}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component)
: NasaError(message, component) {}

UserError::UserError(std::string const &message, std::string const &component)
: NasaError(message, component) {}

CommunicationError::CommunicationError(std::string const &message)
: NasaError(message, "CommunicationDevice") {}

//Members
const std::string &NasaError::getComponent() const { return (_componentname); }

const char *NasaError::what() const noexcept { return (_message.c_str()); }
