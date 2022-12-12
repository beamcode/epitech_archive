#include "Toy.hpp"

#ifndef Ted
#define Ted
class Teddy : public Toy
{
    public:
        Teddy(const std::string &name);
        virtual ~Teddy();
        void isTaken() const;
};

#endif
