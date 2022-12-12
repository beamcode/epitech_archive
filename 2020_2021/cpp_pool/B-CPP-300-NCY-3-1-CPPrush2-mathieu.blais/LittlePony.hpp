#include "Toy.hpp"

#ifndef Pony
#define Pony

class LittlePony : public Toy
{
  public:
    LittlePony(const std::string &name);
    virtual ~LittlePony();
    void isTaken() const;
};

#endif
