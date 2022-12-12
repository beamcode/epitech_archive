/*
** EPITECH PROJECT, 2021
** IElf
** File description:
** cppoolrush2
*/
#ifndef _ELF_
#define _ELF_
#include "Wrap.hpp"
#include "ITable.hpp"
#include "Wrap.hpp"
#include "IConveyorBelt.hpp"

class IElf {
    public:
        virtual ~IElf() {};
        virtual void putOnTable(Object *object) const = 0;
        virtual Object *TakeFromTable() const = 0;
        virtual std::string *lookTable() const = 0;
        virtual bool pressIn() const = 0;
        virtual bool pressOut() const = 0;
        virtual void wrap(Object *object) const = 0;
        virtual void openBox() const = 0;
        virtual void closeBox() const = 0;
    protected:
      ITable *_table;
      IConveyorBelt *_belt;
      Wrap *_wrap;
};

#endif /* !_ELF_ */
