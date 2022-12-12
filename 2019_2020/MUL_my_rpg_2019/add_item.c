/*
** EPITECH PROJECT, 2020
** add item
** File description:
** add item
*/
#include "include/my.h"

int add_ring(game_t *game)
{
    int tmp;

    if (game->pos_clic.x < 310 && game->pos_clic.x > 210
        && game->pos_clic.y < 615 && game->pos_clic.y > 510) {
        if (game->item->ring != 0
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            for (item_t *t = game->item; t->mark != 70; t = t->next)
                if (t->sprite && t->mark == (game->item->ring + 29)
                    && (t->type >= 6 && t->type <= 10)) {
                    sfSprite_setPosition(t->sprite, t->pos);
                    game->item->ring = 0;
                    t->get = 1;
                    change_player_stats(t, game);
                    return (1);
                }
        }
        tmp = set_ring(game);
        if (tmp == 1)
            return (1);
    }
    return (0);
}

int add_boots(game_t *game)
{
    int tmp;

    if (game->pos_clic.x < 450 && game->pos_clic.x > 350
        && game->pos_clic.y < 750 && game->pos_clic.y > 650) {
        if (game->item->boots != 0
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            for (item_t *t = game->item; t->mark != 70; t = t->next)
                if (t->sprite && t->mark == (game->item->boots + 29)
                    && (t->type >= 21 && t->type <= 25)) {
                    sfSprite_setPosition(t->sprite, t->pos);
                    game->item->boots = 0;
                    t->get = 1;
                    change_player_stats(t, game);
                    return (1);
                }
        }
        tmp = set_boots(game);
        if (tmp == 1)
            return (1);
    }
    return (0);
}

int add_chest(game_t *game)
{
    int tmp;

    if (game->pos_clic.x < 450 && game->pos_clic.x > 350
        && game->pos_clic.y < 615 && game->pos_clic.y > 510) {
        if (game->item->chest != 0
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            for (item_t *t = game->item; t->mark != 70; t = t->next)
                if (t->sprite && t->mark == (game->item->chest + 29)
                    && (t->type >= 16 && t->type <= 20)) {
                    sfSprite_setPosition(t->sprite, t->pos);
                    game->item->chest = 0;
                    t->get = 1;
                    change_player_stats(t, game);
                    return (1);
                }
        }
        tmp = set_chest(game);
        if (tmp == 1)
            return (1);
    }
    return (0);
}

int add_amulet(game_t *game)
{
    int tmp;

    if (game->pos_clic.x < 450 && game->pos_clic.x > 350
        && game->pos_clic.y < 460 && game->pos_clic.y > 350) {
        if (game->item->amulet != 0
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            for (item_t *t = game->item; t->mark != 70; t = t->next)
                if (t->sprite && t->mark == (game->item->amulet + 29)
                    && (t->type >= 1 && t->type <= 5)) {
                    sfSprite_setPosition(t->sprite, t->pos);
                    game->item->amulet = 0;
                    t->get = 1;
                    change_player_stats(t, game);
                    return (1);
                }
        }
        tmp = set_amulet(game);
        if (tmp == 1)
            return (1);
    }
    return (0);
}

int add_helmet(game_t *game)
{
    int tmp;

    if (game->pos_clic.x < 450 && game->pos_clic.x > 350
        && game->pos_clic.y < 340 && game->pos_clic.y > 240) {
        if (game->item->helmet != 0
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            for (item_t *t = game->item; t->mark != 70; t = t->next)
                if (t->sprite && t->mark == (game->item->helmet + 29)
                    && (t->type >= 11 && t->type <= 15)) {
                    sfSprite_setPosition(t->sprite, t->pos);
                    game->item->helmet = 0;
                    t->get = 1;
                    change_player_stats(t, game);
                    return (1);
                }
        }
        tmp = set_helmet(game);
        if (tmp == 1)
            return (1);
    }
    return (0);
}
