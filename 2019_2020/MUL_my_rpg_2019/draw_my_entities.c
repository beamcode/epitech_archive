/*
** EPITECH PROJECT, 2020
** c
** File description:
** c
*/

#include "include/my.h"

void draw_my_real_game(g_t *game)
{
    for (but_t *t = game->but; t != NULL; t = t->next) {
        if (t->sprite && t->mark > 4 && t->color == 0)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
    for (but_t *t = game->but; t != NULL; t = t->next) {
        if (t->sprite && t->mark > 4 && t->color == 1)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
    for (enemy_t *t = game->enemy; t != NULL; t = t->next)
        if (t->sprite && t->hp >= -10) {
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
        }
    display_rect_shape(game->window, game->pv_bar, 4);
    sfRenderWindow_drawSprite(game->window, game->hero->sprite, NULL);
}

void draw_static_monster(g_t *game)
{
    for (enemy_t *t = game->enemy; t != NULL; t = t->next) {
        if (t->sprite)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
    sfRenderWindow_drawSprite(game->window, game->hero->sprite, NULL);
}

void draw_my_game(g_t *game)
{
    if (game->command->mark == 2) {
        draw_my_real_game(game);
        return;
    }
    for (but_t *t = game->but; t->mark <= 2; t = t->next) {
        if (t->color == 1 && t->sprite && t->mark == 1) {
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
            break;
        }
        if (t->sprite)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
    for (but_t *t = game->but; t->mark <= 4; t = t->next) {
        if (t->color == 1 && t->sprite && t->mark == 3) {
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
            break;
        }
        if (t->sprite && t->mark == 4)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
    draw_static_monster(game);
}
