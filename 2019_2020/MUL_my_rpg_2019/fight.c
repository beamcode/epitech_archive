/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** defender
*/

#include "include/my.h"

int boss_case(g_t *game, int mark)
{
    if (mark == 19) {
        game->sizex = 70;
        game->sizey = 120;
        game->nb_c = 1;
        get_fight_map("scripts/script13", game);
        return (3);
    }
    return (-1);
}

int fight(int mark)
{
    g_t *game;
    int tmp = 0;

    game = fill_my_game_two();
    firsts_case(game, mark);
    seconds_case(game, mark);
    third_case(game, mark);
    four_case(game, mark);
    five_case(game, mark);
    boss_case(game, mark);
    tmp = open_sec_window(game);
    sfRenderWindow_destroy(game->window);
    return (tmp);
}
