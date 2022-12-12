/*
** EPITECH PROJECT, 2019
** sokoban.c
** File description:
** Main funtion with loop and initializations
*/

#include "include/sokoban.h"

map_t *initialize(void)
{
    map_t *map = malloc(sizeof(map_t));

    char **dmap = NULL;
    char *mapstring = NULL;
    int rows = 0;
    int colums = 0;
    int p = 0;
    int p_y = 0;
    int p_x = 0;
    int O = 0;
    int win = 0;
    int wind_x = 0;
    int wind_y = 0;
    return (map);
}

void key_events(map_t *map)
{
    int key = getch();
    if (key == 32) {
        map->win = 0;
        fill_table(map);
    }
    if (key == 27) {
        endwin();
        exit(1);
    }
    if (map->win == 1)
        return;
    if (key == KEY_UP)
        move_up(map);
    if (key == KEY_DOWN)
        move_down(map);
    if (key == KEY_LEFT)
        move_left(map);
    if (key == KEY_RIGHT)
        move_right(map);
}

void draw_loop(map_t *map)
{
    initscr();
    noecho();
    keypad(stdscr, TRUE);

    while (1) {
        clear();
        map->wind_x = COLS/2 - map->rows/2;
        map->wind_y = LINES/2 - map->rows/2;
        check_win(map);
        for (int row = 0; row < map->rows; row += 1)
            mvprintw(row + map->wind_y, map->wind_x, "%s", map->dmap[row]);
        if (map->win == 1) {
            endwin();
            exit(1);
        }
        key_events(map);
        refresh();
    }
}

void sokoban(char **av)
{
    map_t *map = initialize();

    get_data(av, map);
    get_ppos(map);
    draw_loop(map);
}