/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** destroy_game.c
*/

#include "include/my.h"

void destroy_scene(scene_t *scene)
{
    for (int i = 0; i < scene->nb_object; i++) {
        sfTexture_destroy(scene->object[i].texture);
        sfSprite_destroy(scene->object[i].sprite);
    }
    for (int i = 0; i < scene->nb_button; i++) {
        sfTexture_destroy(scene->button[i].play);
        sfRectangleShape_destroy(scene->button[i].rect);
    }
    free(scene->button);
    free(scene->object);
    free(scene);
}

void destroy_game(window_t *win)
{
    sfRenderWindow_destroy(win->window);
    destroy_scene(win->scene);
}
