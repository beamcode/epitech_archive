/*
** EPITECH PROJECT, 2020
** bar
** File description:
** nar
*/
#include "include/my.h"

void display_lifebar_second(game_t *game)
{
    for (button_t *t = game->button; t->mark != 81; t = t->next)
        if (t->sprite && t->mark == 80 && game->player->lifebar == 4)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 80; t = t->next)
        if (t->sprite && t->mark == 79 && game->player->lifebar == 3)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 79; t = t->next)
        if (t->sprite && t->mark == 78 && game->player->lifebar == 2)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 78; t = t->next)
        if (t->sprite && t->mark == 77 && game->player->lifebar == 1)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
}

void display_lifebar(game_t *game)
{
    for (button_t *t = game->button; t->mark != 85; t = t->next)
        if (t->sprite && t->mark == 84 && game->player->lifebar == 8)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 84; t = t->next)
        if (t->sprite && t->mark == 83 && game->player->lifebar == 7)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 83; t = t->next)
        if (t->sprite && t->mark == 82 && game->player->lifebar == 6)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 82; t = t->next)
        if (t->sprite && t->mark == 81 && game->player->lifebar == 5)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    display_lifebar_second(game);
}

void display_xpbar_second(game_t *game)
{
    for (button_t *t = game->button; t->mark != 89; t = t->next)
        if (t->sprite && t->mark == 88 && game->player->xpbar == 4)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 90; t = t->next)
        if (t->sprite && t->mark == 89 && game->player->xpbar == 5)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 91; t = t->next)
        if (t->sprite && t->mark == 90 && game->player->xpbar == 6)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 92; t = t->next)
        if (t->sprite && t->mark == 91 && game->player->xpbar == 7)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 93; t = t->next)
        if (t->sprite && t->mark == 92 && game->player->xpbar == 8)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
}

void display_xpbar(game_t *game)
{
    for (button_t *t = game->button; t->mark != 86; t = t->next)
        if (t->sprite && t->mark == 85 && game->player->xpbar == 1)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 87; t = t->next)
        if (t->sprite && t->mark == 86 && game->player->xpbar == 2)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 88; t = t->next)
        if (t->sprite && t->mark == 87 && game->player->xpbar == 3)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    display_xpbar_second(game);
}
