/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** create_scene.c
*/

#include "include/my.h"

void exit_function(window_t *win)
{
    sfRectangleShape_setFillColor(win->scene->button[0].rect, sfMagenta);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        sfRenderWindow_close(win->window);
}

void play_function(window_t *win)
{
    sfRectangleShape_setFillColor(win->scene->button[1].rect, sfCyan);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        destroy_scene(win->scene);
        create_game(win);
    }
}

void init_menu_button(button_t *button)
{
    button[0].rect = sfRectangleShape_create();
    button[0].play = sfTexture_createFromFile("assets/buttons/exit.png", NULL);
    sfRectangleShape_setPosition(button[0].rect, (sfVector2f) {50, 540});
    button[0].rect_pos = sfRectangleShape_getPosition(button[0].rect);
    sfRectangleShape_setSize(button[0].rect, (sfVector2f) {300, 100});
    button[0].size  = sfRectangleShape_getSize(button[0].rect);
    sfRectangleShape_setTexture(button[0].rect, button[0].play, sfTrue);
    button[0].callback = &exit_function;

    button[1].rect = sfRectangleShape_create();
    button[1].play = sfTexture_createFromFile("assets/buttons/play1.png", NULL);
    sfRectangleShape_setPosition(button[1].rect, (sfVector2f) {910, 540});
    button[1].rect_pos = sfRectangleShape_getPosition(button[1].rect);
    sfRectangleShape_setSize(button[1].rect, (sfVector2f) {300, 100});
    button[1].size  = sfRectangleShape_getSize(button[1].rect);
    sfRectangleShape_setTexture(button[1].rect, button[1].play, sfTrue);
    button[1].callback = &play_function;
}

void create_menu(window_t *win)
{
    win->scene = malloc(sizeof(scene_t));
    win->scene->object = malloc(sizeof(game_t));
    win->scene->button = malloc(sizeof(button_t) * 2);
    win->scene->nb_object = 1;
    win->scene->nb_button = 2;

    win->scene->object[0].texture = sfTexture_createFromFile
        ("assets/back/scene1.png", NULL);
    win->scene->object[0].sprite = sfSprite_create();
    sfSprite_setTexture(win->scene->object[0].sprite,
        win->scene->object[0].texture, sfTrue);
    init_menu_button(win->scene->button);
    win->scene->type = MENU;
}
