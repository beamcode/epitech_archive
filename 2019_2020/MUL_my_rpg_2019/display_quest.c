/*
** EPITECH PROJECT, 2020
** display quest
** File description:
** display quest
*/
#include "include/my.h"

void display_quest_indicator(game_t *game)
{
    sfVector2f p;

    for (pnj_t *t = game->pnj; t->mark != 10; t = t->next) {
        for (button_t *a = game->button; a->mark != 132; a = a->next) {
            p.x = t->pos.x + 10;
            p.y = t->pos.y - 40;
            if (a->sprite && a->mark == 131 && game->current_map == t->map
                && t->map == game->quest->quest)
                sfSprite_setPosition(a->sprite, p);
        }
        for (button_t *e = game->button; e->mark != 132; e = e->next)
            if (e->sprite && e->mark == 131
                && game->current_map == game->quest->quest
                && game->current_map != 10)
                sfRenderWindow_drawSprite(game->window, e->sprite, NULL);
    }
}

void display_quest_cursor(game_t *game)
{
    for (button_t *t = game->button; t->mark != 127; t = t->next)
        if (t->sprite && t->mark == 126 && (game->cur == 1 || game->cur2 == 1))
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    if (game->cur == 1 || game->cur2 == 1)
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
}

void check_quest_map(game_t *game)
{
    if (game->current_map == game->quest->quest
        || game->current_map == game->quest->quest + 1) {
        if ((game->current_map == 2 && game->quest->q2 != 2)
            || (game->current_map == 4 && game->quest->q3 != 1)
            || (game->current_map == 6 && game->quest->q4 != 2)
            || (game->current_map == 8 && game->quest->q5 != 1))
            game->quest->quest = game->quest->quest;
        else {
            game->quest->quest = game->current_map + 1;
            game->player->xp += 500;
            check_bar_sprite(game);
        }
    }
}

int check_quest_number(game_t *game, int tmp)
{
    if (game->current_map != 9)
        tmp = game->current_map + 113;
    if (game->quest->q2 == 2 && game->current_map == 2)
        tmp += 8;
    if (game->quest->q3 == 1 && game->current_map == 4)
        tmp += 7;
    if (game->quest->q4 == 2 && game->current_map == 6)
        tmp += 6;
    if (game->quest->q4 == 2 && game->current_map == 6
        && game->quest->quest == 7) {
        for (item_t *t = game->item; t->mark != 62; t = t->next)
            if (t->sprite && t->mark == 61)
                t->get = 1;
        game->inventory = 1;
    }
    if (game->current_map == 9 && game->quest->q5 == 1)
        tmp = game->current_map + 113;
    return (tmp);
}

void display_quest(game_t *game, int tmp)
{
    for (button_t *t = game->button; t->mark != 128; t = t->next)
        if (t->sprite && (t->mark == tmp || t->mark == 127))
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
}
