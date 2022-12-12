/*
** EPITECH PROJECT, 2021
** Priest.hpp
** File description:
** Priest
*/

#ifndef PRIEST_HPP_
#define PRIEST_HPP_

#include "Mage.hpp"

class Priest : public Mage {
    public:
        //Ctor & Dtor
        Priest(const std::string &name, int level);
        ~Priest();

        //Members
        int CloseAttack();
        int RangeAttack();
        void Heal();
    protected:
    private:
};

#endif /* !PRIEST_HPP_ */
