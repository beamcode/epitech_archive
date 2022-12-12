/*
** EPITECH PROJECT, 2019
** lose_win_events.c
** File description:
** yes
*/

#include "../include/my.h"

void check_win_events(st_s *st)
{
    if (st->event.type == sfEvtMouseButtonPressed) {
        st->cursor = sfMouse_getPositionRenderWindow(st->window);

        if ((st->cursor.x >= 1685.0 && st->cursor.y >=
            0.0) && ((st->cursor.x <= 1920.0)
            && (st->cursor.y <= 155.0))) {
            st->current_window = 0;
            sfMusic_stop(st->se_win);
            sfMusic_play(st->menu_music);
        }
    }
}

void check_lose_events(st_s *st)
{
    if (st->event.type == sfEvtMouseButtonPressed) {
        st->cursor = sfMouse_getPositionRenderWindow(st->window);

        if ((st->cursor.x >= 1400.0 && st->cursor.y >=
            805.0) && ((st->cursor.x <= 1608.0)
            && (st->cursor.y <= 1006.0)))
            st->current_window = 1;
        if ((st->cursor.x >= 1685.0 && st->cursor.y >=
            0.0) && ((st->cursor.x <= 1920.0)
            && (st->cursor.y <= 155.0))) {
            st->current_window = 0;
            sfMusic_stop(st->se_lose);
            sfMusic_play(st->menu_music);
        }
    }
}

void win(st_s *st)
{
    sfMusic_stop(st->game_music);
    sfMusic_play(st->se_win);
    st->count = 0;
    st->current_window = 2;
    init_game_enemy_pos(st);
}

void lose(st_s *st)
{
    sfMusic_stop(st->game_music);
    sfMusic_play(st->se_lose);
    st->count = 0;
    st->current_window = 3;
    init_game_enemy_pos(st);
}