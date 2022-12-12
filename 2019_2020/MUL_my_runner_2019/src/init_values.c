/*
** EPITECH PROJECT, 2019
** init_values.c
** File description:
** init sprites
*/

#include "../include/my.h"

void init_menu_bg_pos(st_s *st)
{
    st->menu_bg_rect.width = 870;
    st->menu_bg_rect.height = 388;
    st->menu_bg_rect.left = 0;
    st->menu_bg_rect.top = 0;
    sfSprite_setTextureRect(st->menu_bg, st->menu_bg_rect);
}

void init_values(st_s *st)
{
    st->fps = 60;
    st->volume = 100;
    st->music_on_off = 1;

    st->win_lose = 0;
    st->score = 0;
    st->count = 0;

    st->action = 1;
    st->is_finished_duck = 1;
    st->is_finished_jump = 2;
}

void init_actions(st_s *st)
{
    sfRenderWindow_setFramerateLimit(st->window, 60);
    sfRenderWindow_setMouseCursorVisible(st->window, sfTrue);
    sfRenderWindow_setVerticalSyncEnabled(st->window, sfTrue);
    sfRenderWindow_setKeyRepeatEnabled(st->window, sfTrue);
}

void create_clocks(st_s *st)
{
    st->game_clock = sfClock_create();
    st->menu_clock = sfClock_create();
    st->player_clock = sfClock_create();
    st->enemie_clock = sfClock_create();
}

void set_init_values(st_s *st)
{
    init_actions(st);
    init_values(st);
    create_clocks(st);

    init_menu_assets(st);
    init_game_assets(st);

    init_game_positions(st);
    init_menu_bg_pos(st);
}
