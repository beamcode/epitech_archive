/*
** EPITECH PROJECT, 2018
** cpp_rush1
** File description:
** Exercice 01
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "vertex.h"

Object *new(const Class *class, ...);

typedef struct
{
    Class   base;
    int a;
    int b;
    int c;
    char *tmp;
}   VertexClass;

static void Vertex_ctor(VertexClass *this, va_list *args)
{
    this->a = va_arg(*args, int);
    this->b = va_arg(*args, int);
    this->c = va_arg(*args, int);
}

static void Vertex_dtor(VertexClass *this)
{
    free(this->tmp);
}

int count_nbb(int nbr)
{
      int z = 10;
      int count = 1;

      while ((nbr / z) >= 1) {
          count++;
          z = z * 10;
      }
      return (count);
}

char *my_itoaa(int nbr)
{
      int size = count_nbb(nbr);
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

static Object *Vertex_get_addition(const Object *this, const Object *other)
{
    const VertexClass *a = this;
    const VertexClass *b = other;
    VertexClass *result = malloc(sizeof(*a));
    Object *tmp = NULL;

    result->a = a->a + b->a;
    result->b = a->b + b->b;
    result->c = a->c + b->c;
    tmp = new(Vertex, result->a, result->b, result->c);
    return (tmp);
}

static Object *Vertex_get_substraction(VertexClass *this, VertexClass *other)
{
    const VertexClass *a = this;
    const VertexClass *b = other;
    VertexClass *result = malloc(sizeof(*a));
    Object *tmp = NULL;

    result->a = a->a - b->a;
    result->b = a->b - b->b;
    result->c = a->c - b->c;
    tmp = new(Vertex, result->a, result->b, result->c);
    return (tmp);
}

static char *Vertex_print(VertexClass *this)
{
    char *a = my_itoaa(this->a);
    char *b = my_itoaa(this->b);
    char *c = my_itoaa(this->c);
    int size = strlen(a) + strlen(b) + strlen(c) + 50;

    this->tmp = malloc(sizeof(char) * size + 1);
    snprintf(this->tmp, size, "<Vertex (%d, %d, %d)>", this->a, this->b, this->c);
    return (this->tmp);
}

static const VertexClass    _description = {
    {   /* Class struct */
        .__size__ = sizeof(VertexClass),
        .__name__ = "Vertex",
        .__ctor__ = (ctor_t)&Vertex_ctor,
        .__dtor__ = (dtor_t)&Vertex_dtor,
        .__str__ = (to_string_t)&Vertex_print,
        .__add__ = (binary_operator_t)&Vertex_get_addition,
        .__sub__ = (binary_operator_t)&Vertex_get_substraction,
        .__mul__ = NULL,
        .__div__ = NULL,
        .__eq__ = NULL,
        .__gt__ = NULL,
        .__lt__ = NULL
    },
    .a = 0,
    .b = 0,
    .c = 0,
    .tmp = NULL
};

Class const *Vertex = (const Class *)&_description;
