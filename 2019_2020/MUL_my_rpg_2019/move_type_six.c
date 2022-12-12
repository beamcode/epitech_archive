/*
** EPITECH PROJECT, 2020
** six
** File description:
** six
*/
#include "include/my.h"

void rect_mob_six_sec(mob_t *t)
{
    if (t->tmp == 0) {
        t->rect.top = 0;
        t->rect.left = 634;
        t->rect.width = 160;
        t->rect.height = 180;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 1) {
        t->rect.top = 0;
        t->rect.left = 797;
        t->rect.width = 160;
        t->rect.height = 180;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    rect_six(t);
}

void rect_mob_six(mob_t *t)
{
    if (t->tmp == 0) {
        t->rect.top = 0;
        t->rect.left = 8;
        t->rect.width = 153;
        t->rect.height = 180;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 1) {
        t->rect.top = 0;
        t->rect.left = 160;
        t->rect.width = 153;
        t->rect.height = 180;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    rect_seven(t);
}

void set_pos_type_six(mob_t *t)
{
    if (t->count == 1 && (t->pos.y - t->ipos.y) > 0) {
        t->pos.y -= 0.5;
        if (t->mv > 0.2) {
            rect_mob_six_sec(t);
            t->tmp++;
            if (t->tmp == 4)
                t->tmp = 0;
            t->mv = 0;
        }
    }
    if ((t->pos.y - t->ipos.y) == 0) {
        t->count = 0;
    }
    sfSprite_setPosition(t->sprite, t->pos);
    t->pos_max.x = t->pos.x + 160;
    t->pos_min.x = t->pos.x + 0;
    t->pos_max.y = t->pos.y + 150;
    t->pos_min.y = t->pos.y + 10;
}

void move_type_six(mob_t *t)
{
    if ((t->pos.y - t->ipos.y) < 150 && t->count == 0) {
        t->pos.y += 0.5;
        if (t->mv > 0.2) {
            rect_mob_six(t);
            t->tmp++;
            if (t->tmp == 4)
                t->tmp = 0;
            t->mv = 0;
        }
    }
    if ((t->pos.y - t->ipos.y) >= 150) {
        t->pos.x += 0.5;
        t->count = 1;
    }
    set_pos_type_six(t);
}
