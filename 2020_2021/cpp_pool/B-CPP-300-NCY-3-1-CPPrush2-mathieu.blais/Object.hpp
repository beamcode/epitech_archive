#include <iomanip>
#include <iostream>

#ifndef Obj
#define Obj

class Object
{
    public:
        Object(const std::string &name);
        Object();
        virtual ~Object();
        std::string getName() const;
    protected:
        std::string _name;
};
std::ostream &operator<<(std::ostream &os, Object const &object);
#endif
