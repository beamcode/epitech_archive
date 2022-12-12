/*
** EPITECH PROJECT, 2020
** sword
** File description:
** swod
*/
#include "include/my.h"

int set_sword(game_t *game)
{
    for (item_t *t = game->item; t->mark != 70; t = t->next)
        if (t->sprite && t->mark == game->nb && (t->type >= 26
            && t->type <= 35) && game->item->sword == 0) {
            sfSprite_setPosition(t->sprite, (sfVector2f) {514, 533});
            game->item->sword = t->type;
            t->get = 1;
            change_player_stats(t, game);
            return (1);
        }
    return (0);
}

int add_sword(game_t *game)
{
    int tmp;

    if (game->pos_clic.x < 600 && game->pos_clic.x > 500
        && game->pos_clic.y < 615 && game->pos_clic.y > 510) {
        if (game->item->sword != 0
            && sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            for (item_t *t = game->item; t->mark != 70; t = t->next)
                if (t->sprite && t->mark == (game->item->sword + 29)
                    && (t->type >= 26 && t->type <= 35)) {
                    sfSprite_setPosition(t->sprite, t->pos);
                    game->item->sword = 0;
                    t->get = 1;
                    change_player_stats(t, game);
                    return (1);
                }
        }
        tmp = set_sword(game);
        if (tmp == 1)
            return (1);
    }
    return (0);
}
