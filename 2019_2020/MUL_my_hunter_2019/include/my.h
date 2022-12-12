/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** Header file
*/

#ifndef FISH_HUNT
#define FISH_HUNT

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/System.h>
#include <SFML/System/Clock.h>
#include <SFML/Config.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

typedef struct display_t
{
    int fish_height;
    int fish_lenght;
    int fish_speed;
    int score_count;
    int miss;
    int gameover;
    sfIntRect fish_rect;
    sfSprite *respawn;
    sfSprite *heart1;
    sfSprite *heart2;
    sfSprite *heart3;
    sfSprite *fish;
    sfSprite *crosshair;
    sfSprite *bg;
    sfSprite *death;
    sfSprite *score_bg;
    sfText *text;
    sfText *score_text;
    sfMusic *music1;
    sfMusic *music2;
    sfMusic *music3;

}display_s;

typedef struct files
{
    sfFont *font;
    sfTexture *death_texture;
    sfTexture *respawn_texture;
    sfTexture *texture_bg;
    sfTexture *texture_heart;
    sfTexture *texture_fish;
    sfTexture *texture_crosshair;
    sfTexture *texture_score_bg;
    
}files_s;

sfVector2f dynamic_pos(display_s *toto, sfEvent event, sfRenderWindow *window);
sfVector2f pos_mouse(display_s *toto, sfRenderWindow *window);
sfVector2f pos(int x, int y);

void initialize(display_s *toto, files_s *files);
void check_events(sfRenderWindow *window, sfEvent event, display_s *toto, files_s *files);
void init_window_assets(sfRenderWindow *window, display_s *toto);
void execute_all(sfRenderWindow *window, display_s *toto, files_s *files);
void spawn_sprites(sfRenderWindow *window, display_s *toto, files_s *files, sfEvent event);
void init_sprites(display_s *toto, files_s *files);
int	my_putstr(char const *str);
char *my_itoa(int nbr);
void launch(sfRenderWindow *window, sfEvent event, display_s *toto, files_s *files);

#endif /* FISH_HUNT */