/*
** EPITECH PROJECT, 2020
** settings
** File description:
** settings event
*/
#include "include/my.h"

void change_menu_volume(game_t *game)
{
    if (game->pos_clic.x < 456 && game->pos_clic.x > 422
        && game->pos_clic.y < 578 && game->pos_clic.y > 546
        && game->music->game_v <= 95)
        game->music->game_v += 5;
    if (game->pos_clic.x < 305 && game->pos_clic.x > 273
        && game->pos_clic.y < 691 && game->pos_clic.y > 659
        && game->music->sound_v >= 5)
        game->music->sound_v -= 5;
    if (game->pos_clic.x < 456 && game->pos_clic.x > 422
        && game->pos_clic.y < 691 && game->pos_clic.y > 659
        && game->music->sound_v <= 95)
        game->music->sound_v += 5;
}

void change_game_volume(game_t *game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
        if (game->pos_clic.x < 305 && game->pos_clic.x > 273
            && game->pos_clic.y < 465 && game->pos_clic.y > 433
            && game->music->menu_v >= 5)
            game->music->menu_v -= 5;
        if (game->pos_clic.x < 456 && game->pos_clic.x > 422
            && game->pos_clic.y < 465 && game->pos_clic.y > 433
            && game->music->menu_v <= 95)
            game->music->menu_v += 5;
        if (game->pos_clic.x < 305 && game->pos_clic.x > 273
            && game->pos_clic.y < 578 && game->pos_clic.y > 546
            && game->music->game_v >= 5)
            game->music->game_v -= 5;
        change_menu_volume(game);
    }
}

void change_music_volume(game_t *game)
{
    sfMusic_setVolume(game->music->menumusic, game->music->menu_v);
    sfMusic_setVolume(game->music->gamemusic, game->music->game_v);
    sfMusic_setVolume(game->music->quest, game->music->game_v);
    sfMusic_setVolume(game->music->grow, game->music->sound_v);
    sfMusic_setVolume(game->music->menumusic, game->music->menu_v);
    sfMusic_setVolume(game->music->gamemusic, game->music->menu_v);
    sfMusic_setVolume(game->music->radio, game->music->sound_v);
    sfMusic_setVolume(game->music->radio2, game->music->sound_v);
    sfMusic_setVolume(game->music->radio3, game->music->sound_v);
    sfMusic_setVolume(game->music->quest, game->music->game_v);
    sfMusic_setVolume(game->music->grow, game->music->sound_v);
    sfMusic_setVolume(game->music->typing, game->music->sound_v);
    sfMusic_setVolume(game->music->cine, game->music->menu_v);
    sfMusic_setVolume(game->music->credits, game->music->game_v);
}

void check_settings_event(game_t *game)
{
    change_game_volume(game);
    change_music_volume(game);
    if (game->pos_mouse.x >= 373 && game->pos_mouse.x <= 636
        && game->pos_mouse.y >= 886 && game->pos_mouse.y <= 998) {
        game->apply = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            game->settings = 0;
    }
    else
        game->apply = 0;
}
