/*
** EPITECH PROJECT, 2019
** sokoban.c
** File description:
** Sokoban checks
*/

#include "include/sokoban.h"

void get_map_file(char **av, map_t *map)
{
    int open_result = open(av[1], O_RDONLY);
    struct stat buf;

    stat(av[1], &buf);
    map->mapstring = malloc(sizeof(char) * (buf.st_size + 1));
    read(open_result, map->mapstring, buf.st_size);
    map->mapstring[buf.st_size] = '\0';
}

void check_equal(map_t *map)
{
    int X = 0;
    int O = 0;
    int P = 0;

    for (int i = 0; map->mapstring[i]; i++) {
        if (map->mapstring[i] == 'O')
            O++;
        if (map->mapstring[i] == 'X')
            X++;
        if (map->mapstring[i] == 'P')
            P++;
    }
    if (O != X || P == 2)
        exit(84);
}

void check_map(map_t *map)
{   
    for (int i = 0; map->mapstring[i]; i++) {
        if (map->mapstring[i] == ' ' || map->mapstring[i] == '\n' ||
        map->mapstring[i] == '#' || map->mapstring[i] == 'P' ||
        map->mapstring[i] == 'O' || map->mapstring[i] == 'X' ||
        map->mapstring[i] == '\0') {
        }
        else exit(84);
        check_equal(map);
    }
}

void check_win(map_t *map)
{
    get_ppos(map);
    for (int a = 0; a != map->rows; a++) {
        for (int b = 0; map->dmap[a][b] != '\0'; b++) {
            if (map->omap[map->p_y][map->p_x] == 'O')
                return;
            if (map->dmap[a][b] == 'O')
                return;
        }
    }
    map->win = 1;
}