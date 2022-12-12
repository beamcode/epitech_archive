/*
** EPITECH PROJECT, 2020
** save val
** File description:
** save val
*/
#include "include/my.h"

char *save_val_five(game_t *game)
{
    char *save = NULL;
    char *tmp = NULL;

    tmp = my_itoa(game->stat->jewel_life);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->sword_life);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->chest_life);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->amulet_life);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->boots_life);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    free(tmp);
    return (save);
}

char *save_val_six(game_t *game)
{
    char *save = NULL;
    char *tmp = NULL;

    tmp = my_itoa(game->stat->helmet_life);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->ring_dam);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->jewel_dam);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->sword_dam);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->chest_dam);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    free(tmp);
    return (save);
}

char *save_val_seven(game_t *game)
{
    char *save = NULL;
    char *tmp = NULL;

    tmp = my_itoa(game->stat->amulet_dam);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->boots_dam);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->helmet_dam);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->ring_res);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->jewel_res);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    free(tmp);
    return (save);
}

char *save_last(game_t *game)
{
    char *save = NULL;
    char *tmp = NULL;

    tmp = my_itoa(game->quest->q5);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->quest->q6);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->quest->quest);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->quest->boss);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    return (save);
}

char *save_val_eight(game_t *game)
{
    char *save = NULL;
    char *tmp = NULL;
    char *x = NULL;

    tmp = my_itoa(game->stat->sword_res);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->chest_res);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->amulet_res);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->boots_res);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    x = save_val_nine(game);
    save = my_strcat(save, x);
    free(tmp);
    return (save);
}
