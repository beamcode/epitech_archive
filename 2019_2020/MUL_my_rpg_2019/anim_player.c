/*
** EPITECH PROJECT, 2020
** anim player
** File description:
** anim player
*/
#include "include/my.h"

void move_up_sec(game_t *game, int tmp)
{
    if (tmp == 2) {
        game->player->rect.top = 0;
        game->player->rect.left = 86;
        game->player->rect.width = 40;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
    if (tmp == 3) {
        game->player->rect.top = 0;
        game->player->rect.left = 129;
        game->player->rect.width = 40;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
}

void move_up(game_t *game, int tmp)
{
    if (tmp == 0) {
        game->player->rect.top = 0;
        game->player->rect.left = 0;
        game->player->rect.width = 40;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
    if (tmp == 1) {
        game->player->rect.top = 0;
        game->player->rect.left = 43;
        game->player->rect.width = 40;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
    move_up_sec(game, tmp);
}

void move_down_sec(game_t *game, int tmp)
{
    if (tmp == 2) {
        game->player->rect.top = 0;
        game->player->rect.left = 628;
        game->player->rect.width = 50;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
    if (tmp == 3) {
        game->player->rect.top = 0;
        game->player->rect.left = 675;
        game->player->rect.width = 50;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
}

void move_down(game_t *game, int tmp)
{
    if (tmp == 0) {
        game->player->rect.top = 0;
        game->player->rect.left = 535;
        game->player->rect.width = 40;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
    if (tmp == 1) {
        game->player->rect.top = 0;
        game->player->rect.left = 584;
        game->player->rect.width = 50;
        game->player->rect.height = 50;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
    }
    move_down_sec(game, tmp);
}
