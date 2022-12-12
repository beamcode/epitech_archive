/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

char *get_input(st_s *st)
{
    char *line = NULL;
    size_t size = 0;

    while (1) {
        my_putstr("attack: ");
        getline(&line, &size, stdin);
        if (check_input(line) == 0)
            break;
        my_putstr("wrong position\n");
    }
    return (line);
}