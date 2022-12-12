/*
** EPITECH PROJECT, 2019
** menu_window.c
** File description:
** yes
*/

#include "../include/my.h"

void animate_menu(st_s *st)
{
    st->time_menu = sfClock_getElapsedTime(st->menu_clock);

    if (st->time_menu.microseconds / 1000000.0 > 1.0 / 11.0) {
        if (st->menu_bg_rect.left <= 3480) {
            st->menu_bg_rect.left += 870;
            if (st->menu_bg_rect.left >= 3480) {
                st->menu_bg_rect.left = 0;
                st->menu_bg_rect.top += 388;
            }
            if (st->menu_bg_rect.top >= 5432 && st->menu_bg_rect.left >= 877) {
                st->menu_bg_rect.left = 0;
                st->menu_bg_rect.top = 0;
            }
            sfClock_restart(st->menu_clock);
        }
    }
    sfSprite_setTextureRect(st->menu_bg, st->menu_bg_rect);
}

void draw_menu(st_s *st)
{
    sfRenderWindow_drawSprite(st->window, st->menu_bg, NULL);
    sfRenderWindow_drawSprite(st->window, st->menu_menu_guy, NULL);
    sfSprite_setScale(st->menu_bg, pos(2.207, 2.79));

    sfRenderWindow_drawSprite(st->window, st->menu_menu_guy, NULL);
    sfSprite_setPosition(st->menu_menu_guy, pos(910.0, 450.0));

    sfRenderWindow_drawSprite(st->window, st->menu_logo, NULL);
    sfSprite_setPosition(st->menu_logo, pos(410.0, 80.0));
    sfSprite_setScale(st->menu_logo, pos(1.2, 1.2));

    sfRenderWindow_drawSprite(st->window, st->menu_start, NULL);
    sfSprite_setPosition(st->menu_start, pos(480.0, 680.0));

    sfRenderWindow_drawSprite(st->window, st->menu_options, NULL);
    sfSprite_setPosition(st->menu_options, pos(1070.0, 680.0));

    sfRenderWindow_drawSprite(st->window, st->menu_quit, NULL);
    sfSprite_setPosition(st->menu_quit, pos(820.0, 850.0));
}

void display_menu(st_s *st)
{
    animate_menu(st);
    draw_menu(st);
}
