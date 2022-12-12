/*
** EPITECH PROJECT, 2020
** display menu
** File description:
** display menu
*/
#include "include/my.h"

void display_first_button(game_t *game)
{
    if (game->menu1 == 0) {
        for (button_t *t = game->button; t->mark != 3; t = t->next)
            if (t->sprite && t->mark == 2)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
    else {
        for (button_t *t = game->button; t->mark != 8; t = t->next)
            if (t->sprite && t->mark == 7)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
    if (game->menu2 == 0) {
        for (button_t *t = game->button; t->mark != 5; t = t->next)
            if (t->sprite && t->mark == 4)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
    else {
        for (button_t *t = game->button; t->mark != 9; t = t->next)
            if (t->sprite && t->mark == 8)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
}

void display_second_button(game_t *game)
{
    if (game->menu3 == 0) {
        for (button_t *t = game->button; t->mark != 4; t = t->next)
            if (t->sprite && t->mark == 3)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
    else {
        for (button_t *t = game->button; t->mark != 10; t = t->next)
            if (t->sprite && t->mark == 9)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
    if (game->menu4 == 0) {
        for (button_t *t = game->button; t->mark != 6; t = t->next)
            if (t->sprite && t->mark == 5)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
    else {
        for (button_t *t = game->button; t->mark != 11; t = t->next)
            if (t->sprite && t->mark == 10)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
}

void display_menu(game_t *game)
{
    if (game->menu == 1 && game->settings == 0) {
        for (button_t *t = game->button; t->mark != 2; t = t->next)
            if (t->sprite && t->mark == 1)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
        display_first_button(game);
        display_second_button(game);
        for (button_t *t = game->button; t->mark != 7; t = t->next)
            if (t->sprite && t->mark == 6)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
    if (game->settings == 1)
        display_settings(game);
}
