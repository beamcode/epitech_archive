#ifndef TABLE_H
#define TABLE_H
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>
#include "Object.hpp"

class ITable
{
  public:
    ~ITable() {};
    virtual void put(Object *object) = 0;
    virtual Object *take() = 0;
    virtual std::string *look() = 0;
  protected:
    int _number;
    Object *_tableContent[10];
};
#endif
