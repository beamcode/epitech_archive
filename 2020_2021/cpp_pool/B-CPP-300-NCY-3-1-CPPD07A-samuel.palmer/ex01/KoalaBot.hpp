/*
** EPITECH PROJECT, 2021
** KoalaBot.hpp
** File description:
** KoalaBot
*/

#ifndef KOALABOT_HPP_
#define KOALABOT_HPP_

#include "Parts.hpp"

class KoalaBot {
    public:
        //Dtor & Ctor
        KoalaBot(const std::string &serial);
        KoalaBot();
        ~KoalaBot();

        //Members
        void setParts(const Arms &arms);
        void setParts(const Legs &legs);
        void setParts(const Head &head);
        void swapParts(Arms &arms);
        void swapParts(Legs &legs);
        void swapParts(Head &head);
        void informations() const;
        bool status() const;
    protected:
    private:
        Arms _arms;
        Legs _legs;
        Head _head;
        std::string _serial;
};

#endif /* !KOALABOT_HPP_ */