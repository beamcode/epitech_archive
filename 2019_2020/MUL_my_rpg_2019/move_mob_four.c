/*
** EPITECH PROJECT, 2020
** four
** File description:
** foru
*/
#include "include/my.h"

void rect_mob_four_sec(mob_t *t)
{
    if (t->tmp == 0) {
        t->rect.top = 0;
        t->rect.left = 212;
        t->rect.width = 50;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 1) {
        t->rect.top = 0;
        t->rect.left = 265;
        t->rect.width = 50;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    rect_second(t);
}

void rect_mob_four(mob_t *t)
{
    if (t->tmp == 0) {
        t->rect.top = 0;
        t->rect.left = 10;
        t->rect.width = 50;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 1) {
        t->rect.top = 0;
        t->rect.left = 58;
        t->rect.width = 50;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    rect_third(t);
}

void set_pos_type_four(mob_t *t)
{
    if (t->count == 1 && (t->pos.y - t->ipos.y) > 0) {
        t->pos.y -= 0.5;
        if (t->mv > 0.08) {
            rect_mob_four_sec(t);
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
    t->pos_max.x = t->pos.x + 50;
    t->pos_min.x = t->pos.x + 10;
    t->pos_max.y = t->pos.y + 80;
    t->pos_min.y = t->pos.y + 20;
}

void move_type_four(mob_t *t)
{
    if ((t->pos.y - t->ipos.y) < 150 && t->count == 0) {
        t->pos.y += 0.5;
        if (t->mv > 0.08) {
            rect_mob_four(t);
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
    set_pos_type_four(t);
}
