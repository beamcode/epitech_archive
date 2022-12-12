/*
** EPITECH PROJECT, 2019
** game_enemies_spawn.c
** File description:
** yes
*/

#include "../include/my.h"

void get_enemie_pos(st_s *st)
{
    st->p_robot1 = sfSprite_getPosition(st->ge_robot1);
    st->p_robot2 = sfSprite_getPosition(st->ge_robot2);
    st->p_slug1 = sfSprite_getPosition(st->ge_slug1);
    st->p_slug2 = sfSprite_getPosition(st->ge_slug2);
}

void add_increment(st_s *st)
{
    get_enemie_pos(st);
    if (st->map[st->count] == '0') {
        if (st->p_slug1.x < 0)
            sfSprite_setPosition(st->ge_slug1, (sfVector2f) {2200, 570});
        else if (st->p_slug2.x < 0)
            sfSprite_setPosition(st->ge_slug2, (sfVector2f) {2200, 570});
    }
    if (st->map[st->count] == '1') {
        if (st->p_robot1.x < 0)
            sfSprite_setPosition(st->ge_robot1, (sfVector2f) {2200, 400});
        else if (st->p_robot2.x < 0)
            sfSprite_setPosition(st->ge_robot2, (sfVector2f) {2200, 400});
    }
    st->count++;
}

void set_spawn_rate(st_s *st)
{
    st->time_enemie = sfClock_getElapsedTime(st->enemie_clock);
    if (st->time_enemie.microseconds / 1000000.0 > 1.2) {
        add_increment(st);
        sfClock_restart(st->enemie_clock);
    }
}

void draw_enemies(st_s *st)
{
    set_spawn_rate(st);
    sfRenderWindow_drawSprite(st->window, st->ge_robot1, NULL);
    sfRenderWindow_drawSprite(st->window, st->ge_robot2, NULL);
    sfRenderWindow_drawSprite(st->window, st->ge_slug1, NULL);
    sfRenderWindow_drawSprite(st->window, st->ge_slug2, NULL);
}
