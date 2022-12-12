/*
** EPITECH PROJECT, 2020
** status
** File description:
** status
*/
#include "include/my.h"

void display_statusmenu(game_t *game)
{
    for (button_t *t = game->button; t->mark != 98; t = t->next)
        if (t->sprite && t->mark == 97)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    if (game->player->points > 0) {
        for (button_t *t = game->button; t->mark != 102; t = t->next)
            if (t->sprite && (t->mark == 98 || t->mark == 99 || t->mark == 100
                || t->mark == 101))
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
        for (button_t *t = game->button; t->mark != 103; t = t->next)
            if (t->sprite && t->mark == 102 && game->s1 == 1)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
        for (button_t *t = game->button; t->mark != 104; t = t->next)
            if (t->sprite && t->mark == 103 && game->s2 == 1)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
        for (button_t *t = game->button; t->mark != 105; t = t->next)
            if (t->sprite && t->mark == 104 && game->s3 == 1)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
        for (button_t *t = game->button; t->mark != 106; t = t->next)
            if (t->sprite && t->mark == 105 && game->s4 == 1)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
}

void display_settings(game_t *game)
{
    for (button_t *t = game->button; t->mark != 77; t = t->next)
        if (t->sprite && (t->mark == 11 || t->mark == 76))
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 114; t = t->next)
        if (t->sprite && t->mark == 113 && game->apply == 1)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
}
