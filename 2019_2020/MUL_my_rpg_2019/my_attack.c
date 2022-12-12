/*
** EPITECH PROJECT, 2020
** c
** File description:
** c
*/

#include "include/my.h"
#include <unistd.h>

void counter_attack(g_t *game)
{
    int i =  (rand() % game->nb_c);
    enemy_t *t = game->enemy;

    if (i == 0)
        i++;
    for (; i != 0; t = t->next) {
        if (t->sprite && t->hp >= -10)
            break;
        i--;
    }
    if (t->pos.x <= 600) {
        usleep(20000);
        move_my_monster_towards(game, t);
    }
    move_my_monster_backwards(game, t);
    hero_take_damage(1, &game->pv_bar[3]);
}

void animate_attack(hero_t *h, enemy_t *t, g_t *game)
{
    sfVector2f enemyp = sfSprite_getPosition(t->sprite);
    sfVector2f herop = sfSprite_getPosition(h->sprite);

    move_my_hero_backwards(game, h, herop);
    move_my_hero_forwards(game, h);
    if (enemyp.x <= 600) {
        while (t->pos.x >= 570) {
            sfSprite_setPosition(t->sprite,
                (sfVector2f) {t->pos.x - 20, t->pos.y});
            t->pos = sfSprite_getPosition(t->sprite);
            sfRenderWindow_clear(game->window, sfBlack);
            draw_background(game, game->back);
            draw_my_real_game(game);
            sfRenderWindow_display(game->window);
        }
    }
    get_impact_monster(game, t);
}

void mob_take_damage(int attack, lifebar_t *lifebar, g_t *game)
{
    if (game->nb_c == 2)
        lifebar->size.x -= attack + 40;
    if (game->nb_c == 3)
        lifebar->size.x -= attack + 28;
    if (game->nb_c == 1)
        lifebar->size.x -= attack + 50;

    sfRectangleShape_setSize(lifebar->rect_s, lifebar->size);
}

void get_my_type_attack(g_t *game, command_t *c)
{
    if (game->event.type == sfEvtMouseButtonPressed) {
        c->position_clic = sfMouse_getPositionRenderWindow(game->window);
        if (c->position_clic.x > 650 && c->position_clic.x < 770
            && c->position_clic.y > 840 && c->position_clic.y < 960)
            c->attack = 4;
        if (c->position_clic.x > 250 && c->position_clic.x < 370
            && c->position_clic.y > 840 && c->position_clic.y < 960)
            c->attack = 6;
        if (c->position_clic.x > 1450 && c->position_clic.x < 1570
            && c->position_clic.y > 840 && c->position_clic.y < 960)
            c->attack = 8;
        if (c->position_clic.x > 1050 && c->position_clic.x < 1170
            && c->position_clic.y > 840 && c->position_clic.y < 960)
            c->attack = 8;
    }
}

int get_my_attack(g_t *game, command_t *c)
{
    int mark = 0;

    get_my_type_attack(game, c);
    if (game->event.type == sfEvtMouseButtonPressed) {
        c->position_clic = sfMouse_getPositionRenderWindow(game->window);
        for (enemy_t *t = game->enemy; t != NULL; t = t->next) {
            if (c->position_clic.x > t->pos.x
                && c->position_clic.x < (t->pos.x + game->sizex)
                && c->position_clic.y > t->pos.y
                && c->position_clic.y < (t->pos.y + game->sizey) && t->sprite) {
                t->hp -= c->attack;
                c->attack = 0;
                animate_attack(game->hero, t, game);
                mob_take_damage(c->attack, &game->pv_bar[1], game);
                mark = 1;
            }
        }
    }
    return (mark);
}
