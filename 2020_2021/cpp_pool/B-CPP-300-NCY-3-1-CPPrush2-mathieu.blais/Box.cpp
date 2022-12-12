#include "Box.hpp"

Box::Box(const std::string &name) : Wrap(name)
{
    this->_name = name;
    this->openMe();
}

Box::Box()
{
    this->_name = "Box";
}

Box::~Box()
{

}

void Box::openMe()
{
    if (this->Status == CLOSED)
        this->Status = OPEN;
}

void Box::closeMe()
{
  if (this->Status == OPEN)
      this->Status = CLOSED;
}
