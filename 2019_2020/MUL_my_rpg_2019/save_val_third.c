/*
** EPITECH PROJECT, 2020
** save val
** File description:
** save val
*/
#include "include/my.h"

char *save_val_nine(game_t *game)
{
    char *save = NULL;
    char *tmp = NULL;
    char *x = NULL;

    tmp = my_itoa(game->stat->helmet_res);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->quest->q2);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->quest->q3);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->quest->q4);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    x = save_last(game);
    save = my_strcat(save, x);
    return (save);
}
