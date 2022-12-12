/*
** EPITECH PROJECT, 2020
** three
** File description:
** three
*/
#include "include/my.h"

void rect_mob_th_sec(mob_t *t)
{
    if (t->tmp == 0) {
        t->rect.top = 0;
        t->rect.left = 222;
        t->rect.width = 80;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 1) {
        t->rect.top = 0;
        t->rect.left = 295;
        t->rect.width = 80;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 2) {
        t->rect.top = 0;
        t->rect.left = 380;
        t->rect.width = 80;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
}

void rect_mob_th(mob_t *t)
{
    if (t->tmp == 0) {
        t->rect.top = 0;
        t->rect.left = 10;
        t->rect.width = 70;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 1) {
        t->rect.top = 0;
        t->rect.left = 80;
        t->rect.width = 80;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 2) {
        t->rect.top = 0;
        t->rect.left = 152;
        t->rect.width = 80;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
}

void set_pos_type_three(mob_t *t)
{
    if (t->count == 1 && (t->pos.y - t->ipos.y) > 0) {
        t->pos.y -= 0.5;
        if (t->mv > 0.08) {
            rect_mob_th_sec(t);
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
    t->pos_max.x = t->pos.x + 60;
    t->pos_min.x = t->pos.x + 10;
    t->pos_max.y = t->pos.y + 80;
    t->pos_min.y = t->pos.y + 30;
}

void move_type_three(mob_t *t)
{
    if ((t->pos.y - t->ipos.y) < 150 && t->count == 0) {
        t->pos.y += 0.5;
        if (t->mv > 0.08) {
            rect_mob_th(t);
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
    set_pos_type_three(t);
}
