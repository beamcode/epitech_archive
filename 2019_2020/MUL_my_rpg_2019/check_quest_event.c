/*
** EPITECH PROJECT, 2020
** quest event
** File description:
** quest event
*/
#include "include/my.h"

void get_boss_sound(game_t *game)
{
    static int d = 0;

    if (game->quest->quest == 10 && game->quest->boss == 1) {
        game->credits = 1;
        game->menu = 2;
        sfMusic_stop(game->music->gamemusic);
        sfMusic_stop(game->music->grow);
        sfMusic_play(game->music->credits);
        sfMusic_setLoop(game->music->credits, sfTrue);
    }
    if (game->current_map == 10 && d == 0) {
        sfMusic_play(game->music->grow);
        sfMusic_setLoop(game->music->grow, sfTrue);
        d = 1;
    }
}

void get_boss_event(game_t *game)
{
    static int a = 0;

    if (a == 0 && game->quest->quest == 10) {
        a = 1;
        sfMusic_stop(game->music->quest);
        sfMusic_play(game->music->gamemusic);
    }
    if (game->player->pos.x <= 1010 && game->player->pos.x >= 950
        && game->player->pos.y <= 377 && game->player->pos.y >= 314
        && game->current_map == 3 && game->quest->quest == 10) {
        game->current_map = 10;
        game->player->pos.x = 570;
        game->player->pos.y = 305;
        sfSprite_setPosition(game->player->sprite, game->player->pos);
        game->on_move = 0;
        game->quest->q6 = 1;
    }
    get_boss_sound(game);
}

void get_quest_four_cursor(game_t *game)
{
    if (game->pos_mouse.x <= 1208 && game->pos_mouse.x >= 1143
        && game->pos_mouse.y <= 484 && game->pos_mouse.y >= 428
        && game->current_map == 4 && game->quest->quest == 4) {
        game->cur = 1;
        for (button_t *t = game->button; t->mark != 127; t = t->next)
            if (t->sprite && t->mark == 126 && game->cur == 1)
                sfSprite_setPosition(t->sprite, game->curs);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->inventory = 1;
            for (item_t *t = game->item; t->mark != 31; t = t->next)
                if (t->sprite && t->mark == 30) {
                    t->get = 1;
                    game->quest->q3 = 1;
                }
        }
    }
    else {
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
        game->cur = 0;
    }
}

void get_quest_nine_cursor(game_t *game)
{
    if (game->pos_mouse.x <= 1458 && game->pos_mouse.x >= 1399
        && game->pos_mouse.y <= 683 && game->pos_mouse.y >= 634
        && game->current_map == 8 && game->quest->quest == 8) {
        game->cur2 = 1;
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
        for (button_t *t = game->button; t->mark != 127; t = t->next)
            if (t->sprite && t->mark == 126 && game->cur2 == 1)
                sfSprite_setPosition(t->sprite, game->curs);
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            game->inventory = 1;
            for (item_t *t = game->item; t->mark != 66; t = t->next)
                if (t->sprite && t->mark == 65) {
                    t->get = 1;
                    game->quest->q5 = 1;
                }
        }
    }
    else {
        sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
        game->cur2 = 0;
    }
}

void search_quest_event(game_t *game)
{
    static int b = 0;
    static int c = 0;

    game->curs.x = game->pos_mouse.x - 20;
    game->curs.y = game->pos_mouse.y - 15;
    get_boss_event(game);
    get_quest_four_cursor(game);
    get_quest_nine_cursor(game);
    if (game->quest->quest == 6 && b == 0) {
        sfMusic_play(game->music->radio2);
        b = 1;
    }
    if (game->quest->quest == 9 && c == 0) {
        sfMusic_play(game->music->radio3);
        c = 1;
    }
}
