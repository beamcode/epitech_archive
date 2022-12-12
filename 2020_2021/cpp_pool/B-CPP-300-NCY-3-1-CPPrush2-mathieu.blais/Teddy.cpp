#include "Teddy.hpp"

Teddy::Teddy(const std::string &name) : Toy(name)
{
    this->_name = name;
}

Teddy::~Teddy()
{

}

void Teddy::isTaken() const
{
    std::cout << "gra hu" << std::endl;
}
