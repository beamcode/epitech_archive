/*
** EPITECH PROJECT, 2019
** game_music.c
** File description:
** yes
*/

#include "../include/my.h"

void put_game_music(st_s *st)
{
    static int run_once = 0;

    if (st->count == 0)
        run_once = 0;
    if (st->music_on_off == 1) {
        if (run_once == 0) {
            sfMusic_setLoop(st->game_music, sfTrue);
            sfMusic_play(st->game_music);
            run_once = 1;
        }
    }
    else {
        if (run_once == 1)
            sfMusic_stop(st->game_music);
            run_once = 0;
    }
}

void play_game_music(st_s *st)
{
    put_game_music(st);
}
