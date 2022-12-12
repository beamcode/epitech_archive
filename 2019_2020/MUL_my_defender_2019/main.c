/*
** EPITECH PROJECT, 2020
** defender
** File description:
** main.c
*/

#include "include/my.h"

void init_window(window_t *win)
{
    sfVideoMode mode = {1280, 720, 32};

    win->window = sfRenderWindow_create(mode, "my_window", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(win->window, 60);
    win->scene = NULL;
    win->save = NULL;
    win->click_pos = (sfVector2i) {0, 0};
    sfMouse_setPosition(win->click_pos, (sfWindow*) win->window);
    win->game_clock = sfClock_create();
}

void game_events(window_t *win)
{
    while (sfRenderWindow_pollEvent(win->window, &win->event)) {
        if (win->event.type == sfEvtClosed)
            sfRenderWindow_close(win->window);
        if (sfKeyboard_isKeyPressed(sfKeyEscape))
            sfRenderWindow_close(win->window);
    }
}

int main(void)
{
    window_t win;

    init_window(&win);
    create_menu(&win);

    sfMusic *music = sfMusic_createFromFile("assets/track1.ogg");
    sfMusic_setLoop(music, sfTrue);
    sfMusic_play(music);
    while (sfRenderWindow_isOpen(win.window)) {
        game_events(&win);
        button(&win);
        display_game(&win);
    }
    destroy_game(&win);
    return (0);
}
