/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** check_position.c
*/

#include "include/my.h"

int check_two(button_t button, sfVector2i pos)
{
    if (pos.x >= button.rect_pos.x &&
        pos.x <= (button.rect_pos.x + (button.size.x / 2))
        && pos.y >= (button.rect_pos.y + (button.size.y / 2)) &&
        pos.y <= (button.rect_pos.y + button.size.y))
        return (3);
    if (pos.x >= (button.rect_pos.x + (button.size.x / 2)) &&
        pos.x <= (button.rect_pos.x + button.size.x)
        && pos.y >= (button.rect_pos.y + (button.size.y / 2)) &&
        pos.y <= (button.rect_pos.y + button.size.y))
        return (4);
    return (0);
}

int check_position(button_t button, sfVector2i pos)
{
    if (pos.x >= button.rect_pos.x &&
        pos.x <= (button.rect_pos.x + (button.size.x / 2))
        && pos.y >= button.rect_pos.y &&
        pos.y <= (button.rect_pos.y + (button.size.y / 2)))
        return (1);
    if (pos.x >= (button.rect_pos.x + (button.size.x / 2)) &&
        pos.x <= (button.rect_pos.x + button.size.x)
        && pos.y >= button.rect_pos.y &&
        pos.y <= (button.rect_pos.y + (button.size.y / 2)))
        return (2);
    return (check_two(button, pos));
}

void check_towers_two(window_t *win, int nb)
{
    if (check_position(win->scene->button[nb], win->click_pos) == 3) {
        sfRectangleShape_setPosition(win->scene->button[nb+49].rect,
        win->scene->button[nb].rect_pos);
        sfRectangleShape_setFillColor(win->scene->button[nb+49].rect, sfWhite);
        sfRenderWindow_drawRectangleShape
            (win->window, win->scene->button[nb+49].rect, NULL);
    }
    if (check_position(win->scene->button[nb], win->click_pos) == 4) {
        sfRectangleShape_setFillColor(win->scene->button[nb+7].rect,
        sfTransparent);
        sfRectangleShape_setFillColor(win->scene->button[nb+28].rect,
        sfTransparent);
        sfRectangleShape_setFillColor(win->scene->button[nb+49].rect,
        sfTransparent);
    }
}

void check_towers(window_t *win, int nb)
{
    if (check_position(win->scene->button[nb], win->click_pos) == 1) {
        sfRectangleShape_setPosition(win->scene->button[nb+7].rect,
        win->scene->button[nb].rect_pos);
        sfRectangleShape_setFillColor(win->scene->button[nb+7].rect, sfWhite);
        sfRenderWindow_drawRectangleShape
            (win->window, win->scene->button[nb+7].rect, NULL);
    }
    if (check_position(win->scene->button[nb], win->click_pos) == 2) {
        sfRectangleShape_setPosition(win->scene->button[nb+28].rect,
        win->scene->button[nb].rect_pos);
        sfRectangleShape_setFillColor(win->scene->button[nb+28].rect, sfWhite);
        sfRenderWindow_drawRectangleShape
            (win->window, win->scene->button[nb+28].rect, NULL);
    }
    check_towers_two(win, nb);
}
