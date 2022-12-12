/*
** EPITECH PROJECT, 2020
** inv
** File description:
** inv
*/
#include "include/my.h"

void display_first_item(game_t *game)
{
    for (button_t *t = game->button; t->mark != 22; t = t->next)
        if (t->sprite && t->mark == 21 && game->inventory == 1
            && game->item->helmet != 0)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 23; t = t->next)
        if (t->sprite && t->mark == 22 && game->inventory == 1
            && game->item->amulet != 0)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 24; t = t->next)
        if (t->sprite && t->mark == 23 && game->inventory == 1
            && game->item->chest != 0)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 25; t = t->next)
        if (t->sprite && t->mark == 24 && game->inventory == 1
            && game->item->ring != 0)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
}

void display_second_item(game_t *game)
{
    for (button_t *t = game->button; t->mark != 26; t = t->next)
        if (t->sprite && t->mark == 25 && game->inventory == 1
            && game->item->sword != 0)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 27; t = t->next)
        if (t->sprite && t->mark == 26 && game->inventory == 1
            && game->item->boots != 0)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 28; t = t->next)
        if (t->sprite && t->mark == 27 && game->inventory == 1
            && game->item->jewel != 0)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (button_t *t = game->button; t->mark != 109; t = t->next)
        if (t->sprite && (t->mark == 108 || t->mark == 107)
            && game->inventory == 1)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
}

void display_inventory(game_t *game)
{
    for (button_t *t = game->button; t->mark != 21; t = t->next)
        if ((t->sprite && t->mark >= 13 && game->inventory == 1)
            || (t->sprite && t->mark == 70))
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    display_first_item(game);
    display_second_item(game);
    for (item_t *t = game->item; t->mark != 70; t = t->next)
        if (t->sprite && t->mark >= 30 && game->inventory == 1 && t->get == 1)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (item_t *t = game->item; t->mark != 70; t = t->next) {
        if (t->sprite && t->mark > 0 && t->on == 1 && game->inventory == 1)
            for (info_t *a = game->info; a->mark != 41; a = a->next) {
                if (a->sprite && a->mark == (t->mark - 29))
                    sfRenderWindow_drawSprite(game->window, a->sprite, NULL);
            }
    }
}
