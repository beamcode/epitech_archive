/*
** EPITECH PROJECT, 2019
** play game
** File description:
** play game
*/
#include "include/my.h"

void free_all(game_t *game)
{
    free(game->pnj);
    free(game->button);
    free(game->mob);
    free(game->item);
    free(game->player);
    free(game->stat);
    free(game->text);
    free(game->info);
    free(game->map);
    free(game);
}

void destroy_all(game_t *game)
{
    for (map_t *t = game->map; t->nb != 11; t = t->next)
        if (t->sprite && t->nb > 0)
            sfSprite_destroy(t->sprite);
    for (mob_t *t = game->mob; t->mark != 5; t = t->next)
        if (t->sprite && t->mark > 0)
            sfSprite_destroy(t->sprite);
    for (pnj_t *t = game->pnj; t->mark != 10; t = t->next)
        if (t->sprite && t->mark > 0)
            sfSprite_destroy(t->sprite);
    for (button_t *t = game->button; t->mark != 123; t = t->next)
        if (t->sprite && t->mark > 0)
            sfSprite_destroy(t->sprite);
    for (item_t *t = game->item; t->mark != 70; t = t->next)
        if (t->sprite && t->mark > 0)
            sfSprite_destroy(t->sprite);
    for (info_t *a = game->info; a->mark != 26; a = a->next)
        if (a->sprite && a->mark > 0)
            sfSprite_destroy(a->sprite);
    free_all(game);
}

void create_text_credits(game_t *game)
{
    game->text->credits_text = sfText_create();

    sfText_setPosition(game->text->credits_text, (sfVector2f) {180, 1080});
    sfText_setScale(game->text->credits_text, (sfVector2f) {1.6, 1.6});
    sfText_setFont(game->text->credits_text, game->text->font);
    sfText_setColor(game->text->credits_text, sfBlack);
}

int open_window(game_t *game)
{
    create_window(game);
    create_text_credits(game);
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            search_event(game);
        if (game->menu == 0) {
            my_game_clock(game);
            check_map_number(game);
        }
        if (game->cinematic == 1)
            draw_cinematic(game);
        display_sprite(game);
        apply_text_modif(game);
        sfRenderWindow_display(game->window);
        sfRenderWindow_clear(game->window, sfBlack);
    }
    destroy_all(game);
    sfMusic_destroy(game->music->menumusic);
    sfMusic_destroy(game->music->gamemusic);
    return (0);
}
