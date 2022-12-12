/*
** EPITECH PROJECT, 2020
** gametime
** File description:
** gametime
*/
#include "include/my.h"

void concate_time(game_t *game, int minuts, char *a, char *b)
{
    if (minuts <= 9) {
        game->gametime = my_strcat(b, ":");
        game->gametime = my_strcat(game->gametime, "0");
        game->gametime = my_strcat(game->gametime, a);
    }
    else {
        game->gametime = my_strcat(b, ":");
        game->gametime = my_strcat(game->gametime, a);
    }
    free(a);
    free(b);
}

void get_time(game_t *game)
{
    int minuts;
    char *a;
    char *b;

    minuts = game->min;
    a = my_itoa(minuts);
    if (minuts == 59) {
        game->min = 0.00;
        game->hours++;
        if (game->hours == 24)
            game->hours = 0;
    }
    if (game->hours <= 9) {
        b = my_itoa(game->hours);
        b = my_strcat("0", b);
    }
    else
        b = my_itoa(game->hours);
    concate_time(game, minuts, a, b);
}
