/*
** EPITECH PROJECT, 2020
** map first
** File description:
** map first
*/
#include "include/my.h"

void check_map_nine(game_t *game)
{
    if (game->current_map == 9) {
        if (game->player->pos.x > 0 && game->player->pos.x < 74
            && game->player->pos.y > 484 && game->player->pos.y < 554) {
            game->current_map = 8;
            game->on_move = 0;
            game->player->pos.x = 1789.0;
            game->player->pos.y = 523.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
        if (game->player->pos.x > 1651 && game->player->pos.x < 1721
            && game->player->pos.y > 0 && game->player->pos.y < 78) {
            game->current_map = 6;
            game->on_move = 0;
            game->player->pos.x = 1658.0;
            game->player->pos.y = 940.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
    }
}

void check_map_th(game_t *game)
{
    if (game->current_map == 3) {
        if (game->player->pos.x > 0 && game->player->pos.x < 80
            && game->player->pos.y > 505 && game->player->pos.y < 578) {
            game->current_map = 2;
            game->on_move = 0;
            game->player->pos.x = 1780.0;
            game->player->pos.y = 520.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
        if (game->player->pos.x > 960 && game->player->pos.x < 1045
            && game->player->pos.y > 970 && game->player->pos.y < 1080) {
            game->current_map = 6;
            game->on_move = 0;
            game->player->pos.x = 990.0;
            game->player->pos.y = 80.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
    }
    check_map_four(game);
}

void check_map_sec_two(game_t *game)
{
    if (game->player->pos.x > 1847 && game->player->pos.x < 1919
        && game->player->pos.y > 504 && game->player->pos.y < 577) {
        game->current_map = 3;
        game->on_move = 0;
        game->player->pos.x = 94.0;
        game->player->pos.y = 532.0;
        sfSprite_setPosition(game->player->sprite, game->player->pos);
    }
}

void check_map_sec(game_t *game)
{
    if (game->current_map == 2) {
        if (game->player->pos.x > 0 && game->player->pos.x < 78
            && game->player->pos.y > 503 && game->player->pos.y < 580) {
            game->current_map = 1;
            game->on_move = 0;
            game->player->pos.x = 1780.0;
            game->player->pos.y = 520.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
        if (game->player->pos.x > 917 && game->player->pos.x < 960
            && game->player->pos.y > 970 && game->player->pos.y < 1080) {
            game->current_map = 5;
            game->on_move = 0;
            game->player->pos.x = 1000.0;
            game->player->pos.y = 100.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
        check_map_sec_two(game);
    }
    check_map_th(game);
}

void check_map_number(game_t *game)
{
    if (game->current_map == 1) {
        if (game->player->pos.x > 1847 && game->player->pos.x < 1919
            && game->player->pos.y > 505 && game->player->pos.y < 579) {
            game->current_map = 2;
            game->on_move = 0;
            game->player->pos.x = 90.0;
            game->player->pos.y = 520.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
        if (game->player->pos.x > 921 && game->player->pos.x < 957
            && game->player->pos.y > 970 && game->player->pos.y < 1080) {
            game->current_map = 4;
            game->on_move = 0;
            game->player->pos.x = 946.0;
            game->player->pos.y = 90.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
    }
    check_map_sec(game);
}
