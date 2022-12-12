/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** button.c
*/

#include "include/my.h"
#include <stdlib.h>

int check_mouse_pos(button_t button, sfVector2i pos)
{
        if (pos.x >= button.rect_pos.x &&
            pos.x <= (button.rect_pos.x + button.size.x)
            && pos.y >= button.rect_pos.y &&
            pos.y <= (button.rect_pos.y + button.size.y))
            return (1);
    return (0);
}

void callback_menu(window_t *win)
{
    for (int i = 0; i < 2 && win->scene->type == MENU; i++) {
        if (check_mouse_pos(win->scene->button[i], win->click_pos) == 1) {
            win->scene->button[i].callback(win);
        }
        else
            sfRectangleShape_setFillColor(win->scene->button[i].rect, sfWhite);
    }
}

void callback_game(window_t *win)
{
    for (int i = 0; i < 1 && win->scene->type == GAME; i++) {
        if (check_mouse_pos(win->scene->button[i], win->click_pos) == 1) {
            win->scene->button[i].callback(win);
        }
        else
            sfRectangleShape_setFillColor(win->scene->button[i].rect, sfWhite);
    }
    for (int i = 1; i < 8 && win->scene->type == GAME; i++) {
        if (check_mouse_pos(win->scene->button[i], win->click_pos) == 1) {
            win->scene->nb = i;
            win->scene->button[i].callback(win);
        }
        else
            sfRectangleShape_setFillColor(win->scene->button[i].rect,
            sfTransparent);
    }
}

void callback_pause(window_t *win)
{
    for (int i = 0; i < 3 && win->scene->type == PAUSE; i++) {
        if (check_mouse_pos(win->scene->button[i], win->click_pos) == 1) {
            win->scene->button[i].callback(win);
        }
        else
            sfRectangleShape_setFillColor(win->scene->button[i].rect, sfWhite);
    }
}

void button(window_t *win)
{
    scene_type_t scene = win->scene->type;

    win->click_pos = sfMouse_getPosition( (sfWindow*) win->window);
    if (scene == MENU)
        callback_menu(win);
    else if (scene == GAME)
        callback_game(win);
    else
        callback_pause(win);
}
