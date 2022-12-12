/*
** EPITECH PROJECT, 2019
** vectors.c
** File description:
** vector functions for the spirtes
*/

#include "include/my.h"

sfVector2f pos(int x, int y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfVector2f pos_mouse(display_s *toto, sfRenderWindow *window)
{
    sfVector2i vector_mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2f vector1;

    vector1.x = vector_mouse.x - 101;
    vector1.y = vector_mouse.y - 101;
    return (vector1);
}

sfVector2f dynamic_pos(display_s *toto, sfEvent event, sfRenderWindow *window)
{
    sfVector2f vector;

    srand(time(NULL));
    if (toto->fish_lenght >= 1800) {
        toto->fish_lenght = -170;
        toto->miss++;
        toto->fish_height = rand() % 1000;
    }
    toto->fish_lenght += toto->fish_speed;
    vector.x = toto->fish_lenght;
    vector.y = toto->fish_height;
    return (vector);
}