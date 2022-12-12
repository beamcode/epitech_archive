/*
** EPITECH PROJECT, 2020
** bar sprite
** File description:
** bar sprite
*/
#include "include/my.h"

void change_xpbar(game_t *game)
{
    int pc2;

    pc2 = (game->player->xp * 100) / game->player->xpmax;
    if (pc2 == 100)
        game->player->xpbar = 8;
    if (pc2 >= 83 && pc2 < 100)
        game->player->xpbar = 7;
    if (pc2 >= 67 && pc2 < 83)
        game->player->xpbar = 6;
    if (pc2 >= 50 && pc2 < 67)
        game->player->xpbar = 5;
    if (pc2 >= 33 && pc2 < 50)
        game->player->xpbar = 4;
    if (pc2 >= 16 && pc2 < 33)
        game->player->xpbar = 3;
    if (pc2 >= 1 && pc2 < 16)
        game->player->xpbar = 2;
    if (pc2 == 0)
        game->player->xpbar = 1;
}

void change_lifebar(game_t *game)
{
    int pc;

    pc = (game->player->life * 100) / game->player->lifemax;
    if (pc == 100)
        game->player->lifebar = 8;
    if (pc >= 83 && pc < 100)
        game->player->lifebar = 7;
    if (pc >= 67 && pc < 83)
        game->player->lifebar = 6;
    if (pc >= 50 && pc < 67)
        game->player->lifebar = 5;
    if (pc >= 33 && pc < 50)
        game->player->lifebar = 4;
    if (pc >= 16 && pc < 33)
        game->player->lifebar = 3;
    if (pc >= 1 && pc < 16)
        game->player->lifebar = 2;
    if (pc == 0)
        game->player->lifebar = 1;
}

void check_bar_sprite(game_t *game)
{
    change_xpbar(game);
    change_lifebar(game);
    if (game->player->life < 0)
        game->player->life = 0;
    if (game->player->xp >= game->player->xpmax) {
        game->player->level++;
        game->player->points += 5;
        game->player->xpmax += 500;
        game->player->xp = 0;
    }
}
