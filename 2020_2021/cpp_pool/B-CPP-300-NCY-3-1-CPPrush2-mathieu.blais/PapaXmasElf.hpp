#ifndef XELF_H
#define XELF_H
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>
#include "IElf.hpp"
class PapaXmasElf : public IElf
{
  public:
    PapaXmasElf();
    virtual ~PapaXmasElf();
    void putOnTable(Object *object) const;
    Object *TakeFromTable() const;
    std::string *lookTable() const;
    bool pressIn() const;
    bool pressOut() const;
    void wrap(Object *object) const;
    void openBox() const;
    void closeBox() const;
  private:
};

#endif
