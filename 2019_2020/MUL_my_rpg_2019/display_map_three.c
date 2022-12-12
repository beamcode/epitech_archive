/*
** EPITECH PROJECT, 2020
** map thre
** File description:
** map three
*/
#include "include/my.h"

void check_map_six_two(game_t *game)
{
    if (game->player->pos.x > 1648 && game->player->pos.x < 1710
        && game->player->pos.y > 970 && game->player->pos.y < 1080) {
        game->current_map = 9;
        game->on_move = 0;
        game->player->pos.x = 1662.0;
        game->player->pos.y = 95.0;
        sfSprite_setPosition(game->player->sprite, game->player->pos);
    }
}

void check_map_six(game_t *game)
{
    if (game->current_map == 6) {
        if (game->player->pos.x > 976 && game->player->pos.x < 1045
            && game->player->pos.y > 0 && game->player->pos.y < 20) {
            game->current_map = 3;
            game->on_move = 0;
            game->player->pos.x = 980.0;
            game->player->pos.y = 950.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
        if (game->player->pos.x > 0 && game->player->pos.x < 73
            && game->player->pos.y > 700 && game->player->pos.y < 766) {
            game->current_map = 5;
            game->on_move = 0;
            game->player->pos.x = 1780.0;
            game->player->pos.y = 731.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
        check_map_six_two(game);
    }
    check_map_seven(game);
}

void check_map_four_two(game_t *game)
{
    if (game->player->pos.x > 1389 && game->player->pos.x < 1451
        && game->player->pos.y > 970 && game->player->pos.y < 1080) {
        game->current_map = 7;
        game->on_move = 0;
        game->player->pos.x = 1390.0;
        game->player->pos.y = 60.0;
        sfSprite_setPosition(game->player->sprite, game->player->pos);
    }
}

void check_map_five_two(game_t *game)
{
    if (game->player->pos.x > 1849 && game->player->pos.x < 1919
        && game->player->pos.y > 708 && game->player->pos.y < 784) {
        game->current_map = 6;
        game->on_move = 0;
        game->player->pos.x = 90.0;
        game->player->pos.y = 726.0;
        sfSprite_setPosition(game->player->sprite, game->player->pos);
    }
    if (game->player->pos.x > 1521 && game->player->pos.x < 1586
        && game->player->pos.y > 970 && game->player->pos.y < 1080) {
        game->current_map = 8;
        game->on_move = 0;
        game->player->pos.x = 1529.0;
        game->player->pos.y = 90.0;
        sfSprite_setPosition(game->player->sprite, game->player->pos);
    }
}

void check_map_five(game_t *game)
{
    if (game->current_map == 5) {
        if (game->player->pos.x > 0 && game->player->pos.x < 73
            && game->player->pos.y > 584 && game->player->pos.y < 650) {
            game->current_map = 4;
            game->on_move = 0;
            game->player->pos.x = 1785.0;
            game->player->pos.y = 575.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
        if (game->player->pos.x > 979 && game->player->pos.x < 1047
            && game->player->pos.y > 0 && game->player->pos.y < 76) {
            game->current_map = 2;
            game->on_move = 0;
            game->player->pos.x = 940.0;
            game->player->pos.y = 940.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
        check_map_five_two(game);
    }
    check_map_six(game);
}
