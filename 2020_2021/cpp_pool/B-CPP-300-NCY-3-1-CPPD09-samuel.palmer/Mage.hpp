/*
** EPITECH PROJECT, 2021
** Mage.hpp
** File description:
** Mage
*/

#ifndef MAGE_HPP_
#define MAGE_HPP_

#include "Character.hpp"

class Mage : virtual public Character {
    public:
        //Ctor & Dtor
        Mage(const std::string &name, int level);
        ~Mage();

        //Members
        Mage(std::string &name, int level);
        int CloseAttack();
        void RestorePower();
        int RangeAttack();

    protected:
    private:
};

#endif /* !MAGE_HPP_ */
