/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

int check_input(int x, int y)
{
    if (x <= 0 || y <= 0) {
        printf("./generator: the dimensions must be greater than 0!\n");
        return (84);
    }
    if (x > 1000 || y > 1000)
        return (84);
    return (0);
}

void scramble_maze(st_s *st)
{
    int r = 1 + (rand() % 2);

    for (int a = 0; a < st->y; a++) {
        for (int b = 0; st->maze[a][b] != '\0'; b++) {
            if (r == 5 && st->maze[a][b] != '*')
                st->maze[a][b] = '*';
            r = 1 + (rand() % 5);
        }
    }
}

int build_exit(st_s *st, int x, int y)
{
    int a = 1 + (rand() % 2);

    if (x < 0 || y < 0)
        return (1);
    st->maze[y][x] = '*';
    if (st->maze[y][x - 1] == '*' || st->maze[y - 1][x] == '*')
        return (1);
    while (1) {
        if (a == 1 && build_exit(st, x, (y - 1)) == 1)
            return (1);
        if (a == 2 && build_exit(st, (x - 1), y) == 1)
            return (1);
        a = 1 + (rand() % 2);
    }
    return (0);
}

void kill_coding_style(st_s *st)
{
    if (st->y <= 1 || st->x <= 1) {
        fill_star(st->maze);
        return;
    }
    st->maze[st->y - 1][st->x - 1] = 'X';
    if (st->maze[st->y - 1][st->x - 1] == 'X') {
        st->maze[st->y - 1][st->x - 2] = 'X';
        st->maze[st->y - 2][st->x - 1] = 'X';
        build_exit(st, st->x - 1, st->y - 1);
        st->maze[0][0] = '*';
    }
    st->maze[0][0] = '*';
}

int main(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return (84);
    st_s *st = malloc(sizeof(st_s));

    srand(time(NULL));
    st->x = my_atoi(av[1]);
    st->y = my_atoi(av[2]);
    if (check_input(st->x, st->y) == 84)
        return (84);
    st->maze = generate_array(st->x, st->y);
    if (st->maze == NULL)
        return (84);
    st->maze[0][0] = '*';
    search_begin(st, 0, 0);
    if ((ac == 4 && strcmp(av[3], "perfect\0") != 0) || ac == 3)
        scramble_maze(st);
    kill_coding_style(st);
    print_maze(st->maze);
    free(st->maze);
    return (0);
}