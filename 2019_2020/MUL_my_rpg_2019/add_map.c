/*
** EPITECH PROJECT, 2020
** add map
** File description:
** add map
*/
#include "include/my.h"

map_t *add_map(char **tab, map_t *map)
{
    map_t *new = malloc(sizeof(map_t));

    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(tab[1], NULL);
    new->pos.x = my_atoi(tab[2]);
    new->pos.y = my_atoi(tab[3]);
    new->mark = my_atoi(tab[4]);
    new->nb = my_atoi(tab[5]);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setPosition(new->sprite, new->pos);
    if (map == NULL)
        return (map);
    else
        for (; map->next != NULL; map = map->next);
    map->next = new;
    new->next = NULL;
    return (map);
}

obs_t *add_obs(char **tab, obs_t *obs)
{
    obs_t *new = malloc(sizeof(obs_t));

    new->pos_min.x = my_atoi(tab[1]);
    new->pos_min.y = my_atoi(tab[3]);
    new->pos_max.x = my_atoi(tab[2]);
    new->pos_max.y = my_atoi(tab[4]);
    new->map_nb = my_atoi(tab[5]);
    new->mark = my_atoi(tab[6]);
    if (obs == NULL)
        return (obs);
    else
        for (; obs->next != NULL; obs = obs->next);
    obs->next = new;
    new->next = NULL;
    return (obs);
}

button_t *add_button(char **tab, button_t *button)
{
    button_t *new = malloc(sizeof(button_t));

    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(tab[1], NULL);
    new->pos.x = my_atoi(tab[2]);
    new->pos.y = my_atoi(tab[3]);
    new->mark = my_atoi(tab[4]);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setPosition(new->sprite, new->pos);
    if (button == NULL)
        return (button);
    else
        for (; button->next != NULL; button = button->next);
    button->next = new;
    new->next = NULL;
    return (button);
}

pnj_t *add_pnj(char **tab, pnj_t *pnj)
{
    pnj_t *new = malloc(sizeof(pnj_t));

    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(tab[1], NULL);
    new->pos.x = my_atoi(tab[2]);
    new->pos.y = my_atoi(tab[3]);
    new->mark = my_atoi(tab[4]);
    new->map = my_atoi(tab[5]);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    sfSprite_setPosition(new->sprite, new->pos);
    new->pos_max.x = new->pos.x + 40;
    new->pos_min.x = new->pos.x - 0;
    new->pos_max.y = new->pos.y + 60;
    new->pos_min.y = new->pos.y - 0;
    if (pnj == NULL)
        return (pnj);
    else
        for ( ; pnj->next != NULL; pnj = pnj->next);
    pnj->next = new;
    new->next = NULL;
    return (pnj);
}
