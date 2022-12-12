/*
** EPITECH PROJECT, 2019
** clock_func.c
** File description:
** yes
*/

#include "../include/my.h"

void get_map(st_s *st, int ac, char **av)
{
    long length;
    char *buffer = 0;
    FILE *f = fopen (av[1], "rb");

    if (f) {
        fseek (f, 0, SEEK_END);
        length = ftell (f);
        fseek (f, 0, SEEK_SET);
        buffer = malloc (length);
        if (buffer) {
            fread (buffer, 1, length, f);
        }
    }
    fclose (f);
    st->map = buffer;
    if (length != 49){
        my_putstr("Invalid map!\n");
        exit(84);
    }
}

void select_window(st_s *st)
{
    sfRenderWindow_clear(st->window, sfWhite);
    if (st->current_window == 0)
        display_menu(st);
    if (st->current_window == 1)
        display_game(st);
    if (st->current_window == 2)
        sfRenderWindow_drawSprite(st->window, st->game_bg_win, NULL);
    if (st->current_window == 3)
        sfRenderWindow_drawSprite(st->window, st->game_bg_lose, NULL);
    sfRenderWindow_display(st->window);
}

void check_infinit(st_s *st)
{
    st->p_bg1 = sfSprite_getPosition(st->game_bg1);
    st->p_bg2 = sfSprite_getPosition(st->game_bg2);
    if (st->p_bg1.x <= -8664.0)
        sfSprite_setPosition(st->game_bg1, pos(0.0, 0.0));
    if (st->p_bg2.x <= -8770.0)
        sfSprite_setPosition(st->game_bg2, pos(0.0, 0.0));
}

void start_clock(st_s *st, int ac, char **av)
{
    set_init_values(st);
    get_map(st, ac, av);

    while (sfRenderWindow_isOpen(st->window)) {
        while (sfRenderWindow_pollEvent(st->window, &st->event))
            check_events(st);
        check_infinit(st);
        st->time_game = sfClock_getElapsedTime(st->game_clock);
        if (st->time_game.microseconds / 1000000.0 > 1.0 / 60.0) {
            select_window(st);
            sfClock_restart(st->game_clock);
        }
    }
}
