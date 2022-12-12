/*
** EPITECH PROJECT, 2020
** lifebar
** File description:
** lifebar
*/

#include "include/my.h"

void display_rect_shape(sfRenderWindow *w, lifebar_t *lifebar, int nb_buttons)
{
    for (int i = 0; i < nb_buttons; i++)
        sfRenderWindow_drawRectangleShape(w, lifebar[i].rect_s, NULL);
}

sfVector2f set_vector(int x, int y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}

void create_rect_shape_color(lifebar_t *rectShape, sfColor color, int x, int y)
{
    rectShape->rect_s = sfRectangleShape_create();
    sfRectangleShape_setFillColor(rectShape->rect_s, color);
    rectShape->pos = set_vector(x, y);
    sfRectangleShape_setPosition(rectShape->rect_s, rectShape->pos);
}

lifebar_t *setup_fight(g_t *g)
{
    g->pv_bar = malloc(sizeof(but_t) * 5);
    for (int i = 0; i < 4; i += 2) {
        create_rect_shape_color(&g->pv_bar[i], sfBlack, 600 * i + 350, 200);
        g->pv_bar[i].size = set_vector(200, 20);
        sfRectangleShape_setSize(g->pv_bar[i].rect_s, g->pv_bar[i].size);
        create_rect_shape_color(&g->pv_bar[i + 1], sfRed, 600 * i + 350, 200);
        g->pv_bar[i + 1].size = set_vector(200, 20);
        sfRectangleShape_setSize(g->pv_bar[i + 1].rect_s,
        g->pv_bar[i + 1].size);
    }
    return (g->pv_bar);
}
