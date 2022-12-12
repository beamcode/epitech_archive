/*
** EPITECH PROJECT, 2020
** c
** File description:
** c
*/

#include "include/my.h"

void move_my_monster_towards(g_t *game, enemy_t *t)
{
    while (t->pos.x <= 800) {
        sfSprite_setPosition(t->sprite,
        (sfVector2f) {t->pos.x + 20, t->pos.y});
        t->pos = sfSprite_getPosition(t->sprite);
        sfRenderWindow_clear(game->window, sfBlack);
        draw_background(game, game->back);
        draw_my_real_game(game);
        sfRenderWindow_display(game->window);
    }
}

void move_my_monster_backwards(g_t *game, enemy_t *t)
{
    while (t->pos.x >= 600) {
        t->pos =  sfSprite_getPosition(t->sprite);
        sfRenderWindow_clear(game->window, sfBlack);
        draw_background(game, game->back);
        draw_my_real_game(game);
        sfRenderWindow_display(game->window);
        sfSprite_setPosition(t->sprite, (sfVector2f) {t->pos.x - 10, t->pos.y});
    }
}

void move_my_hero_backwards(g_t *game, hero_t *h, sfVector2f herop)
{
    if (herop.x <= 1500) {
        while (h->pos.x >= 1300) {
            sfSprite_setPosition(h->sprite,
            (sfVector2f) {h->pos.x - 20, h->pos.y});
            h->pos = sfSprite_getPosition(h->sprite);
            sfRenderWindow_clear(game->window, sfBlack);
            draw_background(game, game->back);
            draw_my_real_game(game);
            sfRenderWindow_display(game->window);
        }
    }
}

void move_my_hero_forwards(g_t *game, hero_t *h)
{
    while (h->pos.x < 1500) {
        sfSprite_setPosition(h->sprite,
        (sfVector2f) {h->pos.x + 20, h->pos.y});
        h->pos = sfSprite_getPosition(h->sprite);
        sfRenderWindow_clear(game->window, sfBlack);
        draw_background(game, game->back);
        draw_my_real_game(game);
        sfRenderWindow_display(game->window);
    }
}

void get_impact_monster(g_t *game, enemy_t *t)
{
    while (t->pos.x <= 580) {
        t->pos =  sfSprite_getPosition(t->sprite);
        sfRenderWindow_clear(game->window, sfBlack);
        draw_background(game, game->back);
        draw_my_real_game(game);
        sfRenderWindow_display(game->window);
        sfSprite_setPosition(t->sprite, (sfVector2f) {t->pos.x + 2, t->pos.y});
    }
}
