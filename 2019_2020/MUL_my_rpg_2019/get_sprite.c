/*
** EPITECH PROJECT, 2019
** sprite
** File description:
** sprite
*/
#include "include/my.h"

void display_pause(game_t *game)
{
    for (button_t *t = game->button; t->mark != 76; t = t->next) {
        if (t->sprite && t->mark == 71)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
        if (t->sprite && t->mark == 74 && game->p1_on == 1)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
        if (t->sprite && t->mark == 73 && game->p2_on == 1)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
        if (t->sprite && t->mark == 72 && game->p3_on == 1)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
        if (t->sprite && t->mark == 75 && game->p4_on == 1)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
}

void display_stats(game_t *game)
{
    display_lifebar(game);
    display_xpbar(game);
}

void display_map(game_t *game)
{
    for (map_t *t = game->map; t->nb != 11; t = t->next)
        if (t->sprite && t->nb == game->current_map)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    if (game->hours >= 20 || game->hours < 8) {
        for (button_t *t = game->button; t->mark != 107; t = t->next)
            if (t->sprite && t->mark >= 106)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
    display_mob_pnj(game);
    load_quest(game);
    display_quest_cursor(game);
    display_quest_indicator(game);
}

void display_game(game_t *game)
{
    if (game->credits == 1)
        draw_credits(game);
    if (game->new_game == 1)
        game->new_game = 0;
    display_map(game);
    sfRenderWindow_drawSprite(game->window, game->player->sprite, NULL);
    display_inventory(game);
    display_stats(game);
    if (game->status == 1)
        display_statusmenu(game);
    if (game->menupause == 1)
        display_pause(game);
}

void display_sprite(game_t *game)
{
    if (game->cinematic == 1) {
        for (button_t *t = game->button; t->mark != 130; t = t->next)
            if (t->sprite && (t->mark == 128 || t->mark == 129)
                && game->cinematic == 1)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
        for (button_t *t = game->button; t->mark != 131; t = t->next)
            if (t->sprite && t->mark == 130 && game->cinematic == 1
                && game->pass == 1)
                sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    }
    if (game->credits == 1)
        draw_credits(game);
    if (game->menu == 0)
        display_game(game);
    if (game->menu == 1 && game->cinematic == 0)
        display_menu(game);
}
