/*
** EPITECH PROJECT, 2020
** draw tetx
** File description:
** draw text
*/
#include "include/my.h"

void draw_menu(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->text->life, NULL);
    sfRenderWindow_drawText(game->window, game->text->lifemax, NULL);
    sfRenderWindow_drawText(game->window, game->text->div, NULL);
    sfRenderWindow_drawText(game->window, game->text->div2, NULL);
    sfRenderWindow_drawText(game->window, game->text->xp, NULL);
    sfRenderWindow_drawText(game->window, game->text->xpmax, NULL);
    sfRenderWindow_drawText(game->window, game->text->time, NULL);
}

void draw_text_settings(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->text->menu_v, NULL);
    sfRenderWindow_drawText(game->window, game->text->game_v, NULL);
    sfRenderWindow_drawText(game->window, game->text->sound_v, NULL);
    sfRenderWindow_drawText(game->window, game->text->key1, NULL);
    sfRenderWindow_drawText(game->window, game->text->key2, NULL);
    sfRenderWindow_drawText(game->window, game->text->key3, NULL);
}

void draw_text(game_t *game)
{
    if (game->menu == 0) {
        draw_menu(game);
        if (game->status == 1) {
            sfRenderWindow_drawText(game->window, game->text->points, NULL);
            sfRenderWindow_drawText(game->window, game->text->lifestat, NULL);
            sfRenderWindow_drawText(game->window, game->text->xpstat, NULL);
            sfRenderWindow_drawText(game->window, game->text->res, NULL);
            sfRenderWindow_drawText(game->window, game->text->dam, NULL);
            sfRenderWindow_drawText(game->window, game->text->level, NULL);
        }
    }
    if (game->cinematic == 1)
        sfRenderWindow_drawText(game->window, game->text->scroll_text, NULL);
    if (game->settings == 1)
        draw_text_settings(game);
    set_text_pos(game);
}
