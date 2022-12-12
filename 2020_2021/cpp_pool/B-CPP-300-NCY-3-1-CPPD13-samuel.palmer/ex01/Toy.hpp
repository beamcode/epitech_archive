/*
** EPITECH PROJECT, 2021
** Toy.hpp
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"

class Toy {
    public:
        //Ctors & Dtors
        enum ToyType {
            BASIC_TOY,
            ALIEN
        };
        Toy();
        Toy(const Toy &toy);
        Toy &operator=(const Toy &toy);
        Toy(ToyType type, const std::string &name, const std::string &fillename);
        ~Toy();

        //Members
        ToyType getType() const;
        Picture getPicture() const;
        std::string getName() const;
        std::string getAscii() const;
        void setName(const std::string &name);
        bool setAscii(const std::string &file);
    protected:
    private:
        ToyType _toytype;
        std::string _name;
        Picture _picture;
};

#endif /* !TOY_HPP_ */
