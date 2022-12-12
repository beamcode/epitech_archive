/*
** EPITECH PROJECT, 2020
** set text color
** File description:
** color
*/
#include "include/my.h"

void set_color_two(text_t *text)
{
    sfText_setColor(text->scroll_text, sfBlack);
    sfText_setColor(text->quest, sfWhite);
    sfText_setColor(text->level, sfBlack);
    sfText_setColor(text->menu_v, sfWhite);
    sfText_setColor(text->game_v, sfWhite);
    sfText_setColor(text->sound_v, sfWhite);
    sfText_setColor(text->key1, sfWhite);
    sfText_setColor(text->key2, sfWhite);
    sfText_setColor(text->key3, sfWhite);
}

void set_color(text_t *text)
{
    sfText_setColor(text->life, sfWhite);
    sfText_setColor(text->lifemax, sfWhite);
    sfText_setColor(text->xp, sfWhite);
    sfText_setColor(text->div, sfWhite);
    sfText_setColor(text->div2, sfWhite);
    sfText_setColor(text->xpmax, sfWhite);
    sfText_setColor(text->time, sfWhite);
    sfText_setColor(text->points, sfBlack);
    sfText_setColor(text->lifestat, sfBlack);
    sfText_setColor(text->xpstat, sfBlack);
    sfText_setColor(text->res, sfBlack);
    sfText_setColor(text->dam, sfBlack);
    sfText_setColor(text->open_inv, sfWhite);
    sfText_setColor(text->pause, sfWhite);
    sfText_setColor(text->stats, sfWhite);
    set_color_two(text);
    set_font(text);
}
