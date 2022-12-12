/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_game.c
*/

#include "include/my.h"

sfVector2f follow_path(sfSprite *sprite, double speed)
{
    sfVector2f goblin = sfSprite_getPosition(sprite);

    if (goblin.x < 135)
        return ((sfVector2f) {2 * speed, -0.25 * speed});
    if (goblin.x < 197)
        return ((sfVector2f) {0.6 * speed, -2 * speed});
    if (goblin.x < 380)
        return ((sfVector2f) {2 * speed, 0});
    if (goblin.x < 437)
        return ((sfVector2f) {0.3 * speed, 2 * speed});
    if (goblin.x < 695)
        return ((sfVector2f) {2 * speed, 0});
    if (goblin.x < 742)
        return ((sfVector2f) {0.45 * speed, -2 * speed});
    if (goblin.x < 1375)
        return ((sfVector2f) {2 * speed, 0});
    else
        sfSprite_setPosition(sprite, (sfVector2f) {-95, 350});
    return ((sfVector2f) {0, 0});
}

void draw_enemies(window_t *win, int i)
{
    win->scene->object[i].time = sfClock_getElapsedTime
        (win->scene->object[i].clock);
    if (win->scene->object[i].time.microseconds / 1000000.0 > 0.10) {
        if (win->scene->object[i].rect.left < 475)
            win->scene->object[i].rect.left += 95;
        else
            win->scene->object[i].rect.left = 0;
        sfClock_restart(win->scene->object[i].clock);
    }
    sfSprite_setTextureRect(win->scene->object[i].sprite,
                            win->scene->object[i].rect);
    sfRenderWindow_drawSprite(win->window, win->scene->object[i].sprite, NULL);
}

void start_game(window_t *win)
{
    for (int i = 1; i < 11; i++)
        sfSprite_move(win->scene->object[i].sprite,
        follow_path(win->scene->object[i].sprite, 0.3));
    sfRenderWindow_drawSprite(win->window, win->scene->object[0].sprite, NULL);
    for (int i = 1; i < 11; i++)
        draw_enemies(win, i);
    for (int i = 0; i < 71; i++) {
        sfRenderWindow_drawRectangleShape(win->window,
        win->scene->button[i].rect, NULL);
    }
}

void create_game(window_t *win)
{
    win->scene = malloc(sizeof(scene_t));
    win->scene->object = malloc(sizeof(game_t) * 11);
    win->scene->button = malloc(sizeof(button_t) * 71);
    win->scene->nb_object = 11;
    win->scene->nb_button = 71;
    win->scene->nb = 0;

    init_game_button(win->scene->button);
    init_map(win);
    win->scene->type = GAME;
}
