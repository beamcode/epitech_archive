#ifndef BELT_H
#define BELT_H
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>
#include "Object.hpp"

class IConveyorBelt
{
  public:
    virtual ~IConveyorBelt() {};
    virtual bool In() = 0;
    virtual bool Out() = 0;
    virtual void put(Object *object) = 0;
    virtual Object *take() = 0;
  protected:
    bool _occuped;
    Object *_beltContent;
};
#endif
