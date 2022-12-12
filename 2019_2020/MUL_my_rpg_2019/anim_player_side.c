/*
** EPITECH PROJECT, 2020
** side
** File description:
** side
*/
#include "include/my.h"

void move_right_sec(game_t *game, int tmp)
{
    if (tmp == 2) {
        game->player->rect.top = 0;
        game->player->rect.left = 265;
        game->player->rect.width = 40;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
    if (tmp == 3) {
        game->player->rect.top = 0;
        game->player->rect.left = 315;
        game->player->rect.width = 40;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
}

void move_right(game_t *game, int tmp)
{
    if (tmp == 0) {
        game->player->rect.top = 0;
        game->player->rect.left = 172;
        game->player->rect.width = 40;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
    if (tmp == 1) {
        game->player->rect.top = 0;
        game->player->rect.left = 218;
        game->player->rect.width = 40;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
    move_right_sec(game, tmp);
}

void move_left_sec(game_t *game, int tmp)
{
    if (tmp == 2) {
        game->player->rect.top = 0;
        game->player->rect.left = 440;
        game->player->rect.width = 50;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
    if (tmp == 3) {
        game->player->rect.top = 0;
        game->player->rect.left = 480;
        game->player->rect.width = 50;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
}

void move_left(game_t *game, int tmp)
{
    if (tmp == 0) {
        game->player->rect.top = 0;
        game->player->rect.left = 350;
        game->player->rect.width = 50;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
    if (tmp == 1) {
        game->player->rect.top = 0;
        game->player->rect.left = 395;
        game->player->rect.width = 50;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
    move_left_sec(game, tmp);
}
