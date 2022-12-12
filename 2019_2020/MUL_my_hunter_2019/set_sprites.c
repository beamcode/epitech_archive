/*
** EPITECH PROJECT, 2019
** set_sprites.c
** File description:
** places the sprites
*/

#include "include/my.h"

void init_window_assets(sfRenderWindow *window, display_s *toto)
{
    sfRenderWindow_drawSprite(window, toto->bg, NULL);
    sfRenderWindow_drawSprite(window, toto->fish, NULL);
    sfSprite_setPosition(toto->crosshair, pos_mouse(toto, window));
    sfRenderWindow_drawSprite(window, toto->score_bg, NULL);
    sfRenderWindow_drawText(window, toto->text, NULL);
    sfRenderWindow_drawText(window, toto->score_text, NULL);
    sfSprite_setPosition(toto->death, pos(-17, 23));
    sfSprite_setPosition(toto->respawn, pos(450, 680));
    sfSprite_setPosition(toto->score_bg, pos(1700, 20));
    
    sfText_setPosition(toto->text, pos(1745, 20));
    sfText_setPosition(toto->score_text, pos(1775, 60));
}

void display_life(sfRenderWindow *window, display_s *toto)
{
    if (toto->gameover >= 1)
        return;
    if (toto->miss >= 3)
        toto->gameover = 1;
    if (toto->miss <= 2) {
        sfRenderWindow_drawSprite(window, toto->heart1, NULL);
        sfSprite_setPosition(toto->heart1, pos(1340, 25));
    }
    if (toto->miss <= 1) {
        sfRenderWindow_drawSprite(window, toto->heart2, NULL);
        sfSprite_setPosition(toto->heart2, pos(1450, 25));
    }
    if (toto->miss <= 0) {
        sfRenderWindow_drawSprite(window, toto->heart3, NULL);
        sfSprite_setPosition(toto->heart3, pos(1560, 25));
    }
}

void set_sprites(display_s *toto, sfRenderWindow *window, sfEvent event)
{
    init_window_assets(window, toto);
    display_life(window, toto);
    sfRenderWindow_drawSprite(window, toto->crosshair, NULL);
    if (toto->gameover >= 1) {
        sfRenderWindow_drawSprite(window, toto->death, NULL);
        sfRenderWindow_drawSprite(window, toto->respawn, NULL);
        sfRenderWindow_drawSprite(window, toto->crosshair, NULL);
        return;
    }
    sfSprite_setPosition(toto->fish, dynamic_pos(toto, event, window));
}

void spawn_sprites(sfRenderWindow *window, display_s *toto, files_s *files, sfEvent event)
{
    set_sprites(toto, window, event);
}