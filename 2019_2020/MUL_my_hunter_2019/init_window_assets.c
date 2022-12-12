/*
** EPITECH PROJECT, 2019
** init_window_assets.c
** File description:
** init sprites
*/

#include "include/my.h"

void initialize(display_s *toto, files_s *files)
{
    toto->miss = 0;
    toto->gameover = 0;
    toto->fish_speed = 2;
    toto->fish_lenght = 0;
    toto->score_count = 0;
    toto->fish_height = 500;
    sfMusic_stop(toto->music3);
    sfText_setString(toto->score_text, "0");
    toto->fish_rect = (sfIntRect) {0, 0, 160, 160}; 
}

void init_actions(sfRenderWindow *window, display_s *toto, files_s *files)
{   
    sfMusic_play(toto->music1);
    sfRenderWindow_clear(window, sfWhite);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setMouseCursorVisible(window, sfFalse);
}

void execute_all(sfRenderWindow *window, display_s *toto, files_s *files)
{
    init_sprites(toto, files);
    initialize(toto, files);
    init_actions(window, toto, files);
}