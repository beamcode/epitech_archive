/*
** EPITECH PROJECT, 2020
** c
** File description:
** c
*/

#include "include/my.h"

g_t *fill_my_game_two(void)
{
    g_t *game = malloc(sizeof(g_t));

    if (game != NULL) {
        game->enemy = fill_my_enemy();
        game->hero = fill_my_hero();
        game->but = fill_my_but();
        game->command = fill_my_command();
        game->text_c = NULL;
        game->pv_bar = setup_fight(game);
        game->battle = fill_my_battle();
        game->sizex = 0;
        game->sizey = 0;
    }
    return (game);
}
