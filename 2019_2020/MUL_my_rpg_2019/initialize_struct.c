/*
** EPITECH PROJECT, 2020
** defender
** File description:
** ok
*/

#include "include/my.h"

command_t *fill_my_command(void)
{
    command_t *command = malloc(sizeof(command_t));

    if (NULL != command) {
        command->pos_mouse.y = 0;
        command->pos_tbase1.y = 0;
        command->pos_tbase2.y = 0;
        command->pos_tbase3.y = 0;
        command->pos_tbase4.y = 0;
        command->pos_mouse.x = 0;
        command->pos_tbase1.x = 0;
        command->pos_tbase2.x = 0;
        command->pos_tbase3.x = 0;
        command->pos_tbase4.x = 0;
        command->mark = 0;
        command->attack = 0;
    }
    return (command);
}

but_t *fill_my_but(void)
{
    but_t *but = malloc(sizeof(but_t));

    if (NULL != but) {
        but->pos.x = 0;
        but->pos.y = 0;
        but->sprite = NULL;
        but->next = NULL;
        but->mark = 0;
        but->color = 0;
        but->texture = NULL;
    }
    return (but);
}

battle_t *fill_my_battle(void)
{
    battle_t *battle = malloc(sizeof(battle_t));

    if (NULL != battle) {
        battle->run = 0;
        battle->mouse.x = 0;
        battle->mouse.y = 0;
        battle->id = 0;
        battle->map = 0;
        battle->number_fight = 0;
        battle->icone = NULL;
        battle->background = NULL;
        battle->texture = NULL;
        battle->text = 0;
        battle->clock = NULL;
    }
    return (battle);
}

hero_t *fill_my_hero(void)
{
    hero_t *hero = malloc(sizeof(hero_t));

    if (NULL != hero) {
        hero->form = NULL;
        hero->pos.x = 0;
        hero->pos.y = 0;
        hero->nw.x = 0;
        hero->nw.y = 0;
        hero->alive = 0;
        hero->select = 0;
        hero->played = 0;
        hero->move = 0;
        hero->attack = 0;
        hero->sword = 0;
        hero->spell_id = 0;
        hero->target = 0;
        hero->hp = 10;
        hero->dmg = 0;
        hero->armor = 0;
    }
    return (hero);
}

enemy_t *fill_my_enemy(void)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    if (enemy != NULL) {
        enemy->texture = NULL;
        enemy->sprite = NULL;
        enemy->pos.x = 0;
        enemy->pos.y = 0;
        enemy->dmg = 0;
        enemy->mark = 0;
        enemy->hp = 0;
        enemy->next = NULL;
    }
    return (enemy);
}
