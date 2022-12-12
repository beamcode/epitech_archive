/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

int check_array(char **temp)
{
    int x = 0;

    for (int i = 0; temp[i]; i++) {
        for (int a = 0; temp[i][a] != '\0'; a++) {
            if (temp[i][a] == 'x') {
                x++;
            }
        }
    }
    return (x);
}

int verify_win(st_s *st)
{
    int x_me = check_array(st->map);
    int x_enemy = check_array(st->enemy_map);

    if (x_me == 14) {
        print_maps(st);
        my_putstr("Enemy won\n");
        return (1);
    }
    if (x_enemy == 14) {
        print_maps(st);
        my_putstr("I won\n");
        return (1);
    }
    return (0);
}

int check_input(char *input)
{
    if (my_strlen(input) != 3)
        return (84);
    if (input[0] < 'A' || input[0] > 'H' || input[1] < '1' || input[1] > '8')
        return (84);
    if (input[2] != '\n')
        return (84);
    return (0);
}

void print_maps(st_s *st)
{
    my_putstr("my positions:\n");
    my_putarray(st->map);
    my_putstr("\nenemy’s positions:\n");
    my_putarray(st->enemy_map);
    my_putchar('\n');
}

void sig_handler(int signum, siginfo_t *sig, void *c)
{
    vg.global = signum;
    vg.pid = sig->si_pid;
}
