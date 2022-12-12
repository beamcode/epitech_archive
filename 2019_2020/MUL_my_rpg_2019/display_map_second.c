/*
** EPITECH PROJECT, 2020
** map second
** File description:
** map second
*/
#include "include/my.h"

void check_map_eight_two(game_t *game)
{
    if (game->player->pos.x > 1847 && game->player->pos.x < 1919
        && game->player->pos.y > 506 && game->player->pos.y < 579) {
        game->current_map = 9;
        game->on_move = 0;
        game->player->pos.x = 100.0;
        game->player->pos.y = 522.0;
        sfSprite_setPosition(game->player->sprite, game->player->pos);
    }
}

void check_map_eight(game_t *game)
{
    if (game->current_map == 8) {
        if (game->player->pos.x > 0 && game->player->pos.x < 73
            && game->player->pos.y > 490 && game->player->pos.y < 566) {
            game->current_map = 7;
            game->on_move = 0;
            game->player->pos.x = 1785.0;
            game->player->pos.y = 520.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
        if (game->player->pos.x > 1515 && game->player->pos.x < 1580
            && game->player->pos.y > 0 && game->player->pos.y < 75) {
            game->current_map = 5;
            game->on_move = 0;
            game->player->pos.x = 1532.0;
            game->player->pos.y = 931.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
        check_map_eight_two(game);
    }
    check_map_nine(game);
}

void check_map_seven(game_t *game)
{
    if (game->current_map == 7) {
        if (game->player->pos.x > 1385 && game->player->pos.x < 1456
            && game->player->pos.y > 0 && game->player->pos.y < 30) {
            game->current_map = 4;
            game->on_move = 0;
            game->player->pos.x = 1400.0;
            game->player->pos.y = 953.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
        if (game->player->pos.x > 1849 && game->player->pos.x < 1919
            && game->player->pos.y > 490 && game->player->pos.y < 566) {
            game->current_map = 8;
            game->on_move = 0;
            game->player->pos.x = 100.0;
            game->player->pos.y = 519.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
    }
    check_map_eight(game);
}

void check_map_four(game_t *game)
{
    if (game->current_map == 4) {
        if (game->player->pos.x > 926 && game->player->pos.x < 1000
            && game->player->pos.y > 0 && game->player->pos.y < 71) {
            game->current_map = 1;
            game->on_move = 0;
            game->player->pos.x = 945.0;
            game->player->pos.y = 940.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
        if (game->player->pos.x > 1853 && game->player->pos.x < 1919
            && game->player->pos.y > 537 && game->player->pos.y < 631) {
            game->current_map = 5;
            game->on_move = 0;
            game->player->pos.x = 90.0;
            game->player->pos.y = 600.0;
            sfSprite_setPosition(game->player->sprite, game->player->pos);
        }
        check_map_four_two(game);
    }
    check_map_five(game);
}
