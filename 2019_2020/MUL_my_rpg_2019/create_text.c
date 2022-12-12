/*
** EPITECH PROJECT, 2020
** create text
** File description:
** create text
*/
#include "include/my.h"

void create_text_sec(text_t *text)
{
    text->pause = sfText_create();
    text->stats = sfText_create();
    text->quest = sfText_create();
    text->level = sfText_create();
    text->menu_v = sfText_create();
    text->game_v = sfText_create();
    text->sound_v = sfText_create();
    text->scroll_text = sfText_create();
    text->key1 = sfText_create();
    text->key2 = sfText_create();
    text->key3 = sfText_create();
}

void create_text(text_t *text)
{
    text->life = sfText_create();
    text->xp = sfText_create();
    text->xpmax = sfText_create();
    text->lifemax = sfText_create();
    text->div = sfText_create();
    text->div2 = sfText_create();
    text->time = sfText_create();
    text->points = sfText_create();
    text->lifestat = sfText_create();
    text->xpstat = sfText_create();
    text->res = sfText_create();
    text->dam = sfText_create();
    text->open_inv = sfText_create();
    create_text_sec(text);
}
