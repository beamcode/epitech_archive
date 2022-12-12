/*
** EPITECH PROJECT, 2021
** z.c
** File description:
** this is day one of c++ pool
*/

#include "string.h"

void append_s(string_t *this, const string_t *ap)
{
    char *tmp = malloc(strlen(this->str) + strlen(ap->str) + 1);

    strcpy(tmp, this->str);
    strcat(tmp, ap->str);
    this->str = tmp;
}

void assign_c(string_t *this, const char *s)
{
    this->str = strdup(s);
}

void assign_s(string_t *this, const string_t *str)
{
    assign_c(this, str->str);
}

void string_init(string_t *this, const char *s)
{
    this->str = strdup(s);
}

void string_destroy(string_t *this)
{
    free(this->str);
}