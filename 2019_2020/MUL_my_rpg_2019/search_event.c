/*
** EPITECH PROJECT, 2019
** search event
** File description:
** search event
*/
#include "include/my.h"

void check_keyboard_event(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue && game->menupause == 0)
        game->inventory = 1;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && game->menupause == 0)
        game->menupause = 1;
    if (sfKeyboard_isKeyPressed(sfKeyC) == sfTrue && game->status == 0)
        game->status = 1;
}

void check_game_event(game_t *game)
{
    search_quest_event(game);
    search_fight(game);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue && game->inventory == 0
        && game->menupause == 0)
        get_move_axes(game);
    check_keyboard_event(game);
    if (game->menupause == 1)
        check_pause_event(game);
    if (game->inventory == 1)
        check_inv_event(game);
    if (game->status == 1)
        check_status_event(game);
}

void check_cinematic_event(game_t *game)
{
    if (game->pos_mouse.x <= 1904 && game->pos_mouse.x >= 1720
        && game->pos_mouse.y <= 994 && game->pos_mouse.y >= 940) {
        game->pass = 1;
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->cinematic = 0;
            sfMusic_play(game->music->menumusic);
            sfMusic_setLoop(game->music->menumusic, sfTrue);
            sfMusic_stop(game->music->typing);
        }
    }
    else
        game->pass = 0;
}

void search_event(game_t *game)
{
    game->new_game = 0;
    game->pos_mouse = sfMouse_getPositionRenderWindow(game->window);
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
        game->pos_clic = sfMouse_getPositionRenderWindow(game->window);
    if (game->menu == 1)
        check_menu_event(game);
    if (game->menu == 1 && game->cinematic == 1)
        check_cinematic_event(game);
    if (game->menu == 0)
        check_game_event(game);
    if (game->event.type == sfEvtClosed) {
        save_game(game);
        sfRenderWindow_close(game->window);
    }
}
