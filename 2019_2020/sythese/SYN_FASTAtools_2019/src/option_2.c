/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "../include/my.h"

void process_two(char **str)
{
    for (int a = 0; str[a]; a++) {
        if (strchr(str[a], '>') != NULL)
            continue;
        for (int b = 0; str[a][b] != '\0'; b++) {
            if (str[a][b] == 'T')
                str[a][b] = 'U';
        }
    }
}

void do_two(char **str)
{
    process_one(str);
    process_two(str);
    my_putarray(str);
}