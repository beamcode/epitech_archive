/*
** EPITECH PROJECT, 2020
** change stat
** File description:
** change stat
*/
#include "include/my.h"

void change_ring_sword(item_t *t, game_t *game)
{
    if ((t->type >= 6 && t->type <= 10)) {
        game->stat->ring_life = 0;
        game->stat->ring_life = t->life;
        game->stat->ring_dam = 0;
        game->stat->ring_dam = t->damage;
        game->stat->ring_res = 0;
        game->stat->ring_res = t->resistance;
    }
    if ((t->type >= 26 && t->type <= 35)) {
        game->stat->sword_life = 0;
        game->stat->sword_life = t->life;
        game->stat->sword_dam = 0;
        game->stat->sword_dam = t->damage;
        game->stat->sword_res = 0;
        game->stat->sword_res = t->resistance;
    }
}

void change_jewel_boots(item_t *t, game_t *game)
{
    if (t->type >= 36 && t->type <= 40) {
        game->stat->jewel_life = 0;
        game->stat->jewel_life = t->life;
        game->stat->jewel_dam = 0;
        game->stat->jewel_dam = t->damage;
        game->stat->jewel_res = 0;
        game->stat->jewel_res = t->resistance;
    }
    if (t->type >= 21 && t->type <= 25) {
        game->stat->boots_life = 0;
        game->stat->boots_life = t->life;
        game->stat->boots_dam = 0;
        game->stat->boots_dam = t->damage;
        game->stat->boots_res = 0;
        game->stat->boots_res = t->resistance;
    }
}

void change_chest_amulet(item_t *t, game_t *game)
{
    if (t->type >= 16 && t->type <= 20) {
        game->stat->chest_life = 0;
        game->stat->chest_life = t->life;
        game->stat->chest_dam = 0;
        game->stat->chest_dam = t->damage;
        game->stat->chest_res = 0;
        game->stat->chest_res = t->resistance;
    }
    if (t->type >= 1 && t->type <= 5) {
        game->stat->amulet_life = 0;
        game->stat->amulet_life = t->life;
        game->stat->amulet_dam = 0;
        game->stat->amulet_dam = t->damage;
        game->stat->amulet_res = 0;
        game->stat->amulet_res = t->resistance;
    }
}

void change_helmet(item_t *t, game_t *game)
{
    if (t->type >= 11 && t->type <= 15) {
        game->stat->helmet_life = 0;
        game->stat->helmet_life = t->life;
        game->stat->helmet_dam = 0;
        game->stat->helmet_dam = t->damage;
        game->stat->helmet_res = 0;
        game->stat->helmet_res = t->resistance;
    }
}

void change_player_stats(item_t *t, game_t *game)
{
    change_ring_sword(t, game);
    change_jewel_boots(t, game);
    change_chest_amulet(t, game);
    change_helmet(t, game);
    game->player->damage = 0;
    game->player->resistance = 0;
    game->player->lifemax = 500;
    game->player->lifemax += game->stat->helmet_life + game->stat->ring_life +
        game->stat->amulet_life + game->stat->chest_life
        + game->stat->sword_life + game->stat->jewel_life +
        game->stat->boots_life + game->player->s_life;
    game->player->life = game->player->lifemax;
    game->player->damage = game->stat->helmet_dam + game->stat->ring_dam +
        game->stat->amulet_dam + game->stat->chest_dam
        + game->stat->sword_dam + game->stat->jewel_dam + game->stat->boots_dam
        + game->player->s_dam;
    game->player->resistance = game->stat->helmet_res + game->stat->ring_res +
        game->stat->amulet_res + game->stat->chest_res
        + game->stat->sword_res + game->stat->jewel_res + game->stat->boots_res
        + game->player->s_res;
}
