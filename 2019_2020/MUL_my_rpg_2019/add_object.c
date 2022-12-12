/*
** EPITECH PROJECT, 2020
** add object
** File description:
** add object
*/
#include "include/my.h"

info_t *add_info(char **tab, info_t *info)
{
    info_t *new = malloc(sizeof(info_t));

    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(tab[1], NULL);
    new->pos.x = my_atoi(tab[2]);
    new->pos.y = my_atoi(tab[3]);
    new->mark = my_atoi(tab[4]);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setPosition(new->sprite, new->pos);
    if (info == NULL)
        return (info);
    else
        for ( ; info->next != NULL; info = info->next);
    info->next = new;
    new->next = NULL;
    return (info);
}

mob_t *set_mob(mob_t *new)
{
    new->tmp = 0;
    new->count = 0;
    new->mv = 0;
    new->on = 1;
    new->rect.top = 0;
    new->rect.left = 0;
    new->rect.width = 80;
    new->rect.height = 80;
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setTextureRect(new->sprite, new->rect);
    sfSprite_setPosition(new->sprite, new->pos);
    return (new);
}

mob_t *add_mob(char **tab, mob_t *mob)
{
    mob_t *new = malloc(sizeof(mob_t));

    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(tab[1], NULL);
    new->pos.x = my_atoi(tab[2]);
    new->pos.y = my_atoi(tab[3]);
    new->mark = my_atoi(tab[4]);
    new->map = my_atoi(tab[5]);
    new->type = my_atoi(tab[6]);
    new->ipos.x = new->pos.x;
    new->ipos.y = new->pos.y;
    new = set_mob(new);
    if (mob == NULL)
        return (mob);
    else
        for ( ; mob->next != NULL; mob = mob->next);
    mob->next = new;
    new->next = NULL;
    return (mob);
}

item_t *init_item_value(char **tab, item_t *new)
{
    new->get = 0;
    new->on = 0;
    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(tab[1], NULL);
    new->pos.x = my_atoi(tab[2]);
    new->pos.y = my_atoi(tab[3]);
    new->pos_max.x = new->pos.x + 70;
    new->pos_max.y = new->pos.y + 75;
    new->pos_min.x = new->pos.x - 20;
    new->pos_min.y = new->pos.y - 20;
    new->mark = my_atoi(tab[4]);
    new->type = my_atoi(tab[5]);
    new->damage = my_atoi(tab[6]);
    new->resistance = my_atoi(tab[7]);
    new->life = my_atoi(tab[8]);
    return (new);
}

item_t *add_item(char **tab, item_t *item)
{
    item_t *new = malloc(sizeof(item_t));

    new = init_item_value(tab, new);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setPosition(new->sprite, new->pos);
    if (item == NULL)
        return (item);
    else
        for ( ; item->next != NULL; item = item->next);
    item->next = new;
    new->next = NULL;
    return (item);
}
