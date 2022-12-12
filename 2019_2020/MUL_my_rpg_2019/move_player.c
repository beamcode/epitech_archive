/*
** EPITECH PROJECT, 2020
** move player
** File description:
** move player
*/
#include "include/my.h"

void stop_player(game_t *game)
{
    sfSprite_setPosition(game->player->sprite, game->player->pos);
    if ((game->player->pos.x <= (game->pos_move.x + 3)
        && game->player->pos.x >= (game->pos_move.x - 3))
        && (game->player->pos.y <= (game->pos_move.y + 3)
        && game->player->pos.y >= (game->pos_move.y - 3)) && game->on_move == 1)
        game->on_move = 0;
}

void move_player(game_t *game)
{
    static int tmp = 0;

    game->player->pos.x += game->axe_x;
    game->player->pos.y += game->axe_y;
    if (game->mv > 0.08) {
        if (game->axe_x > 1.80)
            move_right(game, tmp);
        if (game->axe_x < -1.80)
            move_left(game, tmp);
        if (game->axe_x <= 1.80 && game->axe_y >= 1.2)
            move_down(game, tmp);
        if (game->axe_x >= -1.80 && game->axe_y <= -1.2)
            move_up(game, tmp);
        tmp++;
        if (tmp == 4)
            tmp = 0;
        game->mv = 0;
    }
    check_obstacles(game);
    stop_player(game);
}
