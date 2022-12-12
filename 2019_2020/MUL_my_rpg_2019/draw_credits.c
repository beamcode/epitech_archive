/*
** EPITECH PROJECT, 2020
** draw credits
** File description:
** draw credits
*/
#include "include/my.h"

void animate_perso(game_t *game)
{
    double speed = 0.17;

    game->perso_time = sfClock_getElapsedTime(game->perso_clock);
    if (game->perso_time.microseconds / 1000000.0 > speed) {
        game->perso_rect.left += 70;
        if (game->perso_rect.left > 210) {
            game->perso_rect.left = 0;
            game->perso_rect.top += 85;
        }
        if (game->perso_rect.top > 255)
            game->perso_rect.top = 0;
        sfClock_restart(game->perso_clock);
    }
    sfSprite_setTextureRect(game->perso_sprite, game->perso_rect);
}

void draw_credits(game_t *game)
{
    sfVector2f pos_text = sfText_getPosition(game->text->credits_text);

    animate_perso(game);
    sfText_setString(game->text->credits_text, game->story2);
    for (button_t *t = game->button; t->mark != 133; t = t->next)
        if (t->sprite && t->mark == 128)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    sfRenderWindow_drawSprite(game->window, game->perso_sprite, NULL);
    sfRenderWindow_drawText(game->window, game->text->credits_text, NULL);
    for (button_t *t = game->button; t->mark != 133; t = t->next)
        if (t->sprite && t->mark == 132)
            sfRenderWindow_drawSprite(game->window, t->sprite, NULL);
    if (pos_text.y > -5600)
        sfText_move(game->text->credits_text, (sfVector2f) {0, -2});
}
