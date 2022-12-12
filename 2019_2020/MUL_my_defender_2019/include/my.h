/*
** EPITECH PROJECT, 2020
** my_defender
** File description:
** my.h
*/

#ifndef MY_H
#define MY_H

#include <stdio.h>
#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Window/Keyboard.h>

typedef struct s_window window_t;
typedef struct scene_s scene_t;

typedef enum scene_type_e {
    MENU,
    PAUSE,
    GAME
} scene_type_t;

typedef struct  button_s {
    sfTexture *play;
    sfRectangleShape *rect;
    sfVector2f rect_pos;
    sfVector2f size;
    void (*callback) (window_t *);
} button_t;

typedef struct s_game {
    sfTexture *texture;
    sfSprite *sprite;
    sfIntRect rect;
    sfClock *clock;
    sfTime time;
} game_t;

struct scene_s {
    button_t *button;
    game_t *object;
    int nb_button;
    int nb_object;
    int nb;
    scene_type_t type;
};

struct s_window {
    sfRenderWindow *window;
    sfEvent event;
    sfVector2i click_pos;
    scene_t *scene;
    scene_t *save;
    sfClock *game_clock;
    sfTime game_time;
};

void create_menu(window_t *win);
void init_map(window_t *win);
void init_game_button(button_t *but);
void start_game(window_t *win);

void create_game(window_t *win);

void create_pause(window_t *win);
void init_pause_button(button_t *b);

void button(window_t *win);

int check_position(button_t button, sfVector2i pos);
void check_towers(window_t *win, int nb);
void display_game(window_t *win);
void destroy_scene(scene_t *scene);
void destroy_game(window_t *win);

#endif /* MY_H */
