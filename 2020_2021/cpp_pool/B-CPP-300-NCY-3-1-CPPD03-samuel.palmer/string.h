/*
** EPITECH PROJECT, 2021
** string.h
** File description:
** This is day 2 of c++ pool
*/

#ifndef string
#define string

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct string_s
{
    char *str;
} string_t;

void string_init(string_t *this, const char *s);
void string_destroy(string_t *this);
void append_s(string_t *this, const string_t *ap);
void assign_c(string_t *this, const char *s);
void assign_s(string_t *this, const string_t *str);

#endif