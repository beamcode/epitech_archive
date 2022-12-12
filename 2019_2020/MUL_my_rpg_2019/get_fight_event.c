/*
** EPITECH PROJECT, 2020
** fight
** File description:
** fight
*/
#include "include/my.h"

void get_jewel_drop(game_t *game)
{
    int val2 = 0;

    val2 = rand() % 501;
    for (item_t *t = game->item; t->mark != 70; t = t->next)
        if (t->sprite && val2 == 217 && t->mark == 66)
            t->get = 1;
    for (item_t *t = game->item; t->mark != 70; t = t->next)
        if (t->sprite && val2 == 145 && t->mark == 67)
            t->get = 1;
    for (item_t *t = game->item; t->mark != 70; t = t->next)
        if (t->sprite && val2 == 378 && t->mark == 68)
            t->get = 1;
    for (item_t *t = game->item; t->mark != 70; t = t->next)
        if (t->sprite && val2 == 295 && t->mark == 69)
            t->get = 1;
}

void get_drop(game_t *game)
{
    static int first = 0;
    int val = 0;

    if (first == 0) {
        srand(time (NULL));
        first = 1;
    }
    val = rand() % 81;
    for (item_t *t = game->item; t->mark != 65; t = t->next)
        if (t->sprite && t->mark == val && val != 30 && val != 62)
            t->get = 1;
    get_jewel_drop(game);
}

void start_fight(game_t *game, mob_t *t)
{
    int tmp = 0;

    tmp = fight(t->mark);
    if (tmp != 88) {
        game->player->xp += 400;
        check_bar_sprite(game);
        get_drop(game);
        game->inventory = 1;
    }
}

void check_quest_fight(game_t *game, mob_t *t)
{
    if (t->mark == 3 || t->mark == 4 || t->mark == 11
        || t->mark == 12 || t->mark == 19) {
        if (t->mark == 3 || t->mark == 4)
            game->quest->q2++;
        if (t->mark == 11 || t->mark == 12)
            game->quest->q4++;
        if (t->mark == 19)
            game->quest->boss = 1;
        t->on = 0;
    }
}

void search_fight(game_t *game)
{
    for (mob_t *t = game->mob; t->mark != 20; t = t->next) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
            && game->inventory == 0 && game->menupause == 0
            && t->map == game->current_map && t->on == 1) {
            if (game->pos_clic.x <= t->pos_max.x
                && game->pos_clic.x >= t->pos_min.x
                && game->pos_clic.y <= t->pos_max.y
                && game->pos_clic.y >= t->pos_min.y) {
                check_quest_fight(game, t);
                start_fight(game, t);
            }
        }
    }
}
