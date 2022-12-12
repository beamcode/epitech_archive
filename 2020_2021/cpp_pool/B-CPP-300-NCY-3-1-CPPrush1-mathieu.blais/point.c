/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 01
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "point.h"

Object *new(const Class *class, ...);

typedef struct
{
    Class   base;
    int a;
    int b;
    char *tmp;
}   PointClass;

static void Point_ctor(PointClass *this, va_list *args)
{
    this->a = va_arg(*args, int);
    this->b = va_arg(*args, int);
}

static void Point_dtor(PointClass *this)
{
    free(this->tmp);
}

int count_nb(int nbr)
{
      int z = 10;
      int count = 1;

      while ((nbr / z) >= 1) {
          count++;
          z = z * 10;
      }
      return (count);
}

char *my_itoa(int nbr)
{
      int size = count_nb(nbr);
      char *str;

      str = malloc(sizeof(char) * size + 1);
      if (str == NULL)
          return (NULL);
      str[size] = '\0';
      while (size--) {
          str[size] = nbr % 10 + '0';
          nbr = nbr / 10;
      }
      return (str);
}

static Object *Point_get_addition(const Object *this, const Object *other)
{
    const PointClass *a = this;
    const PointClass *b = other;
    PointClass *result = malloc(sizeof(*a));
    Object *tmp = NULL;

    result->a = a->a + b->a;
    result->b = a->b + b->b;
    tmp = new(Point, result->a, result->b);
    return (tmp);
}

static Object *Point_get_substraction(PointClass *this, PointClass *other)
{
    const PointClass *a = this;
    const PointClass *b = other;
    PointClass *result = malloc(sizeof(*a));
    Object *tmp = NULL;

    result->a = a->a - b->a;
    result->b = a->b - b->b;
    tmp = new(Point, result->a, result->b);
    return (tmp);
}

static char *Point_print(PointClass *this)
{
    char *a = my_itoa(this->a);
    char *b = my_itoa(this->b);
    int size = strlen(a) + strlen(b) + 50;

    this->tmp = malloc(sizeof(char) * size + 1);
    snprintf(this->tmp, size, "<Point (%d, %d)>", this->a, this->b);
    return (this->tmp);
}

static const PointClass    _description = {
    {   /* Class struct */
        .__size__ = sizeof(PointClass),
        .__name__ = "Point",
        .__ctor__ = (ctor_t)&Point_ctor,
        .__dtor__ = (dtor_t)&Point_dtor,
        .__str__ = (to_string_t)&Point_print,
        .__add__ = (binary_operator_t)&Point_get_addition,
        .__sub__ = (binary_operator_t)&Point_get_substraction,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .a = 0,
    .b = 0,
    .tmp = NULL
};

Class const *Point = (const Class *)&_description;
