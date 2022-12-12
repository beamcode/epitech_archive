#include "ConveyorBeltRand.hpp"
#include "GiftPaper.hpp"
#include "Box.hpp"

ConveyorBeltRand::ConveyorBeltRand()
{
    int b = rand() % 2;

    if (b == 0)
        this->_beltContent = new GiftPaper("GiftPaper");
    else
        this->_beltContent = new Box("Box");
}


ConveyorBeltRand::~ConveyorBeltRand()
{

}
