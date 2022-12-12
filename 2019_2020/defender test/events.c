/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** yess
*/

#include "include/my.h"

void check_events(st_s *st)
{   
    if (st->event.type == sfEvtClosed)
        sfRenderWindow_close(st->window);

    //event pour les tours
    st->prev = check_mouse_plots(st);
    check_preview_pos(st, st->prev);
    if (st->event.type == sfEvtMouseButtonPressed)
        switch_tower(st, st->prev);



    //music click
    if (st->event.type == sfEvtMouseButtonPressed) {
        sfMusic_stop(st->click_music);
        sfMusic_play(st->click_music);
    }
}