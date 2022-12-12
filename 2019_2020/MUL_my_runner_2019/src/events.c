/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** yess
*/

#include "../include/my.h"

void check_game_key_pressed(st_s *st)
{
    if (st->event.type == sfEvtKeyPressed) {
        if (st->event.key.code == sfKeyDown) {
            if (st->action == 2 || st->is_finished_jump == 0)
                return;
            st->action = 0;
            st->is_finished_duck = 0;
            return;
        }
        if (st->event.key.code == sfKeyUp) {
            if (st->action == 0 || st->is_finished_duck == 0)
                return;
            st->action = 2;
            st->is_finished_jump = 0;
        }
    }
    else st->action = 1;
}

void check_menu_mouse_pressed(st_s *st)
{
    if (st->event.type == sfEvtMouseButtonPressed) {
        st->pos_start = sfSprite_getPosition(st->menu_start);
        st->pos_quit = sfSprite_getPosition(st->menu_quit);
        st->pos_options = sfSprite_getPosition(st->menu_options);
        st->cursor = sfMouse_getPositionRenderWindow(st->window);

        if ((st->cursor.x >= st->pos_start.x && st->cursor.y >=
            st->pos_start.y) && ((st->cursor.x <= (st->pos_start.x + 400.0))
            && (st->cursor.y <= (st->pos_start.y + 112.0))))
            st->current_window = 1;

        if ((st->cursor.x >= st->pos_quit.x && st->cursor.y >=
            st->pos_quit.y) && ((st->cursor.x <= (st->pos_quit.x + 300.0))
            && (st->cursor.y <= (st->pos_quit.y + 83.0))))
            sfRenderWindow_close(st->window);
    }
}

void check_game_events(st_s *st)
{
    play_game_music(st);
    check_game_key_pressed(st);
}

void check_menu_events(st_s *st)
{
    play_menu_music(st);
    check_menu_mouse_pressed(st);
}

void check_events(st_s *st)
{
    if (st->event.type == sfEvtClosed)
        sfRenderWindow_close(st->window);

    if (st->current_window == 0)
        check_menu_events(st);
    if (st->current_window == 1) {
        check_game_events(st);
        sfMusic_stop(st->menu_music);
        sfMusic_stop(st->se_lose);
        sfMusic_stop(st->se_win);
    }
    if (st->current_window == 2)
        check_win_events(st);
    if (st->current_window == 3)
        check_lose_events(st);
}
