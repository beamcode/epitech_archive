/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_game.c
*/

#include "include/my.h"

void init_goblins(window_t *win)
{
    int x = -400;

    for (int i = 1; i < 11; i++, x += 40) {
        win->scene->object[i].rect.left = 0;
        win->scene->object[i].rect.top = 95;
        win->scene->object[i].rect.width = 95;
        win->scene->object[i].rect.height = 95;
        win->scene->object[i].clock = sfClock_create();
        win->scene->object[i].texture = sfTexture_createFromFile
            ("assets/attackers/goblin.png", NULL);
        win->scene->object[i].sprite = sfSprite_create();
        sfSprite_setTexture(win->scene->object[i].sprite,
        win->scene->object[i].texture, sfTrue);
        sfSprite_setPosition(win->scene->object[i].sprite,
        (sfVector2f) {x, 350});
    }
}

void init_map(window_t *win)
{
    win->scene->object[0].texture = sfTexture_createFromFile
        ("assets/back/map1.png", NULL);
    win->scene->object[0].sprite = sfSprite_create();
    sfSprite_setTexture(win->scene->object[0].sprite,
        win->scene->object[0].texture, sfTrue);
    init_goblins(win);
}
