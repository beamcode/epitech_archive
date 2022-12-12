#ifndef GIFT_H
#define GIFT_H
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>
#include "Wrap.hpp"

class GiftPaper : public Wrap
{
  public:
    GiftPaper(const std::string &name);
    GiftPaper();
    virtual ~GiftPaper();
    void openMe();
    void closeMe();
  private:
};
#endif
