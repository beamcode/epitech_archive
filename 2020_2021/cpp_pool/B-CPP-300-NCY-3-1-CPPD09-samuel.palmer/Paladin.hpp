/*
** EPITECH PROJECT, 2021
** Paladin.hpp
** File description:
** Paladin
*/

#ifndef PALADIN_HPP_
#define PALADIN_HPP_

#include "Warrior.hpp"
#include "Priest.hpp"

class Paladin : public Warrior, public Priest {
    public:
        Paladin(const std::string &name, int level);
        ~Paladin();

        int CloseAttack();
        int Intercept();
        using Warrior::CloseAttack;
        using Priest::RangeAttack;
        using Priest::Heal;
    protected:
    private:
};

#endif /* !PALADIN_HPP_ */
