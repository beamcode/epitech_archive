/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

char **create_grid(const int size)
{
    int total = (size * 2) + 3;
    char **grid;

    grid = malloc(sizeof(char *) * (size + 3));
    for (int g = 0; g < (size + 2); g++)
        grid[g] = malloc(sizeof(char) * total + 1);
    for (int y = 1; y < (size + 1); y++) {
        for (int x = 0; x < total; x++)
            grid[y][x] = ' ';
        grid[y][0] = '|';
        grid[y][total - 1] = '|';
    }
    for	(int a = 0; a < total; a++) {
        grid[size + 1][a] = '+';
        grid[0][a] = '+';
    }
    for (int a = 0; a < (size + 2); grid[a][total] = '\0', a++);
    grid[size + 2] = NULL;
    return (grid);
}

int main(int ac, char **av)
{
    int a = atoi(av[1]);
    char **grid = create_grid(a);

    my_putarray(grid);
    return (0);
}
