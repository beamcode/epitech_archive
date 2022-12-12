/*
** EPITECH PROJECT, 2019
** menu_music.c
** File description:
** yes
*/

#include "../include/my.h"

void put_menu_music(st_s *st)
{
    static int run_once = 0;

    if (st->music_on_off == 1) {
        if (run_once == 0) {
            sfMusic_play(st->menu_music);
            sfMusic_setLoop(st->menu_music, sfTrue);
            run_once = 1;
        }
    }
    else {
        if (run_once == 1)
            sfMusic_stop(st->menu_music);
            run_once = 0;
    }
}

void play_menu_music(st_s *st)
{
    put_menu_music(st);
}
