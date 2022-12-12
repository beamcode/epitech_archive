/*
** EPITECH PROJECT, 2021
** Warrior.hpp
** File description:
** Warrior
*/

#ifndef WARRIOR_HPP_
#define WARRIOR_HPP_

#include "Character.hpp"

class Warrior : public virtual Character {
    public:
        //Ctor & Dtor
        Warrior(const std::string &name, int level);
        ~Warrior();

        //Members
        int CloseAttack();
        int RangeAttack();
    protected:
        const std::string _weaponName;
    private:
};

#endif /* !WARRIOR_HPP_ */