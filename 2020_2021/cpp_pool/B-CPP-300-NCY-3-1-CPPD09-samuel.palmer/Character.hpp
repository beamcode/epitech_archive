/*
** EPITECH PROJECT, 2021
** Character.cpp
** File description:
** Character
*/

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_

#include <iostream>
#include <iomanip>
#include <string>

class Character {
    public:
        //Ctor &Dtor
        Character(const std::string &name, int level);
        ~Character();

        //Member
        const std::string &getName() const;
        int getLvl() const;
        int getPv() const;
        int getPower() const;
        int CloseAttack();
        void Heal();
        void RestorePower();
        int RangeAttack();
        void TakeDamage(int damage);
        enum AttackRange {
            CLOSE,
            RANGE,
        };
        AttackRange Range;
    protected:
        std::string _name;
        std::string _race;
        int _intelligence;
        int _strength;
        int _stamina;
        int _agility;
        int _energy;
        int _spirit;
        int _level;
        int _pv;
    private:
};

#endif /* !CHARACTER_HPP_ */
