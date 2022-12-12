/*
** EPITECH PROJECT, 2020
** init stat
** File description:
** init stat
*/
#include "include/my.h"

void init_stat_values(stat_t *stat)
{
    stat->ring_life = 0;
    stat->sword_life = 0;
    stat->jewel_life = 0;
    stat->helmet_life = 0;
    stat->boots_life = 0;
    stat->amulet_life = 0;
    stat->chest_life = 0;
    stat->ring_res = 0;
    stat->sword_res = 0;
    stat->jewel_res = 0;
    stat->helmet_res = 0;
    stat->boots_res = 0;
    stat->amulet_res = 0;
    stat->chest_res = 0;
    stat->ring_dam = 0;
    stat->sword_dam = 0;
    stat->jewel_dam = 0;
    stat->helmet_dam = 0;
    stat->boots_dam = 0;
    stat->amulet_dam = 0;
    stat->chest_dam = 0;
}

stat_t *get_item_stat(void)
{
    stat_t *stat = malloc(sizeof(stat_t));

    if (stat != NULL)
        init_stat_values(stat);
    return (stat);
}

void rect_player(player_t *player)
{
    player->rect.top = 0;
    player->rect.left = 0;
    player->rect.width = 50;
    player->rect.height = 50;
    sfSprite_setTextureRect(player->sprite, player->rect);
}

player_t *init_player_values(player_t *player)
{
    player->life = 500;
    player->level = 1;
    player->lifemax = player->life;
    player->xp = 0;
    player->xpmax = 1200;
    player->damage = 0;
    player->resistance = 0;
    player->lifebar = 8;
    player->xpbar = 1;
    player->points = 15;
    player->s_life = 0;
    player->s_res = 0;
    player->s_dam = 0;
    return (player);
}

player_t *get_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (player != NULL) {
        player = init_player_values(player);
        player->texture = sfTexture_createFromFile("ressources/pp.png", NULL);
        player->sprite = sfSprite_create();
        sfSprite_setTexture(player->sprite, player->texture, sfTrue);
        player->pos.x = 300;
        player->pos.y = 600;
        rect_player(player);
        sfSprite_setPosition(player->sprite, player->pos);
    }
    return (player);
}
