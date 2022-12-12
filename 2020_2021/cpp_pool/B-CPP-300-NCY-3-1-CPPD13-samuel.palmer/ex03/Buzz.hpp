/*
** EPITECH PROJECT, 2021
** Buzz.hpp
** File description:
** Buzz
*/

#ifndef BUZZ_HPP_
#define BUZZ_HPP_

#include "Toy.hpp"

class Buzz : public Toy {
    public:
        //Ctors & Dtors
        Buzz(const std::string &name);
        Buzz(const std::string &name, const std::string &filename);
        ~Buzz();

        //Members
        void speak(const std::string &str) const;
    protected:
    private:
};

#endif /* !BUZZ_HPP_ */
