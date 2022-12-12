/*
** EPITECH PROJECT, 2021
** Woody.hpp
** File description:
** Woody
*/

#ifndef WOODY_HPP_
#define WOODY_HPP_

#include "Toy.hpp"

class Woody : public Toy {
    public:
        //Ctors & Dtors
        Woody(const std::string &name);
        Woody(const std::string &name, const std::string &filename);
        ~Woody();

        //Members
    protected:
    private:
};

#endif /* !WOODY_HPP_ */
