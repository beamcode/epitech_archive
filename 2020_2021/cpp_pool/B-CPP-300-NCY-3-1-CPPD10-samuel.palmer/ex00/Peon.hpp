/*
** EPITECH PROJECT, 2021
** Peon.hpp
** File description:
** Peon
*/

#ifndef PEON_HPP_
#define PEON_HPP_

#include "Victim.hpp"

class Peon : public Victim {
    public:
        Peon(const std::string &name);
        ~Peon();

        //Members
        void getPolymorphed() const;
    protected:
    private:
};

#endif /* !PEON_HPP_ */