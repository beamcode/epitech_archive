#ifndef XTABLE_H
#define XTABLE_H
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>
#include "ITable.hpp"

class PapaXmasTable : public ITable
{
  public:
    PapaXmasTable();
    virtual ~PapaXmasTable();
    void put(Object *object);
    Object *take();
    std::string *look();
    ITable *createTable();
  private:

};
#endif
