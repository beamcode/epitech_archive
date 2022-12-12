/*
** EPITECH PROJECT, 2021
** KoalaBot.cpp
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"
#include "Parts.hpp"

//Ctor
KoalaBot::KoalaBot() : _serial("Bob-01") {}
KoalaBot::KoalaBot(const std::string &serial) : _serial(serial) {}

//Dtor
KoalaBot::~KoalaBot() {}

//Members
void KoalaBot::swapParts(Arms &arms) { arms = this->_arms; }
void KoalaBot::swapParts(Legs &legs) { legs = this->_legs; }
void KoalaBot::swapParts(Head &head) { head = this->_head; }

void KoalaBot::setParts(const Arms &arms) { this->_arms = arms; }
void KoalaBot::setParts(const Legs &legs) { this->_legs = legs; }
void KoalaBot::setParts(const Head &head) { this->_head = head; }

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << this->_serial << std::endl;
    this->_arms.informations();
    this->_legs.informations();
    this->_head.informations();
}

bool KoalaBot::status() const
{
    return (this->_arms.isFunctional() && this->_legs.isFunctional()
    && this->_head.isFunctional() ? true : false);
}