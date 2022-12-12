/*
** EPITECH PROJECT, 2019
** moves.c
** File description:
** moves the player and checks certain conditions
*/

#include "include/sokoban.h"

void get_ppos(map_t *map)
{
    for (int a = 0; a != map->rows; a++) {
        for (int b = 0; map->dmap[a][b] != '\0'; b++) {
            if (map->dmap[a][b] == 'P') {
                map->p_y = a;
                map->p_x = b;
                return;
            }
            if (map->dmap[a][b] == '\0')
                b = 0;
        }
    }
}

void move_up(map_t *map)
{
    get_ppos(map);
    if (map->dmap[map->p_y - 1][map->p_x] == '#')
        return;
    if (map->dmap[map->p_y - 1][map->p_x] == 'X') {
        if (map->dmap[map->p_y - 2][map->p_x] == '#')
            return;
        if (map->dmap[map->p_y - 2][map->p_x] == 'X')
            return;
        map->dmap[map->p_y - 2][map->p_x] = 'X';
    }
    if (map->omap[map->p_y][map->p_x] == 'O')
        map->dmap[map->p_y][map->p_x] = 'O';
    else map->dmap[map->p_y][map->p_x] = ' ';
    map->dmap[map->p_y - 1][map->p_x] = 'P';
}

void move_down(map_t *map)
{
    get_ppos(map);
    if (map->dmap[map->p_y + 1][map->p_x] == '#')
        return;
    if (map->dmap[map->p_y + 1][map->p_x] == 'X') {
        if (map->dmap[map->p_y + 2][map->p_x] == '#')
            return;
        if (map->dmap[map->p_y + 2][map->p_x] == 'X')
            return;
        map->dmap[map->p_y + 2][map->p_x] = 'X';
    }
    if (map->omap[map->p_y][map->p_x] == 'O')
        map->dmap[map->p_y][map->p_x] = 'O';
    else map->dmap[map->p_y][map->p_x] = ' ';
    map->dmap[map->p_y + 1][map->p_x] = 'P';
}

void move_left(map_t *map)
{
    get_ppos(map);
    if (map->dmap[map->p_y][map->p_x - 1] == '#')
        return;
    if (map->dmap[map->p_y][map->p_x - 1] == 'X') {
        if (map->dmap[map->p_y][map->p_x - 2] == '#')
            return;
        if (map->dmap[map->p_y][map->p_x - 2] == 'X')
            return;
        map->dmap[map->p_y][map->p_x - 2] = 'X';
    }
    if (map->omap[map->p_y][map->p_x] == 'O')
        map->dmap[map->p_y][map->p_x] = 'O';
    else map->dmap[map->p_y][map->p_x] = ' ';
    map->dmap[map->p_y][map->p_x - 1] = 'P';
}

void move_right(map_t *map)
{
    get_ppos(map);
    if (map->dmap[map->p_y][map->p_x + 1] == '#')
        return;
    if (map->dmap[map->p_y][map->p_x + 1] == 'X') {
        if (map->dmap[map->p_y][map->p_x + 2] == '#')
            return;
        if (map->dmap[map->p_y][map->p_x + 2] == 'X')
            return;
        map->dmap[map->p_y][map->p_x + 2] = 'X';
    }
    if (map->omap[map->p_y][map->p_x] == 'O')
        map->dmap[map->p_y][map->p_x] = 'O';
    else map->dmap[map->p_y][map->p_x] = ' ';
    map->dmap[map->p_y][map->p_x + 1] = 'P';
}