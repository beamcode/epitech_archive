/*
** EPITECH PROJECT, 2019
** clock_engin.c
** File description:
** main clock funtion
*/

#include "include/my.h"

void animate_fish(display_s *toto)
{
    if (toto->fish_rect.left <= 160)
            toto->fish_rect.left += 160;
        if (toto->fish_rect.left > 160)
            toto->fish_rect.left = 0;
    sfSprite_setTextureRect(toto->fish, toto->fish_rect);
}

void check_gameover(display_s *toto)
{
    if (toto->gameover == 1) {
        sfMusic_play(toto->music3);
        toto->gameover++;
    }
}

void launch(sfRenderWindow *window, sfEvent event, display_s *toto, files_s *files)
{
    sfClock *main_clock = sfClock_create();
    sfClock *anim_clock = sfClock_create();

    execute_all(window, toto, files);
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event))
            check_events(window, event, toto, files);
        check_gameover(toto);
        sfTime time1 = sfClock_getElapsedTime(main_clock);
        if (time1.microseconds / 1000000.0 > 1.0 / 60.0) {
            spawn_sprites(window, toto, files, event);
            sfRenderWindow_display(window);
            sfClock_restart(main_clock);
        }
        sfTime time2 = sfClock_getElapsedTime(anim_clock);
        if (time2.microseconds / 1000000.0 > 0.5) {
            animate_fish(toto);
            sfClock_restart(anim_clock);
        }
    }
}