#include "LittlePony.hpp"

LittlePony::LittlePony(const std::string &name) : Toy(name)
{
    this->_name = name;
}

LittlePony::~LittlePony()
{

}

void LittlePony::isTaken() const
{
    std::cout << "yo man" << std::endl;
}
