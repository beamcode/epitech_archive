/*
** EPITECH PROJECT, 2020
** check col
** File description:
** check col
*/
#include "include/my.h"

void check_obstacles(game_t *game)
{
    for (obs_t *t = game->map->obs; t->mark != 188; t = t->next)
        if (game->player->pos.x < t->pos_max.x
            && game->player->pos.x > t->pos_min.x
            && game->player->pos.y < t->pos_max.y
            && game->player->pos.y > t->pos_min.y
            && t->map_nb == game->current_map)
            game->on_move = 0;
}
