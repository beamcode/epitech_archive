/*
** EPITECH PROJECT, 2020
** fill game
** File description:
** fill game
*/
#include "include/my.h"

quest_t *fill_quest(void)
{
    quest_t *quest = malloc(sizeof(quest_t));

    if (quest != NULL) {
        quest->q2 = 0;
        quest->q3 = 0;
        quest->q4 = 0;
        quest->q5 = 0;
        quest->q6 = 0;
        quest->quest = 1;
        quest->boss = 0;
    }
    return (quest);
}

map_t *fill_game_map(void)
{
    map_t *map = malloc(sizeof(map_t));

    if (map != NULL) {
        map->sprite = NULL;
        map->next = NULL;
        map->mark = 0;
        map->nb = 0;
    }
    return (map);
}

obs_t *fill_game_obstacles(void)
{
    obs_t *obs = malloc(sizeof(obs_t));

    if (obs != NULL) {
        obs->next = NULL;
        obs->map_nb = 0;
        obs->mark = 0;
    }
    return (obs);
}

info_t *fill_game_info(void)
{
    info_t *info = malloc(sizeof(info_t));

    if (info != NULL) {
        info->texture = NULL;
        info->sprite = NULL;
        info->next = NULL;
        info->mark = 0;
    }
    return (info);
}
