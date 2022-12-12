/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 01
*/
#include "new.h"
#include "player.h"
#include "object.h"
#include "raise.h"
#include <stdarg.h>

void delete(Object *ptr)
{
    Class *test = NULL;

    test = ptr;
    test->__dtor__(ptr);
    free(ptr);
    ptr = NULL;
}

Object *va_new(const Class *class, va_list *ap)
{
    Object *new = NULL;

    if (class == NULL)
        raise("class is NULL");
    new = malloc(class->__size__);
    if (new == NULL)
        raise("Out of memory");
    new = memcpy(new, class, class->__size__);
    if (new == NULL)
        raise("Out of memory");
    class->__ctor__(new, ap);
    return (new);
}

Object *new(const Class *class, ...)
{
    Object *new = NULL;
    va_list ap;

    va_start(ap, class);
    new = va_new(class, &ap);
    va_end(ap);
    return (new);
}
