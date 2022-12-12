/*
** EPITECH PROJECT, 2020
** inv event
** File description:
** inv event
*/
#include "include/my.h"

int check_item_pos(game_t *game)
{
    if (add_boots(game) == 1 || add_helmet(game) == 1 || add_amulet(game) == 1
        || add_ring(game) == 1 || add_sword(game) == 1 || add_jewel(game) == 1
        || add_chest(game) == 1)
        return (1);
    else {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
            && game->item->mv_item == 1) {
            for (item_t *t = game->item; t->mark != 70; t = t->next)
                if (t->sprite && t->mark == game->nb) {
                    sfSprite_setPosition(t->sprite, t->pos);
                    return (1);
                }
        }
    }
    return (0);
}

void check_item_move(game_t *game)
{
    if (game->item->mv_item == 1) {
        for (item_t *t = game->item; t->mark != 70; t = t->next)
            if (t->sprite && t->mark == game->nb)
                sfSprite_setPosition(t->sprite, game->pos_cursor);
    }
    if ((check_item_pos(game) == 1) && game->item->mv_item == 1) {
        game->item->mv_item = 0;
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    }
}

void check_item_info(game_t *game)
{
    for (item_t *t = game->item; t->mark != 70; t = t->next) {
        if (t->sprite && t->mark >= 27) {
            if (game->pos_mouse.x >= t->pos_min.x
                && game->pos_mouse.x <= t->pos_max.x
                && game->pos_mouse.y >= t->pos_min.y
                && game->pos_mouse.y <= t->pos_max.y)
                t->on = 1;
            else
                t->on = 0;
        }
    }
}

void check_inv_event(game_t *game)
{
    game->pos_cursor.x = game->pos_mouse.x;
    game->pos_cursor.y = game->pos_mouse.y;
    for (item_t *t = game->item; t->mark != 70; t = t->next) {
        if (t->sprite && t->mark >= 27) {
            if (game->pos_clic.x >= t->pos_min.x
                && game->pos_clic.x <= t->pos_max.x
                && game->pos_clic.y >= t->pos_min.y
                && game->pos_clic.y <= t->pos_max.y
                && game->item->mv_item == 0 && t->get == 1) {
                sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
                game->item->mv_item = 1;
                game->nb = t->mark;
            }
        }
    }
    check_item_info(game);
    check_item_move(game);
    if (game->pos_clic.x >= 1260 && game->pos_clic.x <= 1460
        && game->pos_clic.y >= 815 && game->pos_clic.y <= 876)
        game->inventory = 0;
}
