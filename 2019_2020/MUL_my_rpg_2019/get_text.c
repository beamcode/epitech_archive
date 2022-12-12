/*
** EPITECH PROJECT, 2020
** get text
** File description:
** get text
*/
#include "include/my.h"

text_t *set_font_sec(text_t *text)
{
    sfText_setFont(text->open_inv, text->font);
    sfText_setFont(text->pause, text->font);
    sfText_setFont(text->stats, text->font);
    sfText_setFont(text->quest, text->font);
    sfText_setFont(text->level, text->font);
    sfText_setFont(text->menu_v, text->font);
    sfText_setFont(text->game_v, text->font);
    sfText_setFont(text->sound_v, text->font);
    sfText_setFont(text->scroll_text, text->font);
    sfText_setFont(text->key1, text->font);
    sfText_setFont(text->key2, text->font);
    sfText_setFont(text->key3, text->font);
    return (text);
}

void set_font(text_t *text)
{
    sfText_setFont(text->life, text->font);
    sfText_setFont(text->lifemax, text->font);
    sfText_setFont(text->xp, text->font);
    sfText_setFont(text->xpmax, text->font);
    sfText_setFont(text->div, text->font);
    sfText_setFont(text->div2, text->font);
    sfText_setFont(text->time, text->font);
    sfText_setFont(text->points, text->font);
    sfText_setFont(text->lifestat, text->font);
    sfText_setFont(text->xpstat, text->font);
    sfText_setFont(text->res, text->font);
    sfText_setFont(text->dam, text->font);
    text = set_font_sec(text);
}

text_t *init_text_sec(text_t *text)
{
    sfText_setCharacterSize(text->xpstat, 30);
    sfText_setCharacterSize(text->res, 30);
    sfText_setCharacterSize(text->dam, 30);
    sfText_setCharacterSize(text->open_inv, 30);
    sfText_setCharacterSize(text->pause, 30);
    sfText_setCharacterSize(text->stats, 30);
    sfText_setCharacterSize(text->quest, 30);
    sfText_setCharacterSize(text->menu_v, 45);
    sfText_setCharacterSize(text->game_v, 45);
    sfText_setCharacterSize(text->sound_v, 45);
    sfText_setCharacterSize(text->key1, 35);
    sfText_setCharacterSize(text->key2, 35);
    sfText_setCharacterSize(text->key3, 35);
    return (text);
}

void init_text(text_t *text)
{
    sfText_setString(text->key1, "E");
    sfText_setString(text->key2, "ESC");
    sfText_setString(text->key3, "C");
    sfText_setCharacterSize(text->life, 23);
    sfText_setCharacterSize(text->lifemax, 23);
    sfText_setCharacterSize(text->xp, 23);
    sfText_setCharacterSize(text->div, 23);
    sfText_setCharacterSize(text->div2, 23);
    sfText_setCharacterSize(text->xpmax, 23);
    sfText_setCharacterSize(text->time, 60);
    sfText_setCharacterSize(text->points, 25);
    sfText_setCharacterSize(text->level, 25);
    sfText_setCharacterSize(text->lifestat, 30);
    text = init_text_sec(text);
    set_color(text);
}
