#include "PapaXmasConveyorBelt.hpp"
#include "Box.hpp"
#include "ConveyorBeltRand.hpp"

PapaXmasConveyorBelt::PapaXmasConveyorBelt()
{
    this->_occuped = false;
    this->_beltContent = NULL;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt()
{
    delete this->_beltContent;
}

IConveyorBelt *PapaXmasConveyorBelt::createConveyorBelt()
{
    return (new PapaXmasConveyorBelt);
}

Object *PapaXmasConveyorBelt::Get()
{
   if (this->_occuped == true)
       return (this->_beltContent);
    else
        std::cerr << "There is nothing on the conveyor belt" << std::endl;
        return (NULL);
}

bool PapaXmasConveyorBelt::In()
{
    if (this->_occuped == true)
      return (false);
    ConveyorBeltRand();
    this->_occuped = false;
    return (true);
}

bool PapaXmasConveyorBelt::Out()
{
  if (this->_occuped == true)
    return (false);
    this->_beltContent = NULL;
    this->_occuped = false;
    return (true);
}

void PapaXmasConveyorBelt::put(Object *object)
{
    if (object == NULL)
        return;
    if (this->_occuped == true) {
        std::cerr << "The Conveyor belt is full" << std::endl;
        return;
    }
    this->_occuped = true;
    this->_beltContent = object;
}

Object *PapaXmasConveyorBelt::take()
{
  if (this->_occuped == true) {
      this->_occuped = false;
  }
  Object *tmp = this->_beltContent;
  this->_beltContent = NULL;
  return (tmp);
}
