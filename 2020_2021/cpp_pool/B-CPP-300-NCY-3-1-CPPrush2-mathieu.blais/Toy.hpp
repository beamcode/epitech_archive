#include "Object.hpp"

#ifndef To
#define To

class Toy : public Object
{
    public:
        Toy(const std::string &name);
        ~Toy();
};

#endif
