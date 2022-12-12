/*
** EPITECH PROJECT, 2020
** load quest
** File description:
** load quest
*/
#include "include/my.h"

void display_mob_pnj(game_t *game)
{
    for (mob_t *t = game->mob; t->mark != 20; t = t->next)
        if (t->sprite && t->mark > 0 && t->map == game->current_map
            && t->on == 1)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    for (pnj_t *t = game->pnj; t->mark != 10; t = t->next)
        if (t->sprite && t->mark > 0 && t->map == game->current_map)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
}

void load_quest(game_t *game)
{
    static int tmp = 0;

    for (pnj_t *t = game->pnj; t->mark != 10; t = t->next) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue
            && game->inventory == 0 && game->menupause == 0
            && t->map == game->current_map
            && game->quest->quest >= game->current_map) {
            if (game->pos_clic.x <= t->pos_max.x
                && game->pos_clic.x >= t->pos_min.x
                && game->pos_clic.y <= t->pos_max.y
                && game->pos_clic.y >= t->pos_min.y) {
                check_quest_map(game);
                tmp = check_quest_number(game, tmp);
            }
            if (game->pos_clic.x <= 287 && game->pos_clic.x >= 232
                && game->pos_clic.y <= 532 && game->pos_clic.y >= 473)
                tmp = 0;
        }
    }
    display_quest(game, tmp);
}
