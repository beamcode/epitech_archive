/*
** EPITECH PROJECT, 2021
** Hunter.hpp
** File description:
** Hunter
*/

#ifndef HUNTER_HPP_
#define HUNTER_HPP_

#include "Warrior.hpp"

class Hunter : public Warrior {
    public:
        Hunter(const std::string &name, int level);
        ~Hunter();

        int RangeAttack();
        void RestorePower();
        int CloseAttack();
    protected:
        const std::string _weaponName;
    private:
};

#endif /* !HUNTER_HPP_ */
