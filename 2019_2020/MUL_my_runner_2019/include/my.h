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
#include <sys/stat.h>
#include <sys/types.h>
#include "../src/lib/my_lib.h"

typedef struct st
{
    sfRenderWindow *window;
    sfEvent event;
    sfVector2i cursor;
    sfClock *game_clock;
    sfClock *menu_clock;
    sfClock *player_clock;
    sfClock *enemie_clock;
    sfTime time_game;
    sfTime time_menu;
    sfTime time_player;
    sfTime time_enemie;
    int fps;
    int music_on_off;
    int volume;
    int score;
    int win_lose;
    int current_window;
    int action;
    int is_finished_duck;
    int is_finished_jump;
    int count;
    char *map;
    sfSprite *game_bg1;
    sfSprite *game_bg2;
    sfSprite *game_bg3;
    sfSprite *game_bg_win;
    sfSprite *game_bg_lose;
    sfText *score_text;
    sfSprite *gp_run;
    sfSprite *gp_duck;
    sfSprite *gp_jump;
    sfSprite *ge_robot1;
    sfSprite *ge_robot2;
    sfSprite *ge_slug1;
    sfSprite *ge_slug2;
    sfIntRect gp_run_rect;
    sfIntRect gp_duck_rect;
    sfIntRect gp_jump_rect;
    sfVector2f p_bg1;
    sfVector2f p_bg2;
    sfVector2f p_bg3;
    sfVector2f p_robot1;
    sfVector2f p_robot2;
    sfVector2f p_slug1;
    sfVector2f p_slug2;
    sfVector2f *p_player_run;
    sfVector2f *p_player_jump;
    sfVector2f *p_player_duck;
    sfSprite *menu_bg;
    sfSprite *menu_logo;
    sfSprite *menu_start;
    sfSprite *menu_quit;
    sfSprite *menu_options;
    sfSprite *menu_menu_guy;
    sfIntRect menu_bg_rect;
    sfVector2f pos_start;
    sfVector2f pos_quit;
    sfVector2f pos_options;
    sfMusic *menu_music;
    sfMusic *game_music;
    sfMusic *se_win;
    sfMusic *se_lose;
    sfTexture *menu_file_bg;
    sfTexture *menu_file_logo;
    sfTexture *menu_file_start;
    sfTexture *menu_file_quit;
    sfTexture *menu_file_options;
    sfTexture *menu_file_menu_guy;
    sfTexture *gf_bg1;
    sfTexture *gf_bg2;
    sfTexture *gf_bg3;
    sfTexture *gf_bg_win;
    sfTexture *gf_bg_lose;
    sfTexture *gf_player_run;
    sfTexture *gf_player_duck;
    sfTexture *gf_player_jump;
    sfTexture *gf_robot;
    sfTexture *gf_slug;
    sfFont *gf_font;
}st_s;

sfVector2f pos(double x, double y);

void start_clock(st_s *st, int ac, char **av);
void init_game_enemy_pos(st_s *st);

void check_events(st_s *st);
void check_win_events(st_s *st);
void check_lose_events(st_s *st);
void set_init_values(st_s *st);

void win(st_s *st);
void lose(st_s *st);

void init_menu_assets(st_s *st);
void init_game_assets(st_s *st);
void init_game_positions(st_s *st);

void display_menu(st_s *st);
void display_game(st_s *st);

void draw_player(st_s *st);
void draw_enemies(st_s *st);

void play_game_music(st_s *st);
void play_menu_music(st_s *st);

#endif
