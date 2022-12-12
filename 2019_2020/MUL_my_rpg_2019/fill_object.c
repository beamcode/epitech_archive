/*
** EPITECH PROJECT, 2020
** fill object
** File description:
** fill object
*/
#include "include/my.h"

button_t *fill_my_button(void)
{
    button_t *button = malloc(sizeof(button_t));

    if (button != NULL) {
        button->sprite = NULL;
        button->texture = NULL;
        button->next = NULL;
        button->mark = 0;
    }
    return (button);
}

pnj_t *fill_my_pnj(void)
{
    pnj_t *pnj = malloc(sizeof(pnj_t));

    if (pnj != NULL) {
        pnj->texture = NULL;
        pnj->sprite = NULL;
        pnj->next = NULL;
        pnj->mark = 0;
        pnj->map = 0;
    }
    return (pnj);
}

mob_t *fill_my_mob(void)
{
    mob_t *mob = malloc(sizeof(mob_t));

    if (mob != NULL) {
        mob->texture = NULL;
        mob->sprite = NULL;
        mob->next = NULL;
        mob->mv = 0;
        mob->tmp = 0;
        mob->count = 0;
        mob->mark = 0;
        mob->map = 0;
        mob->type = 0;
    }
    return (mob);
}

item_t *set_item(item_t *item)
{
    item->texture = NULL;
    item->sprite = NULL;
    item ->next = NULL;
    item->mark = 0;
    item->get = 0;
    item->on = 0;
    item->type = 0;
    item->damage = 0;
    item->resistance = 0;
    item->life = 0;
    item->mv_item = 0;
    item->helmet = 0;
    item->amulet = 0;
    item->chest = 0;
    item->boots = 0;
    item->ring = 0;
    item->sword = 0;
    item->jewel = 0;
    return (item);
}

item_t *fill_my_item(void)
{
    item_t *item = malloc(sizeof(item_t));

    if (item != NULL)
        item = set_item(item);
    return (item);
}
