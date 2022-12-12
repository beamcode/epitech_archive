/*
** EPITECH PROJECT, 2020
** text pos
** File description:
** text pos
*/
#include "include/my.h"

void set_text_pos_two(game_t *game)
{
    sfText_setPosition(game->text->stats, (sfVector2f) {593, 654});
    sfText_setPosition(game->text->quest, (sfVector2f) {597, 776});
    sfText_setPosition(game->text->menu_v, (sfVector2f) {344, 418});
    sfText_setPosition(game->text->game_v, (sfVector2f) {346, 529});
    sfText_setPosition(game->text->sound_v, (sfVector2f) {347, 644});
    sfText_setPosition(game->text->scroll_text, (sfVector2f) {300, 10});
    sfText_setScale(game->text->scroll_text, (sfVector2f) {1.4, 1.4});
}

void set_text_pos(game_t *game)
{
    sfText_setPosition(game->text->lifemax, (sfVector2f) {69.0, 975.0});
    sfText_setPosition(game->text->life, (sfVector2f) {69.0, 940.0});
    sfText_setPosition(game->text->div, (sfVector2f) {69.0, 947.0});
    sfText_setPosition(game->text->div2, (sfVector2f) {480.0, 937.0});
    sfText_setPosition(game->text->xp, (sfVector2f) {480.0, 930.0});
    sfText_setPosition(game->text->xpmax, (sfVector2f) {480.0, 965.0});
    sfText_setPosition(game->text->time, (sfVector2f) {1760.0, 20.0});
    sfText_setPosition(game->text->points, (sfVector2f) {155, 374});
    sfText_setPosition(game->text->level, (sfVector2f) {300, 374});
    sfText_setPosition(game->text->lifestat, (sfVector2f) {260, 435});
    sfText_setPosition(game->text->xpstat, (sfVector2f) {260, 509});
    sfText_setPosition(game->text->res, (sfVector2f) {260, 587});
    sfText_setPosition(game->text->dam, (sfVector2f) {260, 660});
    sfText_setPosition(game->text->open_inv, (sfVector2f) {590, 432});
    sfText_setPosition(game->text->pause, (sfVector2f) {592, 542});
    sfText_setPosition(game->text->key1, (sfVector2f) {590, 430});
    sfText_setPosition(game->text->key2, (sfVector2f) {580, 538});
    sfText_setPosition(game->text->key3, (sfVector2f) {594, 648});
    set_text_pos_two(game);
}
