/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** yes
*/

#ifndef RUNNER_H
#define RUNNER_H

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Config.h>
#include <SFML/Window/Export.h>
#include <SFML/Window/Keyboard.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../lib/my/my_lib.h"

#define draw_sprite(win, sprite, state) sfRenderWindow_drawSprite(win, sprite, state);
#define pos_sprite(sprite, vect) sfSprite_setPosition(sprite, vect);

typedef struct st
{
    sfRenderWindow *window;
    sfEvent event;
    sfClock *game_clock;
    sfTime game_time;
    sfVector2i pos_cursor;
    int prev;
    int *slots;
    int score;

    sfMusic *game_music;
    sfMusic *click_music;
    //map
    sfSprite *map_sprite;
    sfTexture *map_texture;
    //cursor
    sfSprite *cursor_sprite;
    sfTexture *cursor_texture;
    //preview
    sfSprite *preview_sprite;
    sfTexture *preview_texture;
    //preview
    sfSprite *pause_sprite;
    sfTexture *pause_texture;
    //preview
    sfSprite *goblin_sprite;
    sfTexture *goblin_texture;
    sfIntRect goblin_rect;
    sfClock *goblin_clock;
    sfTime goblin_time;


    //se quil faux pour les tour ici
    //towers
    sfSprite ***towers;
    sfTexture **tower_texture;
    sfClock **t_clock;
    sfTime *t_time;
    sfIntRect *t_rect;

    //score
    sfFont *score_font;
    sfText *score_text;
}st_s;

//tower_events.c 
int check_mouse_plots(st_s *st);
void check_preview_pos(st_s *st, int prev);
void switch_tower(st_s *st, int prev);
//
void draw_towers(st_s *st);
sfVector2f pos_mouse(st_s *st, sfRenderWindow *window);
sfVector2f pos(double x, double y);
void check_events(st_s *st);
int create_window(int ac, char **av);

#endif