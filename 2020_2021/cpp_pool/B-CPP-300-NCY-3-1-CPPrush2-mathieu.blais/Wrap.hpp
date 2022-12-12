#ifndef WRAP_H
#define WRAP_H
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>
#include "Object.hpp"

class Wrap : public Object {
  public:
    Wrap(const std::string &name);
    Wrap();
    virtual ~Wrap();
    bool getWrap() const;
    void wrapMeThat(Object*);
    virtual void openMe() = 0;
    virtual void closeMe() = 0;
    bool isOpen() const;
    enum BoxStatus {
      CLOSED,
      OPEN
    };
    BoxStatus Status;
  protected:
    bool _iswrap;
    Object *obj;
};

#endif
