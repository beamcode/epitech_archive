/*
** EPITECH PROJECT, 2019
** game_window.c
** File description:
** yes
*/

#include "../include/my.h"

void check_hit(st_s *st)
{
    st->p_robot1 = sfSprite_getPosition(st->ge_robot1);
    st->p_robot2 = sfSprite_getPosition(st->ge_robot2);
    st->p_slug1 = sfSprite_getPosition(st->ge_slug1);
    st->p_slug2 = sfSprite_getPosition(st->ge_slug2);
    if (st->count == 50)
        win(st);
    if (((st->p_robot1.x >= 180.0) && (st->p_robot1.x <= 220.0)) ||
        ((st->p_robot2.x >= 180.0) && (st->p_robot2.x <= 220.0))) {
        if (st->action == 0 || st->is_finished_duck == 0)
            return;
        else lose(st);
    }
    if (((st->p_slug1.x >= 180.0) && (st->p_slug1.x <= 220.0)) ||
        ((st->p_slug2.x >= 180.0) && (st->p_slug2.x <= 220.0))) {
        if (st->action == 2 || st->is_finished_jump == 0)
            return;
        else lose(st);
    }
}

void set_movments(st_s *st)
{
    sfSprite_move(st->game_bg2, pos(-6.0, 0.0));
    sfSprite_move(st->game_bg1, pos(-8.0, 0.0));

    sfSprite_move(st->ge_robot1, pos(-15.0, 0.0));
    sfSprite_move(st->ge_robot2, pos(-15.0, 0.0));
    sfSprite_move(st->ge_slug1, pos(-15.0, 0.0));
    sfSprite_move(st->ge_slug2, pos(-15.0, 0.0));
}

void draw_order(st_s *st)
{
    sfRenderWindow_drawSprite(st->window, st->game_bg3, NULL);
    sfRenderWindow_drawSprite(st->window, st->game_bg2, NULL);
    draw_player(st);
    draw_enemies(st);
    sfRenderWindow_drawSprite(st->window, st->game_bg1, NULL);
    sfRenderWindow_drawText(st->window, st->score_text, NULL);

    sfText_setPosition(st->score_text, pos(1775, 60));
    sfText_setString(st->score_text, my_itoa(st->count * 2));
}

void display_game(st_s *st)
{
    draw_order(st);
    set_movments(st);
    check_hit(st);
}
