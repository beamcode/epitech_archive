/*
** EPITECH PROJECT, 2020
** window
** File description:
** ok
*/
#include "include/my.h"

int check_death(g_t *game)
{
    int res = 0;
    int count = 0;

    for (enemy_t *t = game->enemy; t != NULL; t = t->next) {
        if (t->sprite && t->hp <= -10)
            res++;
        if (t->sprite)
            count++;
    }
    if (count == res)
        return (1);
    else
        return (0);
}

int my_diff_events(g_t *g)
{
    g->command->position_clic =
        sfMouse_getPositionRenderWindow(g->window);
    g->command->pos_mouse = sfMouse_getPositionRenderWindow(g->window);
    if (search_event_fight(g, g->command) == 88)
        return (88);
    if (get_my_attack(g, g->command) == 1)
        counter_attack(g);
    return (0);
}

int open_sec_window(g_t *g)
{
    sfVideoMode mode = {1920, 1080, 32};

    if (my_loading_screen(g, mode) == 84)
        return (84);
    g->back = init_back();
    g->battle->clock = sfClock_create();
    while (sfRenderWindow_isOpen(g->window)) {
        while (sfRenderWindow_pollEvent(g->window, &g->event)) {
            if (my_diff_events(g) == 88)
                return (88);
        }
        sfRenderWindow_clear(g->window, sfBlack);
        draw_background(g, g->back);
        if (check_death(g) == 1)
            return (1);
        draw_my_game(g);
        sfRenderWindow_display(g->window);
    }
    return (0);
}
