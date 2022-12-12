/*
** EPITECH PROJECT, 2019
** events.c
** File description:
** managing events
*/

#include "include/my.h"

void check_events_of_actions(display_s *toto, sfEvent event, sfRenderWindow *window, files_s *files)
{
    sfVector2i cursor = sfMouse_getPositionRenderWindow(window);

    if (toto->gameover > 1 && event.type == sfEvtMouseButtonPressed && ((cursor.x >= 450 && cursor.x <= 1437) && (cursor.y >= 680 && cursor.y <= 785)))
        initialize(toto, files);
    if (toto->gameover > 1)
        return;
    if (event.type != sfEvtMouseButtonPressed && event.mouseButton.button != sfMouseLeft)
        return;
    if (event.type == sfEvtMouseButtonPressed && ((cursor.x >= toto->fish_lenght && cursor.x <= toto->fish_lenght + 160) && (cursor.y >= toto->fish_height && cursor.y <= toto->fish_height + 160))) {
        sfMusic_stop(toto->music2);
        toto->fish_lenght = -170;
        toto->fish_height = rand() % 1000;
        toto->fish_speed++;
        toto->score_count++;
        sfMusic_play(toto->music2);
        
        sfText_setString(toto->score_text, my_itoa(toto->score_count));
    }
    if (event.type == sfEvtMouseButtonPressed && ((cursor.x < toto->fish_lenght || cursor.x > toto->fish_lenght + 160) && (cursor.y < toto->fish_height && cursor.y > toto->fish_height + 160)))
        toto->miss++;
}

void check_events(sfRenderWindow *window, sfEvent event, display_s *toto, files_s *files)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    check_events_of_actions(toto, event, window, files);
}