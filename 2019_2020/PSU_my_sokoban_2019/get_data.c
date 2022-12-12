/*
** EPITECH PROJECT, 2019
** sokoban.c
** File description:
** Get data and fill tables
*/

#include "include/sokoban.h"

void fill_table(map_t *map)
{
    int a = 0;
    int b = 0;

    for (int i = 0; map->mapstring[i] != '\0'; i++) {
        if (map->mapstring[i] == '\n') {
            a++;
            b = 0;
            continue;
        }
        map->dmap[a][b] = map->mapstring[i];
        b++;
    }
}

void fill_o(map_t *map)
{
    int a = 0;
    int b = 0;

    for (int i = 0; map->mapstring[i] != '\0'; i++) {
        if (map->mapstring[i] == '\n') {
            a++;
            b = 0;
            continue;
        }
        if (map->mapstring[i] == 'O') {
            map->omap[a][b] = map->mapstring[i];
            b++;
            continue;
        }
        map->omap[a][b] = ' ';
        b++;
    }
}

void copy_double(map_t *map)
{
    map->dmap = malloc(sizeof(char *) * (map->rows + 1));
    if (map->dmap == NULL)
        exit(84);
    map->dmap[map->rows] = NULL;
    for (int i = 0; map->rows != i; i++) {
        map->dmap[i] = malloc(sizeof(char) * (map->colums + 1));
        if (map->dmap[i] == NULL)
            exit(84);
        map->dmap[i][map->colums] = '\0';
    }
    fill_table(map);
}

void copy_o(map_t *map)
{
    map->omap = malloc(sizeof(char *) * (map->rows + 1));
    if (map->omap == NULL)
        exit (84);
    map->omap[map->rows] = NULL;
    for (int i = 0; map->rows != i; i++) {
        map->omap[i] = malloc(sizeof(char) * (map->colums + 1));
        if (map->omap[i] == NULL)
            exit(84);
        map->omap[i][map->colums] = '\0';
    }
    fill_o(map);
}

void get_data(char **av, map_t *map)
{
    get_map_file(av, map);
    map->rows = count_rows(map);
    map->colums = count_colums(map);

    check_map(map);
    copy_double(map);
    copy_o(map);
}