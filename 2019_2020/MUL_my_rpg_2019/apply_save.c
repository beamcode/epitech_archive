/*
** EPITECH PROJECT, 2020
** apply save
** File description:
** apply save
*/
#include "include/my.h"

void apply_stats_save(char **tab, game_t *game)
{
    game->current_map = my_atoi(tab[0]);
    game->min = my_atoi(tab[1]);
    game->hours = my_atoi(tab[2]);
    game->player->life = my_atoi(tab[4]);
    game->player->level = my_atoi(tab[5]);
    game->player->lifemax = my_atoi(tab[6]);
    game->player->lifebar = my_atoi(tab[7]);
    game->player->xpbar = my_atoi(tab[8]);
    game->player->xp = my_atoi(tab[9]);
    game->player->xpmax = my_atoi(tab[10]);
    game->player->damage = my_atoi(tab[11]);
    game->player->resistance = my_atoi(tab[12]);
    game->player->points = my_atoi(tab[13]);
    game->player->s_life = my_atoi(tab[14]);
    game->player->s_dam = my_atoi(tab[15]);
    game->player->s_res = my_atoi(tab[16]);
}

void apply_item_save(char **tab, game_t *game)
{
    float a = my_atoi(tab[17]);
    float b = my_atoi(tab[18]);

    game->player->pos.x = a;
    game->player->pos.y = b;
    sfSprite_setPosition(game->player->sprite, game->player->pos);
    game->stat->ring_life = my_atoi(tab[19]);
    game->stat->jewel_life = my_atoi(tab[20]);
    game->stat->sword_life = my_atoi(tab[21]);
    game->stat->chest_life = my_atoi(tab[22]);
    game->stat->amulet_life = my_atoi(tab[23]);
    game->stat->boots_life = my_atoi(tab[24]);
    game->stat->helmet_life = my_atoi(tab[25]);
    game->stat->ring_dam = my_atoi(tab[26]);
    game->stat->jewel_dam = my_atoi(tab[27]);
    game->stat->sword_dam = my_atoi(tab[28]);
    game->stat->chest_dam = my_atoi(tab[29]);
}

void apply_quest_save(char **tab, game_t *game)
{
    game->quest->q2 = my_atoi(tab[40]);
    game->quest->q3 = my_atoi(tab[41]);
    game->quest->q4 = my_atoi(tab[42]);
    game->quest->q5 = my_atoi(tab[43]);
    game->quest->q6 = my_atoi(tab[44]);
    game->quest->quest = my_atoi(tab[45]);
    game->quest->boss = my_atoi(tab[46]);
    game->stat->helmet_res = my_atoi(tab[39]);
}

void apply_save(char **tab, game_t *game)
{
    int i = 46;

    apply_stats_save(tab, game);
    apply_item_save(tab, game);
    game->stat->amulet_dam = my_atoi(tab[30]);
    game->stat->boots_dam = my_atoi(tab[31]);
    game->stat->helmet_dam = my_atoi(tab[32]);
    game->stat->ring_res = my_atoi(tab[33]);
    game->stat->jewel_res = my_atoi(tab[34]);
    game->stat->sword_res = my_atoi(tab[35]);
    game->stat->chest_res = my_atoi(tab[36]);
    game->stat->amulet_res = my_atoi(tab[37]);
    game->stat->boots_res = my_atoi(tab[38]);
    apply_quest_save(tab, game);
    while (tab[i] != NULL) {
        for (item_t *t = game->item; t->mark != 70; t = t->next)
            if (t->sprite && t->mark == my_atoi(tab[i]))
                t->get = 1;
        i++;
    }
    free_array(tab);
}
