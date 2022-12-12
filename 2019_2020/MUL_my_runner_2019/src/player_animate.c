/*
** EPITECH PROJECT, 2019
** player_animate.c
** File description:
** yes
*/

#include "../include/my.h"

void animate_player_run(st_s *st)
{
    if (st->time_player.microseconds / 1000000.0 > 0.10) {
        if (st->gp_run_rect.left < 501)
            st->gp_run_rect.left += 167;
        else st->gp_run_rect.left = 0;
        sfClock_restart(st->player_clock);
    }
}

void animate_player_duck(st_s *st)
{
    if (st->time_player.microseconds / 1000000.0 > 0.015) {
        if (st->action == 0) {
            if (st->gp_duck_rect.left > 2420)
                st->gp_duck_rect.left -= 242;
            else {
                if (st->gp_duck_rect.left < 2420)
                    st->gp_duck_rect.left += 242;
                else st->gp_duck_rect.left = 1936;
            }
        }
        else {
            if (st->gp_duck_rect.left < 4840)
                st->gp_duck_rect.left += 242;
            else {
                st->gp_duck_rect.left = 0;
                st->is_finished_duck = 1;
            }
        }
        sfClock_restart(st->player_clock);
    }
}

void animate_player_jump(st_s *st)
{
    if (st->time_player.microseconds / 1000000.0 > 0.10) {
        if (st->action == 2) {
            if (st->gp_jump_rect.left > 286)
                st->gp_duck_rect.left -= 143;
            else {
                if (st->gp_jump_rect.left < 286)
                    st->gp_jump_rect.left += 143;
                else st->gp_jump_rect.left = 143;
            }
        }
        else {
            if (st->gp_jump_rect.left < 286)
                st->gp_jump_rect.left += 143;
            else {
                st->gp_jump_rect.left = 0;
                st->is_finished_jump = 2;
            }
        }
        sfClock_restart(st->player_clock);
    }
}

void draw_frame(st_s *st)
{
    if (st->action == 0 || st->is_finished_duck == 0) {
        sfSprite_setTextureRect(st->gp_duck, st->gp_duck_rect);
        sfSprite_setPosition(st->gp_duck, pos(100.0, 450.0));
        sfRenderWindow_drawSprite(st->window, st->gp_duck, NULL);
    }
    if (st->action == 1 && st->is_finished_duck == 1 &&
        st->is_finished_jump == 2) {
        sfSprite_setTextureRect(st->gp_run, st->gp_run_rect);
        sfSprite_setPosition(st->gp_run, pos(180.0, 450.0));
        sfRenderWindow_drawSprite(st->window, st->gp_run, NULL);
    }
    if (st->action == 2 || st->is_finished_jump == 0) {
        sfSprite_setTextureRect(st->gp_jump, st->gp_jump_rect);
        sfSprite_setPosition(st->gp_jump, pos(180.0, 270.0));
        sfRenderWindow_drawSprite(st->window, st->gp_jump, NULL);
    }
}

void draw_player(st_s *st)
{
    st->time_player = sfClock_getElapsedTime(st->player_clock);

    if (st->action == 0 || st->is_finished_duck == 0)
        animate_player_duck(st);
    if (st->action == 1 && st->is_finished_duck == 1 &&
        st->is_finished_jump == 2)
        animate_player_run(st);
    if (st->action == 2 || st->is_finished_jump == 0)
        animate_player_jump(st);
    draw_frame(st);
}
