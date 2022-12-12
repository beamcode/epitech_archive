/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_pause.c
*/

#include "include/my.h"

void create_pause(window_t *win)
{
    win->scene = malloc(sizeof(scene_t));
    win->scene->object = malloc(sizeof(game_t));
    win->scene->button = malloc(sizeof(button_t) * 3);
    win->scene->nb_object = 1;
    win->scene->nb_button = 3;

    win->scene->object[0].texture = sfTexture_createFromFile
        ("assets/back/scene3.png", NULL);
    win->scene->object[0].sprite = sfSprite_create();
    sfSprite_setTexture(win->scene->object[0].sprite,
                        win->scene->object[0].texture, sfTrue);
    init_pause_button(win->scene->button);
    win->scene->type = PAUSE;
}
