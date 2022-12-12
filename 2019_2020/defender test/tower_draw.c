/*
** EPITECH PROJECT, 2019
** clock_func.c
** File description:
** yes
*/

#include "include/my.h"

sfIntRect tower_anim(sfTime time, sfClock *clock, sfIntRect rect)
{
    time = sfClock_getElapsedTime(clock);
    if (time.microseconds / 1000000.0 > 0.17) {
        if (rect.left < 900)
            rect.left += 300;
        else
            rect.left = 0;
        sfClock_restart(clock);
    }
    return (rect);
}

void draw_towers(st_s *st)
{
    for (int a = 0; a < 7; a++) {
        if (st->slots[a] >= 0 && st->slots[a] <= 2) {
            st->t_rect[a] = tower_anim(st->t_time[a], st->t_clock[a], st->t_rect[a]);
            sfSprite_setTextureRect(st->towers[a][st->slots[a]], st->t_rect[a]);
            draw_sprite(st->window, st->towers[a][st->slots[a]], NULL);
        }
    }
    if (st->prev > 0)
        draw_sprite(st->window, st->preview_sprite, NULL);
}