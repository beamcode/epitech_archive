/*
** EPITECH PROJECT, 2021
** Parts.hpp
** File description:
** Parts
*/

#ifndef PARTS_HPP_
#define PARTS_HPP_

#include <iostream>
#include <string>

class Arms {
    public:
        Arms();
        Arms(std::string &serial, bool functional);
        ~Arms();

        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
    protected:
    private:
        std::string _serial;
        bool _functional;
};

class Legs {
    public:
        Legs();
        Legs(std::string &serial, bool functional);
        ~Legs();

        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
    protected:
    private:
        std::string _serial;
        bool _functional;
};

class Head {
    public:
        Head();
        Head(std::string &serial, bool functional);
        ~Head();

        bool isFunctional() const;
        std::string serial() const;
        void informations() const;
    protected:
    private:
        std::string _serial;
        bool _functional;
};

#endif /* !PARTS_HPP_ */