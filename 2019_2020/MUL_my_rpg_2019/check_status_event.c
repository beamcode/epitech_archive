/*
** EPITECH PROJECT, 2020
** status
** File description:
** status
*/
#include "include/my.h"

void change_life(game_t *game, item_t item)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        && (game->pos_clic.x < 365 && game->pos_clic.x > 33
        && game->pos_clic.y < 470 && game->pos_clic.y > 440)) {
        game->s1 = 1;
        if (game->player->points > 0) {
            game->player->points -= 1;
            game->player->s_life += 5;
            change_player_stats(&item, game);
        }
    }
    else
        game->s1 = 0;
}

void change_xp(game_t *game)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        && (game->pos_clic.x < 365 && game->pos_clic.x > 33
        && game->pos_clic.y < 544 && game->pos_clic.y > 513)) {
        game->s2 = 1;
        if (game->player->points > 0) {
            game->player->points -= 1;
            game->player->xp += 100;
            check_bar_sprite(game);
        }
    }
    else
        game->s2 = 0;
}

void change_res(game_t *game, item_t item)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        && (game->pos_clic.x < 365 && game->pos_clic.x > 33
        && game->pos_clic.y < 621 && game->pos_clic.y > 590)) {
        game->s3 = 1;
        if (game->player->points > 0) {
            game->player->points -= 1;
            game->player->s_res += 5;
            change_player_stats(&item, game);
        }
    }
    else
        game->s3 = 0;
}

void change_dam(game_t *game, item_t item)
{
    if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
        && (game->pos_clic.x < 365 && game->pos_clic.x > 33
        && game->pos_clic.y < 689 && game->pos_clic.y > 666)) {
        game->s4 = 1;
        if (game->player->points > 0) {
            game->player->points -= 1;
            game->player->s_dam += 5;
            change_player_stats(&item, game);
        }
    }
    else
        game->s4 = 0;
}

void check_status_event(game_t *game)
{
    item_t item;

    if (game->pos_clic.x < 360 && game->pos_clic.x > 260
        && game->pos_clic.y < 785 && game->pos_clic.y > 735)
        game->status = 0;
    change_life(game, item);
    change_xp(game);
    change_res(game, item);
    change_dam(game, item);
}
