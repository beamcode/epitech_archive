#ifndef XBELT_H
#define XBELT_H
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>
#include "IConveyorBelt.hpp"

class PapaXmasConveyorBelt : public IConveyorBelt
{
  public:
    PapaXmasConveyorBelt();
    virtual ~PapaXmasConveyorBelt();
    bool In();
    bool Out();
    void put(Object *object);
    Object *Get();
    Object *take();
    IConveyorBelt *createConveyorBelt();
  private:
};
#endif
