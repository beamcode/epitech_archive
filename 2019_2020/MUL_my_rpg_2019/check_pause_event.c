/*
** EPITECH PROJECT, 2020
** pause
** File description:
** pause
*/
#include "include/my.h"

void check_pause_first(game_t *game)
{
    if (game->pos_mouse.x <= 720 && game->pos_mouse.x >= 610
        && game->pos_mouse.y <= 470 && game->pos_mouse.y >= 360) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            game->menupause = 0;
        game->p1_on = 1;
    }
    else
        game->p1_on = 0;
}

void check_pause_second(game_t *game)
{
    if (game->pos_mouse.x <= 910 && game->pos_mouse.x >= 790
        && game->pos_mouse.y <= 470 && game->pos_mouse.y >= 360) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->menupause = 0;
            sfMusic_stop(game->music->gamemusic);
            sfMusic_stop(game->music->radio);
            sfMusic_stop(game->music->quest);
            sfMusic_play(game->music->menumusic);
            sfMusic_setLoop(game->music->menumusic, sfTrue);
            save_game(game);
            game->menu = 1;
        }
        game->p2_on = 1;
    }
    else
        game->p2_on = 0;
}

void check_pause_button(game_t *game)
{
    if (game->pos_mouse.x <= 1100 && game->pos_mouse.x >= 990
        && game->pos_mouse.y <= 470 && game->pos_mouse.y >= 360) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            game->menupause = 0;
        game->p3_on = 1;
    }
    else
        game->p3_on = 0;
    if (game->pos_mouse.x <= 1295 && game->pos_mouse.x >= 1185
        && game->pos_mouse.y <= 470 && game->pos_mouse.y >= 360) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            sfRenderWindow_close(game->window);
            save_game(game);
        }
        game->p4_on = 1;
    }
    else
        game->p4_on = 0;
}

void check_pause_event(game_t *game)
{
    if (game->menupause == 1) {
        check_pause_first(game);
        check_pause_second(game);
        check_pause_button(game);
    }
}
