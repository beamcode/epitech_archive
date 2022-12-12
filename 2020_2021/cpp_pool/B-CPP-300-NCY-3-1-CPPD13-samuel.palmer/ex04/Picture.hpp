/*
** EPITECH PROJECT, 2021
** Picture.hpp
** File description:
** Picture
*/

#ifndef PICTURE_HPP_
#define PICTURE_HPP_

#include <iostream>
#include <string>
#include <fstream>

class Picture {
    public:
        //Ctors & Dtors
        Picture();
        Picture(const Picture &pic);
        Picture(const std::string &pic);
        Picture &operator=(const Picture &pic);
        ~Picture();

        //Members
        std::string getData() const;
        bool getPictureFromFile(const std::string &);
        void setAscii(const std::string &str);
        std::string data;
    protected:
    private:
};

#endif /* !PICTURE_HPP_ */
