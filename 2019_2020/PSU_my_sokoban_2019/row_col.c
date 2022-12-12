/*
** EPITECH PROJECT, 2019
** row_col.c
** File description:
** counts rows and colums
*/

#include "include/sokoban.h"

int count_rows(map_t *map)
{
    int rows = 0;

    for (int i = 0; map->mapstring[i] != '\0'; i++)
        if (map->mapstring[i] == '\n')
            rows++;
    rows++;
    return rows;
}

int count_colums(map_t *map)
{
    int a = 0;
    int b = 0;

    for (int i = 0; map->mapstring[i] != '\0'; i++) {
        for (int i = 0; map->mapstring[i] != '\n'; i++)
            a++;
        if (a > b)
            b = a;
    }
    return b;
}