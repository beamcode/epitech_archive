/*
** EPITECH PROJECT, 2019
** menu_sprite_load.c
** File description:
** gets st
*/

#include "../include/my.h"

void create_menu_sprites(st_s *st)
{
    st->menu_bg = sfSprite_create();
    st->menu_logo = sfSprite_create();
    st->menu_start = sfSprite_create();
    st->menu_quit = sfSprite_create();
    st->menu_options = sfSprite_create();
    st->menu_menu_guy = sfSprite_create();
}

void get_menu_st(st_s *st)
{
    st->menu_file_bg = sfTexture_createFromFile
    ("assets/menu_bg/menu.png", NULL);
    st->menu_file_logo = sfTexture_createFromFile
    ("assets/menu_bg/2077.png", NULL);
    st->menu_file_start = sfTexture_createFromFile
    ("assets/menu_bg/start.png", NULL);
    st->menu_file_quit = sfTexture_createFromFile
    ("assets/menu_bg/quit.png", NULL);
    st->menu_file_options = sfTexture_createFromFile
    ("assets/menu_bg/options.png", NULL);
    st->menu_file_menu_guy = sfTexture_createFromFile
    ("assets/menu_bg/menu_guy.png", NULL);

    st->menu_music = sfMusic_createFromFile ("assets/music/menu_music.ogg");
    st->se_win = sfMusic_createFromFile ("assets/music/win.ogg");
    st->se_lose = sfMusic_createFromFile ("assets/music/lose.ogg");
}

void associate_menu_assets(st_s *st)
{
    sfSprite_setTexture(st->menu_bg, st->menu_file_bg, sfTrue);
    sfSprite_setTexture(st->menu_logo, st->menu_file_logo, sfTrue);
    sfSprite_setTexture(st->menu_start, st->menu_file_start, sfTrue);
    sfSprite_setTexture(st->menu_quit, st->menu_file_quit, sfTrue);
    sfSprite_setTexture(st->menu_options, st->menu_file_options, sfTrue);
    sfSprite_setTexture(st->menu_menu_guy, st->menu_file_menu_guy, sfTrue);
}

void init_menu_assets(st_s *st)
{
    create_menu_sprites(st);
    get_menu_st(st);
    associate_menu_assets(st);
}