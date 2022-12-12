/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** init_game_button.c
*/

#include "include/my.h"

void pause_function(window_t *win)
{
    sfRectangleShape_setFillColor(win->scene->button[0].rect, sfGreen);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        win->save = win->scene;
        create_pause(win);
    }
}

void preview_function(window_t *win)
{
    int nb = win->scene->nb;

    sfRectangleShape_setFillColor(win->scene->button[nb].rect, sfWhite);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        check_towers(win, nb);
    }
}

void init_preview(button_t *but)
{
    for (int i = 1; i < 8; i++) {
        but[i].rect = sfRectangleShape_create();
        but[i].play = sfTexture_createFromFile
            ("assets/buttons/preview.png", NULL);
    }
    sfRectangleShape_setPosition(but[1].rect, (sfVector2f) {275, 215});
    sfRectangleShape_setPosition(but[2].rect, (sfVector2f) {275, 320});
    sfRectangleShape_setPosition(but[3].rect, (sfVector2f) {550, 615});
    sfRectangleShape_setPosition(but[4].rect, (sfVector2f) {560, 375});
    sfRectangleShape_setPosition(but[5].rect, (sfVector2f) {500, 85});
    sfRectangleShape_setPosition(but[6].rect, (sfVector2f) {820, 165});
    sfRectangleShape_setPosition(but[7].rect, (sfVector2f) {850, 410});
    for (int i = 1; i < 8; i++) {
        but[i].rect_pos = sfRectangleShape_getPosition(but[i].rect);
        sfRectangleShape_setSize(but[i].rect, (sfVector2f) {100, 100});
        but[i].size  = sfRectangleShape_getSize(but[i].rect);
        sfRectangleShape_setTexture(but[i].rect, but[i].play, sfTrue);
        sfRectangleShape_setFillColor(but[i].rect, sfTransparent);
        but[i].callback = &preview_function;
    }
}

void init_towers(button_t *but)
{
    for (int i = 29; i < 50; i++) {
        but[i].rect = sfRectangleShape_create();
        but[i].play = sfTexture_createFromFile
            ("assets/buttons/tower2.png", NULL);
        sfRectangleShape_setPosition(but[i].rect, (sfVector2f) {1000, 16});
        but[i].rect_pos = sfRectangleShape_getPosition(but[i].rect);
        sfRectangleShape_setSize(but[i].rect, (sfVector2f) {80, 80});
        but[i].size  = sfRectangleShape_getSize(but[i].rect);
        sfRectangleShape_setTexture(but[i].rect, but[i].play, sfTrue);
    }
    for (int i = 50; i < 71; i++) {
        but[i].rect = sfRectangleShape_create();
        but[i].play = sfTexture_createFromFile
            ("assets/buttons/tower3.png", NULL);
        sfRectangleShape_setPosition(but[i].rect, (sfVector2f) {1100, 16});
        but[i].rect_pos = sfRectangleShape_getPosition(but[i].rect);
        sfRectangleShape_setSize(but[i].rect, (sfVector2f) {80, 80});
        but[i].size  = sfRectangleShape_getSize(but[i].rect);
        sfRectangleShape_setTexture(but[i].rect, but[i].play, sfTrue);
    }
}

void init_game_button(button_t *but)
{
    but[0].rect = sfRectangleShape_create();
    but[0].play = sfTexture_createFromFile("assets/buttons/pause.png", NULL);
    sfRectangleShape_setPosition(but[0].rect, (sfVector2f) {1190, 16});
    but[0].rect_pos = sfRectangleShape_getPosition(but[0].rect);
    sfRectangleShape_setSize(but[0].rect, (sfVector2f) {80, 80});
    but[0].size  = sfRectangleShape_getSize(but[0].rect);
    sfRectangleShape_setTexture(but[0].rect, but[0].play, sfTrue);
    but[0].callback = &pause_function;
    init_preview(but);
    for (int i = 8; i < 29; i++) {
        but[i].rect = sfRectangleShape_create();
        but[i].play = sfTexture_createFromFile
            ("assets/buttons/tower1.png", NULL);
        sfRectangleShape_setPosition(but[i].rect, (sfVector2f) {900, 16});
        but[i].rect_pos = sfRectangleShape_getPosition(but[i].rect);
        sfRectangleShape_setSize(but[i].rect, (sfVector2f) {80, 80});
        but[i].size  = sfRectangleShape_getSize(but[i].rect);
        sfRectangleShape_setTexture(but[i].rect, but[i].play, sfTrue);
    }
    init_towers(but);
}
