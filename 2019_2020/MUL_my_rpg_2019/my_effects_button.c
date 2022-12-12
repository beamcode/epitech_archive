/*
** EPITECH PROJECT, 2020
** c
** File description:
** c
*/

#include "include/my.h"

int check_first_incrusted_button(but_t *t, command_t *c)
{
    if (c->pos_mouse.x > 250 && c->pos_mouse.x < 370
        && c->pos_mouse.y > 840 && c->pos_mouse.y < 960) {
        if (t->mark == 5) {
            t->color = 1;
            return (1);
        }
    } else
        t->color = 0;
    return (0);
}

int check_sec_incrusted_button(but_t *t, command_t *c)
{
    if (c->pos_mouse.x > 650 && c->pos_mouse.x < 770
        && c->pos_mouse.y > 840 && c->pos_mouse.y < 960) {
        if (t->mark == 7) {
            t->color = 1;
            return (1);
        }
    } else
        t->color = 0;
    return (0);
}

int check_third_incrusted_button(but_t *t, command_t *c)
{
    if (c->pos_mouse.x > 1450 && c->pos_mouse.x < 1570
        && c->pos_mouse.y > 840 && c->pos_mouse.y < 960) {
        if (t->mark == 11) {
            t->color = 1;
            return (1);
        }
    } else
        t->color = 0;
    return (0);
}

int check_forth_incrusted_button(but_t *t, command_t *c)
{
    if (c->pos_mouse.x > 1050 && c->pos_mouse.x < 1170
        && c->pos_mouse.y > 840 && c->pos_mouse.y < 960) {
        if (t->mark == 9) {
            t->color = 1;
            return (1);
        }
    } else
        t->color = 0;
    return (0);
}
