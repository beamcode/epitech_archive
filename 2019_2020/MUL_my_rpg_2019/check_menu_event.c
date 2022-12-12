/*
** EPITECH PROJECT, 2020
** menu
** File description:
** menu
*/
#include "include/my.h"

void exit_button(game_t *game)
{
    if (game->pos_mouse.x >= 70 && game->pos_mouse.x <= 570
        && game->pos_mouse.y >= 790 && game->pos_mouse.y <= 880
        && game->settings == 0 && game->cinematic == 0) {
        game->menu4 = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            sfRenderWindow_close(game->window);
            save_game(game);
        }
    }
    else
        game->menu4 = 0;
}

void create_new_game(game_t *game)
{
    int tmp = 1;

    if (game->pos_mouse.x >= 70 && game->pos_mouse.x <= 570
        && game->pos_mouse.y >= 480 && game->pos_mouse.y <= 565
        && game->settings == 0 && game->cinematic == 0) {
        game->menu2 = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->menu = 0;
            game->new_game = 1;
            sfMusic_play(game->music->radio);
            sfMusic_play(game->music->quest);
            sfMusic_setLoop(game->music->quest, sfTrue);
            sfMusic_stop(game->music->menumusic);
            sfMusic_stop(game->music->cine);
            load_file(game, tmp);
            save_game(game);

        }
    }
    else
        game->menu2 = 0;
}

void open_settings(game_t *game)
{
    if (game->pos_mouse.x >= 70 && game->pos_mouse.x <= 570
        && game->pos_mouse.y >= 630 && game->pos_mouse.y <= 720
        && game->settings == 0 && game->cinematic == 0) {
        game->menu3 = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            game->settings = 1;
    }
    else
        game->menu3 = 0;
    exit_button(game);
}

void check_menu_event(game_t *game)
{
    int tmp = 0;

    if (game->pos_mouse.x >= 70 && game->pos_mouse.x <= 570
        && game->pos_mouse.y >= 330 && game->pos_mouse.y <= 415
        && game->settings == 0 && game->cinematic == 0) {
        game->menu1 = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->menu = 0;
            sfMusic_play(game->music->gamemusic);
            sfMusic_setLoop(game->music->gamemusic, sfTrue);
            sfMusic_stop(game->music->menumusic);
            sfMusic_stop(game->music->cine);
            load_file(game, tmp);
        }
    }
    else
        game->menu1 = 0;
    create_new_game(game);
    open_settings(game);
    if (game->settings == 1)
        check_settings_event(game);
}
