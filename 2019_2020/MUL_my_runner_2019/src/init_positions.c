/*
** EPITECH PROJECT, 2019
** init_values.c
** File description:
** init sprites
*/

#include "../include/my.h"

void init_rects_gp_duck(st_s *st)
{
    st->gp_duck_rect.width = 242;
    st->gp_duck_rect.height = 237;
    st->gp_duck_rect.left = 0;
    st->gp_duck_rect.top = 0;
    sfSprite_setTextureRect(st->gp_duck, st->gp_duck_rect);
}

void init_rects_gp_jump(st_s *st)
{
    st->gp_jump_rect.width = 143;
    st->gp_jump_rect.height = 235;
    st->gp_jump_rect.left = 0;
    st->gp_jump_rect.top = 0;
    sfSprite_setTextureRect(st->gp_jump, st->gp_jump_rect);
}

void init_rects_gp_run(st_s *st)
{
    st->gp_run_rect.width = 167;
    st->gp_run_rect.height = 235;
    st->gp_run_rect.left = 0;
    st->gp_run_rect.top = 0;
    sfSprite_setTextureRect(st->gp_run, st->gp_run_rect);
}

void init_game_enemy_pos(st_s *st)
{
    sfSprite_setPosition(st->ge_robot1, (sfVector2f) {3200, 400});
    sfSprite_setPosition(st->ge_robot2, (sfVector2f) {3200, 400});
    sfSprite_setPosition(st->ge_slug1, (sfVector2f) {2200, 570});
    sfSprite_setPosition(st->ge_slug2, (sfVector2f) {2200, 570});
}

void init_game_positions(st_s *st)
{
    init_game_enemy_pos(st);

    init_rects_gp_run(st);
    init_rects_gp_jump(st);
    init_rects_gp_duck(st);
}