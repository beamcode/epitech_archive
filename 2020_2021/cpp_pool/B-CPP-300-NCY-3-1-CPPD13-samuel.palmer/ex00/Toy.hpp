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
            ALIEN,
        };
        Toy(ToyType type, const std::string &name, const std::string &filename);
        Toy() : toy_type(BASIC_TOY), _name("toy"), _picture(Picture()) {};
        ~Toy();

        //Members
        ToyType getType() const { return (toy_type); };
        std::string getName() const { return (_name); };
        void setName(const std::string &name) { _name = name; };
        bool setAscii(const std::string &filename);
        std::string getAscii() const { return (_picture.getData()); };
    protected:
    private:
        ToyType toy_type;
        std::string _name;
        Picture _picture;
};

#endif /* !TOY_HPP_ */
