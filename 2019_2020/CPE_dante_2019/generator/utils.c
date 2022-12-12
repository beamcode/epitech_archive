/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

void fill_star(char **temp)
{
    for (int y = 0; temp[y]; y++)
        for (int x = 0; temp[y][x] != '\0'; x++) {
            if (temp[y][x] != '*')
                temp[y][x] = '*';
        }
}

void debug(st_s *st)
{
    print_maze(st->maze);
    printf("\n\n");
    usleep(100000);
}

char **generate_array(int x, int y)
{
    char **maze = NULL;

    maze = malloc(sizeof(char *) * y + 2);
    for (int a = 0; a < y; a++) {
        maze[a] = malloc(sizeof(char) * x + 2);
        memset(maze[a], 'X', x);
        maze[a][x] = '\0';
    }
    maze[y] = NULL;
    return (maze);
}

void print_maze(char **array)
{
    for (int x = 0; array[x]; x++) {
        my_putstr(array[x]);
        if (array[x + 1] != NULL)
            my_putstr("\n");
    }
}