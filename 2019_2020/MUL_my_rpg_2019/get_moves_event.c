/*
** EPITECH PROJECT, 2020
** moves
** File description:
** moves
*/
#include "include/my.h"

void check_axe_max(game_t *game)
{
    if (game->axe_x > 4.0) {
        game->axe_y = (game->axe_y * 4.0) / game->axe_x;
        game->axe_x = 4.0;
    }
    if (game->axe_x < -4.0) {
        game->axe_y = (game->axe_y * -4.0) / game->axe_x;
        game->axe_x = -4.0;
    }
    if (game->axe_y < -4.0) {
        game->axe_x = (game->axe_x * -4.0) / game->axe_y;
        game->axe_y = -4.0;
    }
    if (game->axe_y > 4.0) {
        game->axe_x = (game->axe_x * 4.0) / game->axe_y;
        game->axe_y = 4.0;
    }
}

void get_move_axes(game_t *game)
{
    float move_x;
    float move_y;

    game->pos_move.x = game->pos_clic.x - 25;
    game->pos_move.y = game->pos_clic.y - 35;
    move_x = game->pos_move.x;
    move_y = game->pos_move.y;
    game->axe_y = (move_y - game->player->pos.y) / 100;
    game->axe_x = (move_x - game->player->pos.x) / 100;
    check_axe_max(game);
    game->on_move = 1;
}
