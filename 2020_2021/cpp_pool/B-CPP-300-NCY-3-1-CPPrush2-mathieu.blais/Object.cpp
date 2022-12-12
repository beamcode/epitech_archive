#include "Object.hpp"

Object::Object(const std::string &name)
{
    this->_name = name;
}

Object::Object()
{

}

Object::~Object()
{

}

std::string Object::getName() const
{
    return(this->_name);
}

std::ostream &operator<<(std::ostream &os, Object const &object)
{
    os << "Object name : " << object.getName() << std::endl;
    return (os);
}
