/*
** EPITECH PROJECT, 2020
** jewe
** File description:
** jewel
*/
#include "include/my.h"

int set_jewel(game_t *game)
{
    for (item_t *t = game->item; t->mark != 70; t = t->next)
        if (t->sprite && t->mark == game->nb && (t->type >= 36
            && t->type <= 40) && game->item->jewel == 0) {
            sfSprite_setPosition(t->sprite, (sfVector2f) {370, 806});
            game->item->jewel = t->type;
            t->get = 1;
            change_player_stats(t, game);
            return (1);
        }
    return (0);
}

int add_jewel(game_t *game)
{
    int tmp;

    if (game->pos_clic.x < 450 && game->pos_clic.x > 350
        && game->pos_clic.y < 880 && game->pos_clic.y > 780) {
        if (game->item->jewel != 0
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            for (item_t *t = game->item; t->mark != 70; t = t->next)
                if (t->sprite && t->mark == (game->item->jewel + 29)
                    && (t->type >= 36 && t->type <= 40)) {
                    sfSprite_setPosition(t->sprite, t->pos);
                    game->item->jewel = 0;
                    t->get = 1;
                    change_player_stats(t, game);
                    return (1);
                }
        }
        tmp = set_jewel(game);
        if (tmp == 1)
            return (1);
    }
    return (0);
}
