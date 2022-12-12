/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_pause_button.c
*/

#include "include/my.h"

void quit_function(window_t *win)
{
    sfRectangleShape_setFillColor(win->scene->button[0].rect, sfMagenta);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        destroy_scene(win->scene);
        create_menu(win);
    }
}

void replay_function(window_t *win)
{
    sfRectangleShape_setFillColor(win->scene->button[1].rect, sfCyan);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        create_game(win);
        win->save = NULL;
    }
}

void continue_function(window_t *win)
{
    sfRectangleShape_setFillColor(win->scene->button[2].rect, sfGreen);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        win->scene = win->save;
        win->save = NULL;
    }
}

void initialize_two(button_t *b)
{
    b[2].rect = sfRectangleShape_create();
    b[2].play = sfTexture_createFromFile("assets/buttons/continue.png", NULL);
    sfRectangleShape_setPosition(b[2].rect, (sfVector2f) {810, 480});
    b[2].rect_pos = sfRectangleShape_getPosition(b[2].rect);
    sfRectangleShape_setSize(b[2].rect, (sfVector2f) {225, 225});
    b[2].size  = sfRectangleShape_getSize(b[2].rect);
    sfRectangleShape_setTexture(b[2].rect, b[2].play, sfTrue);
    b[2].callback = &continue_function;
}

void init_pause_button(button_t *b)
{
    b[0].rect = sfRectangleShape_create();
    b[0].play = sfTexture_createFromFile("assets/buttons/quit.png", NULL);
    sfRectangleShape_setPosition(b[0].rect, (sfVector2f) {515, 480});
    b[0].rect_pos = sfRectangleShape_getPosition(b[0].rect);
    sfRectangleShape_setSize(b[0].rect, (sfVector2f) {225, 225});
    b[0].size  = sfRectangleShape_getSize(b[0].rect);
    sfRectangleShape_setTexture(b[0].rect, b[0].play, sfTrue);
    b[0].callback = &quit_function;
    b[1].rect = sfRectangleShape_create();
    b[1].play = sfTexture_createFromFile("assets/buttons/replay.png", NULL);
    sfRectangleShape_setPosition(b[1].rect, (sfVector2f) {215, 480});
    b[1].rect_pos = sfRectangleShape_getPosition(b[1].rect);
    sfRectangleShape_setSize(b[1].rect, (sfVector2f) {225, 225});
    b[1].size  = sfRectangleShape_getSize(b[1].rect);
    sfRectangleShape_setTexture(b[1].rect, b[1].play, sfTrue);
    b[1].callback = &replay_function;
    initialize_two(b);
}
