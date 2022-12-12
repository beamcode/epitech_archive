/*
** EPITECH PROJECT, 2020
** fight
** File description:
** fight
*/
#include "include/my.h"

int five_case(g_t *game, int mark)
{
    if (mark == 17 || mark == 15 || mark == 13) {
        game->sizex = 60;
        game->sizey = 60;
        game->nb_c = 2;
        get_fight_map("scripts/script2", game);
        return (3);
    }
    if (mark == 18 || mark == 16 || mark == 14) {
        game->sizex = 70;
        game->sizey = 120;
        game->nb_c = 1;
        get_fight_map("scripts/script4", game);
        return (4);
    }
    return (-1);
}

int four_case(g_t *game, int mark)
{
    if (mark == 12) {
        game->sizex = 60;
        game->sizey = 120;
        game->nb_c = 2;
        get_fight_map("scripts/script2", game);
        return (3);
    }
    if (mark == 11) {
        game->sizex = 70;
        game->sizey = 120;
        game->nb_c = 1;
        get_fight_map("scripts/script10", game);
        return (4);
    }
    return (-1);
}

int third_case(g_t *game, int mark)
{
    if (mark == 7 || mark == 9) {
        game->sizex = 60;
        game->sizey = 60;
        game->nb_c = 2;
        get_fight_map("scripts/script8", game);
        return (3);
    }
    if (mark == 8 || mark == 10) {
        game->sizex = 60;
        game->sizey = 60;
        game->nb_c = 1;
        get_fight_map("scripts/script11", game);
        return (4);
    }
    return (-1);
}

int seconds_case(g_t *game, int mark)
{
    if (mark == 3 || mark == 5) {
        game->sizex = 50;
        game->sizey = 120;
        game->nb_c = 2;
        get_fight_map("scripts/script1", game);
        return (3);
    }
    if (mark == 4 || mark == 6) {
        game->sizex = 60;
        game->sizey = 120;
        game->nb_c = 1;
        get_fight_map("scripts/script6", game);
        return (4);
    }
    return (-1);
}

int firsts_case(g_t *game, int mark)
{
    if (mark == 1) {
        game->sizex = 60;
        game->sizey = 60;
        game->nb_c = 3;
        get_fight_map("scripts/script3", game);
        return (1);
    }
    if (mark == 2) {
        game->sizex = 60;
        game->sizey = 60;
        game->nb_c = 1;
        get_fight_map("scripts/script5", game);
        return (2);
    }
    return (-1);
}
