#ifndef BOX_H
#define BOX_H
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>
#include "Wrap.hpp"

class Box : public Wrap
{
  public:
    Box(const std::string &name);
    Box();
    virtual ~Box();
    void openMe();
    void closeMe();
  private:
};
#endif
