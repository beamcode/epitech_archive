/*
** EPITECH PROJECT, 2021
** Picture.hpp
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>
#include <fstream>
#include <string>

class Picture {
    public:
        //Ctors & Dtors
        Picture(const std::string &file);
        Picture() : data("") {};
        ~Picture();

        //Members
        bool getPictureFromFile(const std::string &file);
        std::string getData() const { return data; };

        //Variables
        std::string data;
    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
