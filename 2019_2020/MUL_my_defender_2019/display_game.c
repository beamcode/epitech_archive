/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** display_game.c
*/

#include "include/my.h"

void display_pause(window_t *win)
{
    sfRenderWindow_drawSprite
        (win->window, win->scene->object[0].sprite, NULL);
    sfRenderWindow_drawRectangleShape
        (win->window, win->scene->button[0].rect, NULL);
    sfRenderWindow_drawRectangleShape
        (win->window, win->scene->button[1].rect, NULL);
    sfRenderWindow_drawRectangleShape
        (win->window, win->scene->button[2].rect, NULL);
}

void display_game(window_t *win)
{
    win->game_time = sfClock_getElapsedTime(win->game_clock);
    if (win->game_time.microseconds / 1000000.0 > 1.0 / 60.0) {
        sfRenderWindow_clear(win->window, sfWhite);
        if (win->scene->type == GAME)
            start_game(win);
        if (win->scene->type == MENU) {
            sfRenderWindow_drawSprite
                (win->window, win->scene->object[0].sprite, NULL);
            sfRenderWindow_drawRectangleShape
                (win->window, win->scene->button[0].rect, NULL);
            sfRenderWindow_drawRectangleShape
                (win->window, win->scene->button[1].rect, NULL);
        }
        else if (win->scene->type == PAUSE)
            display_pause(win);
        sfRenderWindow_display(win->window);
        sfClock_restart(win->game_clock);
    }
}
