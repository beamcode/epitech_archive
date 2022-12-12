/*
** EPITECH PROJECT, 2020
** text modif
** File description:
** text modif
*/
#include "include/my.h"

void apply_settings_modif(game_t *game)
{
    char *menu_v = NULL;
    char *game_v = NULL;
    char *sound_v = NULL;

    menu_v = my_itoa(game->music->menu_v);
    game_v = my_itoa(game->music->game_v);
    sound_v = my_itoa(game->music->sound_v);
    sfText_setString(game->text->menu_v, menu_v);
    sfText_setString(game->text->game_v, game_v);
    sfText_setString(game->text->sound_v, sound_v);
}

void apply_stats_modif(game_t *game)
{
    char *res = NULL;
    char *dam = NULL;
    char *points = NULL;
    char *level = NULL;

    res = my_itoa(game->player->resistance);
    dam = my_itoa(game->player->damage);
    points = my_itoa(game->player->points);
    level = my_itoa(game->player->level);
    sfText_setString(game->text->div, "____");
    sfText_setString(game->text->div2, "____");
    sfText_setString(game->text->time, game->gametime);
    sfText_setString(game->text->points, points);
    sfText_setString(game->text->level, level);
    sfText_setString(game->text->res, res);
    sfText_setString(game->text->dam, dam);
    apply_settings_modif(game);
}

void apply_bar_modif(game_t *game)
{
    char *life = NULL;
    char *lifemax = NULL;
    char *xp = NULL;
    char *xpmax = NULL;

    xp = my_itoa(game->player->xp);
    xpmax = my_itoa(game->player->xpmax);
    lifemax = my_itoa(game->player->lifemax);
    life = my_itoa(game->player->life);
    sfText_setString(game->text->lifemax, lifemax);
    sfText_setString(game->text->life, life);
    sfText_setString(game->text->xp, xp);
    sfText_setString(game->text->xpmax, xpmax);
    sfText_setString(game->text->lifestat, lifemax);
    sfText_setString(game->text->xpstat, xp);
}

void apply_text_modif(game_t *game)
{
    apply_bar_modif(game);
    apply_stats_modif(game);
    draw_text(game);
}
