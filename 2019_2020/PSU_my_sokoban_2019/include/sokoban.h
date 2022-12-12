/*
** EPITECH PROJECT, 2019
** sokoban.h
** File description:
** Header file for sokoban
*/

#ifndef MAP_S
#define MAP_S

#include <sys/types.h>
#include <sys/stat.h>
#include <stddef.h>
#include <fcntl.h>
#include <ncurses.h>
#include "../lib/my/my_lib.h"

typedef struct map
{
    char **dmap;
    char **omap;
    char *mapstring;
    int rows;
    int colums;
    int p_x;
    int p_y;
    int O;
    int win;
    int wind_x;
    int wind_y;
}map_t;

int count_rows(map_t *map);
int count_colums(map_t *map);
void sokoban(char **av);
void get_data(char **av, map_t *map);
void check_map(map_t *map);
void check_win(map_t *map);
void get_map_file(char **av, map_t *map);
void fill_table(map_t *map);
void get_ppos(map_t *map);

void move_up(map_t *map);
void move_down(map_t *map);
void move_left(map_t *map);
void move_right(map_t *map);

#endif