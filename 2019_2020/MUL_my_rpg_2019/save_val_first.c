/*
** EPITECH PROJECT, 2020
** save val
** File description:
** save val
*/
#include "include/my.h"

char *save_val_first(game_t *game)
{
    char *save = NULL;
    char *tmp = NULL;
    int a = game->min;

    tmp = my_itoa(game->current_map);
    save = my_strcat(tmp, " ");
    tmp = my_itoa(a);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->hours);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    save = my_strcat(save, "0");
    save = my_strcat(save, " ");
    tmp = my_itoa(game->player->life);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->player->level);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    return (save);
}

char *save_val_sec(game_t *game)
{
    char *save = NULL;
    char *tmp = NULL;

    tmp = my_itoa(game->player->lifemax);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->player->lifebar);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->player->xpbar);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->player->xp);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->player->xpmax);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    free(tmp);
    return (save);
}

char *save_val_three(game_t *game)
{
    char *save = NULL;
    char *tmp = NULL;

    tmp = my_itoa(game->player->damage);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->player->resistance);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->player->points);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->player->s_life);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->player->s_dam);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    free(tmp);
    return (save);
}

char *save_val_four(game_t *game)
{
    char *save = NULL;
    char *tmp = NULL;
    int posx = game->player->pos.x;
    int posy = game->player->pos.y;

    tmp = my_itoa(game->player->s_res);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(posx);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(posy);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    tmp = my_itoa(game->stat->ring_life);
    save = my_strcat(save, tmp);
    save = my_strcat(save, " ");
    free(tmp);
    return (save);
}
