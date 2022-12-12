/*
** EPITECH PROJECT, 2020
** game clock
** File description:
** game clock
*/
#include "include/my.h"

void check_type(mob_t *t)
{
    if (t->type == 1)
        move_type_one(t);
    if (t->type == 2)
        move_type_two(t);
    if (t->type == 3)
        move_type_three(t);
    if (t->type == 4)
        move_type_four(t);
    if (t->type == 5)
        move_type_five(t);
    if (t->type == 6)
        move_type_six(t);
}

void move_mob(game_t *game)
{
    for (mob_t *t = game->mob; t->mark != 20; t = t->next)
        if (t->sprite && t->mark > 0)
            t->mv += 0.01;
    for (mob_t *t = game->mob; t->mark != 20; t = t->next) {
        if (t->sprite && t->mark >= 1 && t->map == game->current_map)
            check_type(t);
    }
}

void my_game_clock(game_t *game)
{
    int tmp = 0;

    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    if (game->seconds > 0.01) {
        if (game->on_move == 1 && game->inventory == 0 && game->status == 0)
            move_player(game);
        move_mob(game);
        game->min += 0.04;
        game->mv += 0.01;
        get_time(game);
        sfClock_restart(game->clock);
    }
    tmp += 1;
    if (tmp % 2 == 1) {
        if (game->player->life != game->player->lifemax) {
            game->player->life++;
            check_bar_sprite(game);
        }
    }
}
