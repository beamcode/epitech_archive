#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>
#include "PapaXmasElf.hpp"
#include "ITable.hpp"

PapaXmasElf::PapaXmasElf()
{

}

PapaXmasElf::~PapaXmasElf()
{

}

void PapaXmasElf::putOnTable(Object *object) const
{
    if (object == NULL)
        return;
    this->_table->put(object);
}

Object *PapaXmasElf::TakeFromTable() const
{
    return (this->_table->take());
}

std::string *PapaXmasElf::lookTable() const
{
    return (this->_table->look());
}

bool PapaXmasElf::pressIn() const
{
    return (this->_belt->In());
}

bool PapaXmasElf::pressOut() const
{
    return (this->_belt->Out());
}

void PapaXmasElf::wrap(Object *object) const
{
    if (object == NULL)
        return;
    this->pressIn();
    this->_wrap->wrapMeThat(object);
    this->pressOut();
}

void PapaXmasElf::openBox() const
{
    this->_wrap->openMe();
}

void PapaXmasElf::closeBox() const
{
    this->_wrap->closeMe();
}
