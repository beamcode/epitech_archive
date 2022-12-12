/*
** EPITECH PROJECT, 2020
** one
** File description:
** one
*/
#include "include/my.h"

void rect_mob_sec(mob_t *t)
{
    if (t->tmp == 0) {
        t->rect.top = 0;
        t->rect.left = 255;
        t->rect.width = 88;
        t->rect.height = 100;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 1) {
        t->rect.top = 0;
        t->rect.left = 339;
        t->rect.width = 88;
        t->rect.height = 100;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 2) {
        t->rect.top = 0;
        t->rect.left = 424;
        t->rect.width = 88;
        t->rect.height = 100;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
}

void rect_mob(mob_t *t)
{
    if (t->tmp == 0) {
        t->rect.top = 0;
        t->rect.left = 2;
        t->rect.width = 85;
        t->rect.height = 100;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 1) {
        t->rect.top = 0;
        t->rect.left = 87;
        t->rect.width = 85;
        t->rect.height = 100;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 2) {
        t->rect.top = 0;
        t->rect.left = 170;
        t->rect.width = 85;
        t->rect.height = 100;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
}

void set_pos_type_one(mob_t *t)
{
    if (t->count == 1 && (t->pos.y - t->ipos.y) > 0) {
        t->pos.y -= 0.5;
        if (t->mv > 0.2) {
            rect_mob_sec(t);
            t->tmp++;
            if (t->tmp == 3)
                t->tmp = 0;
            t->mv = 0;
        }
    }
    if ((t->pos.y - t->ipos.y) == 0) {
        t->count = 0;
    }
    sfSprite_setPosition(t->sprite, t->pos);
    t->pos_max.x = t->pos.x + 80;
    t->pos_min.x = t->pos.x + 0;
    t->pos_max.y = t->pos.y + 90;
    t->pos_min.y = t->pos.y + 10;
}

void move_type_one(mob_t *t)
{
    if ((t->pos.y - t->ipos.y) < 150 && t->count == 0) {
        t->pos.y += 0.5;
        if (t->mv > 0.2) {
            rect_mob(t);
            t->tmp++;
            if (t->tmp == 3)
                t->tmp = 0;
            t->mv = 0;
        }
    }
    if ((t->pos.y - t->ipos.y) >= 150) {
        t->pos.x += 0.5;
        t->count = 1;
    }
    set_pos_type_one(t);
}
