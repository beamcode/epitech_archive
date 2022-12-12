/*
** EPITECH PROJECT, 2020
** two
** File description:
** two
*/
#include "include/my.h"

void rect_mob_sec_two(mob_t *t)
{
    if (t->tmp == 0) {
        t->rect.top = 0;
        t->rect.left = 740;
        t->rect.width = 70;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 1) {
        t->rect.top = 0;
        t->rect.left = 805;
        t->rect.width = 70;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 2) {
        t->rect.top = 0;
        t->rect.left = 935;
        t->rect.width = 70;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
}

void rect_mob_two(mob_t *t)
{
    if (t->tmp == 0) {
        t->rect.top = 0;
        t->rect.left = 460;
        t->rect.width = 70;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 1) {
        t->rect.top = 0;
        t->rect.left = 535;
        t->rect.width = 70;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
    if (t->tmp == 2) {
        t->rect.top = 0;
        t->rect.left = 605;
        t->rect.width = 70;
        t->rect.height = 80;
        sfSprite_setTextureRect(t->sprite, t->rect);
    }
}

void set_pos_type_two(mob_t *t)
{
    if (t->count == 1 && (t->pos.x - t->ipos.x) > 0) {
        t->pos.x -= 0.5;
        if (t->mv > 0.09) {
            rect_mob_sec_two(t);
            t->tmp++;
            if (t->tmp == 3)
                t->tmp = 0;
            t->mv = 0;
        }
    }
    if ((t->pos.x - t->ipos.x) == 0) {
        t->count = 0;
    }
    sfSprite_setPosition(t->sprite, t->pos);
    t->pos_max.x = t->pos.x + 70;
    t->pos_min.x = t->pos.x + 10;
    t->pos_max.y = t->pos.y + 80;
    t->pos_min.y = t->pos.y + 20;
}

void move_type_two(mob_t *t)
{
    if ((t->pos.x - t->ipos.x) < 150 && t->count == 0) {
        t->pos.x += 0.5;
        if (t->mv > 0.09) {
            rect_mob_two(t);
            t->tmp++;
            if (t->tmp == 3)
                t->tmp = 0;
            t->mv = 0;
        }
    }
    if ((t->pos.x - t->ipos.x) >= 150) {
        t->pos.y += 0.5;
        t->count = 1;
    }
    set_pos_type_two(t);
}
