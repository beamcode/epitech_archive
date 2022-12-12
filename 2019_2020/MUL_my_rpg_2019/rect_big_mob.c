/*
** EPITECH PROJECT, 2020
** rect big mob
** File description:
** rect big mob
*/
#include "include/my.h"

void rect_second(mob_t *t)
{
    if (t->tmp == 2) {
        t->rect.top = 0;
        t->rect.left = 317;
        t->rect.width = 50;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 3) {
        t->rect.top = 0;
        t->rect.left = 372;
        t->rect.width = 50;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
}

void rect_third(mob_t *t)
{
    if (t->tmp == 2) {
        t->rect.top = 0;
        t->rect.left = 108;
        t->rect.width = 50;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 3) {
        t->rect.top = 0;
        t->rect.left = 160;
        t->rect.width = 50;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
}

void rect_six(mob_t *t)
{
    if (t->tmp == 2) {
        t->rect.top = 0;
        t->rect.left = 958;
        t->rect.width = 160;
        t->rect.height = 180;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 3) {
        t->rect.top = 0;
        t->rect.left = 1119;
        t->rect.width = 160;
        t->rect.height = 180;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
}

void rect_seven(mob_t *t)
{
    if (t->tmp == 2) {
        t->rect.top = 0;
        t->rect.left = 318;
        t->rect.width = 153;
        t->rect.height = 180;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 3) {
        t->rect.top = 0;
        t->rect.left = 472;
        t->rect.width = 153;
        t->rect.height = 180;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
}
