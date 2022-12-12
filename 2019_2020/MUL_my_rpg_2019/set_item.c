/*
** EPITECH PROJECT, 2020
** set item
** File description:
** set item
*/
#include "include/my.h"

int set_ring(game_t *game)
{
    for (item_t *t = game->item; t->mark != 70; t = t->next)
        if (t->sprite && t->mark == game->nb
            && (t->type >= 6 && t->type <= 10) && game->item->ring == 0) {
            sfSprite_setPosition(t->sprite, (sfVector2f) {234, 531});
            game->item->ring = t->type;
            t->get = 1;
            change_player_stats(t, game);
            return (1);
        }
    return (0);
}

int set_boots(game_t *game)
{
    for (item_t *t = game->item; t->mark != 70; t = t->next)
        if (t->sprite && t->mark == game->nb && (t->type >= 21
            && t->type <= 25) && game->item->boots == 0) {
            sfSprite_setPosition(t->sprite, (sfVector2f) {373, 670});
            game->item->boots = t->type;
            t->get = 1;
            change_player_stats(t, game);
            return (1);
        }
    return (0);
}

int set_chest(game_t *game)
{
    for (item_t *t = game->item; t->mark != 70; t = t->next)
        if (t->sprite && t->mark == game->nb && (t->type >= 16
            && t->type <= 20) && game->item->chest == 0) {
            sfSprite_setPosition(t->sprite, (sfVector2f) {373, 530});
            game->item->chest = t->type;
            t->get = 1;
            change_player_stats(t, game);
            return (1);
        }
    return (0);
}

int set_amulet(game_t *game)
{
    for (item_t *t = game->item; t->mark != 70; t = t->next)
        if (t->sprite && t->mark == game->nb && (t->type >= 1
            && t->type <= 5) && game->item->amulet == 0) {
            sfSprite_setPosition(t->sprite, (sfVector2f) {373, 392});
            game->item->amulet = t->type;
            t->get = 1;
            change_player_stats(t, game);
            return (1);
        }
    return (0);
}

int set_helmet(game_t *game)
{
    for (item_t *t = game->item; t->mark != 70; t = t->next)
        if (t->sprite && t->mark == game->nb && (t->type >= 11
            && t->type <= 15) && game->item->helmet == 0) {
            sfSprite_setPosition(t->sprite, (sfVector2f) {373, 262});
            game->item->helmet = t->type;
            t->get = 1;
            change_player_stats(t, game);
            return (1);
        }
    return (0);
}
