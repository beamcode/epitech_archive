/*
** EPITECH PROJECT, 2021
** z.c
** File description:
** this is day one of c++ pool
*/

#include "string.h"

int main(void)
{
    string_t s;
    string_t t;
    const char *test = "i dont like valgrind";

    string_init(&s, "Hello World");
    printf("%s\n", s.str);
    string_destroy(&s);

    assign_s(&s, &t);
    printf("%s\n", s.str);
    string_destroy(&s);

    return 0;
    assign_c(&s, test);
    printf("%s\n", s.str);
    string_destroy(&s);

    return (0) ;
}