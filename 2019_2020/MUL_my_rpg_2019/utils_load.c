/*
** EPITECH PROJECT, 2020
** c
** File description:
** c
*/

#include "include/my.h"
#include <math.h>

int cloc = 0;

int my_minus_balance_x(t_framebuffer *f, t_circle *p, t_window *u, g_t *game)
{
    if (cloc == 1)
        return (1);
    for (; p->center.x > 8; p->center.x -= 15) {
        clear_framebuffer(f, u);
        draw_moving_balance(f, p->center, 20);
        sfTexture_updateFromPixels(u->texture, f->pixels, 1920, 1080, 0, 0);
        sfRenderWindow_drawSprite(u->window, u->sprite, NULL);
        sfRenderWindow_drawText(u->window, game->text_c, NULL);
        sfRenderWindow_display(u->window);
    }
    my_loop_balance_x(f, p, u, game);
    return (0);
}

int my_loop_balance_x(t_framebuffer *f, t_circle *p, t_window *u, g_t *game)
{
    if (check_clock(game) == 1 || cloc == 1)
        return (1);
    for (;p->center.x < 1880; p->center.x += 15) {
        clear_framebuffer(f, u);
        draw_moving_balance(f, p->center, 20);
        sfTexture_updateFromPixels(u->texture, f->pixels, 1920, 1080, 0, 0);
        sfRenderWindow_drawSprite(u->window, u->sprite, NULL);
        sfRenderWindow_drawText(u->window, game->text_c, NULL);
        sfRenderWindow_display(u->window);
    }
    my_minus_balance_x(f, p, u, game);
    return (0);
}

int check_clock(g_t *game)
{
    sfTime timer = sfClock_getElapsedTime(game->clock_c);
    float seconds = timer.microseconds / 1000000.0;

    if (seconds > 4) {
        cloc = 1;
        return (1);
    }
    return (0);
}

int my_loop_moving_balanc(t_framebuffer *f, t_window *u, t_circle *p, g_t *g)
{
    sfEvent event;

    u->clock = sfClock_create();
    g->clock_c = sfClock_create();
    while (sfRenderWindow_pollEvent(u->window, &event)) {
        if (event.type == sfEvtKeyPressed) {
            sfKeyEvent echap = event.key;
            if (echap.code == sfKeyEscape) {
                sfRenderWindow_clear(u->window, sfBlack);
                sfRenderWindow_close(u->window);
            }
        }
    }
    sfRenderWindow_clear(u->window, sfBlack);
    if (my_loop_balance_x(f, p, u, g) == 1) {
        return (1);
    }
    return (0);
}

int my_loading_screen(g_t *g, sfVideoMode mode)
{
    t_window *utils = malloc(sizeof(t_window));
    t_circle *pos = malloc(sizeof(pos));

    if (NULL == pos || NULL == utils)
        return (84);
    pos->center.x = 600;
    pos->center.y = 500;
    g->framebuffer = framebuffer_create(1920, 1080);
    utils->texture = sfTexture_create(1920, 1080);
    utils->sprite = sfSprite_create();
    sfSprite_setTexture(utils->sprite, utils->texture, sfTrue);
    g->window = sfRenderWindow_create(mode, "My Radar", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(g->window, 60);
    utils->window = g->window;
    while (sfRenderWindow_isOpen(g->window)) {
        if (my_loop_moving_balanc(g->framebuffer, utils, pos, g) == 1) {
            break;
        }
    }
    cloc = 0;
    return (0);
}
