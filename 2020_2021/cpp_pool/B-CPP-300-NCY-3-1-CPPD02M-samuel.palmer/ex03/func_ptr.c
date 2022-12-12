/*
** EPITECH PROJECT, 2021
** func_ptr.c
** File description:
** This is day 02 of c++ pool
*/

#include "func_ptr.h"

void print_normal(const char *str)
{
    printf("%s\n", str);
}

void print_42(const char *str)
{
    printf("42\n");
}

void print_reverse(const char *str)
{
    for (int a = strlen(str) - 1; a >= 0; a--)
        printf("%c", str[a]);
    printf("\n");
}

void print_upper(const char *str)
{
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            printf("%c", str[i] - 32);
        else
            printf("%c", str[i]);
    }
    printf("\n");
}

void do_action(action_t action, const char *str)
{
    void (*ptr_test[4]) (const char *str) = {
        print_normal,
        print_reverse,
        print_upper,
        print_42
    };
    (*ptr_test[action]) (str);
}