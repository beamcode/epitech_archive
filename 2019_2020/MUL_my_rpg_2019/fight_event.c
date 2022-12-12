/*
** EPITECH PROJECT, 2020
** c
** File description:
** c
*/

#include "include/my.h"

void incrsut_runaway_or_not(g_t *game, command_t *c)
{
    for (but_t *t = game->but; t != NULL; t = t->next) {
        if (c->pos_mouse.x > 1140 && c->pos_mouse.x < 1340
            && c->pos_mouse.y > 140 && c->pos_mouse.y < 260) {
            if (t->mark == 3) {
                t->color = 1;
                continue;
            }
        } else
            t->color = 0;
        if (c->pos_mouse.x > 640 && c->pos_mouse.x < 840
            && c->pos_mouse.y > 140 && c->pos_mouse.y < 260) {
            if (t->mark == 1) {
                t->color = 1;
                continue;
            }
        } else
            t->color = 0;
    }
}

int runaway_or_not(g_t *game, command_t *c)
{
    c->pos_mouse = sfMouse_getPositionRenderWindow(game->window);
    if (game->event.type == sfEvtMouseButtonPressed) {
        c->position_clic = sfMouse_getPositionRenderWindow(game->window);
        if (c->position_clic.x > 1140 && c->position_clic.x < 1280
            && c->position_clic.y > 140 && c->position_clic.y < 260)
            c->mark = 1;
        if (c->position_clic.x > 640 && c->position_clic.x < 780
            && c->position_clic.y > 140 && c->position_clic.y < 260)
            c->mark = 2;
    }
    incrsut_runaway_or_not(game, c);
    return (c->mark);
}

void change_color_sprite(g_t *game, command_t *c)
{
    for (enemy_t *t = game->enemy; t != NULL; t = t->next) {
        if (c->pos_mouse.x > t->pos.x
            && c->pos_mouse.x < (t->pos.x + game->sizex)
            && c->pos_mouse.y > t->pos.y
            && c->pos_mouse.y < (t->pos.y + game->sizey) && t->sprite)
            sfSprite_setColor(t->sprite, sfRed);
        else if (t->sprite)
            sfSprite_setColor(t->sprite, sfWhite);
    }
}

int search_event_fight(g_t *game, command_t *c)
{
    if (game->event.type == sfEvtClosed)
        sfRenderWindow_close(game->window);
    if (c->mark == 0) {
        if (runaway_or_not(game, c) == 1)
            return (88);
        if (runaway_or_not(game, c) == 0)
            return (0);
    }
    for (but_t *t = game->but; t != NULL; t = t->next) {
        if (check_first_incrusted_button(t, c) == 1)
            continue;
        if (check_sec_incrusted_button(t, c) == 1)
            continue;
        if (check_third_incrusted_button(t, c) == 1)
            continue;
        if (check_forth_incrusted_button(t, c) == 1)
            continue;
    }
    change_color_sprite(game, c);
    return (0);
}
