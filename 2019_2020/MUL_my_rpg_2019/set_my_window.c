/*
** EPITECH PROJECT, 2019
** set win
** File description:
** set win
*/
#include "include/my.h"

void init_item_values(game_t *game)
{
    game->item->mv_item = 0;
    game->item->helmet = 0;
    game->item->amulet = 0;
    game->item->chest = 0;
    game->item->boots = 0;
    game->item->ring = 0;
    game->item->sword = 0;
    game->item->jewel = 0;
}

void init_settings_values(game_t *game)
{
    game->nb = 0;
    game->settings = 0;
    game->menupause = 0;
    game->status = 0;
    game->p1_on = 0;
    game->p2_on = 0;
    game->p3_on = 0;
    game->p4_on = 0;
    game->key1 = 0;
    game->key2 = 0;
    game->key3 = 0;
    game->key4 = 0;
}

void init_values(game_t *game)
{
    game->menu1 = 0;
    game->menu2 = 0;
    game->menu3 = 0;
    game->menu4 = 0;
    game->menu = 1;
    game->settings = 0;
    game->inventory = 0;
    init_item_values(game);
    init_settings_values(game);
    game->apply = 0;
    game->s1 = 0;
    game->s2 = 0;
    game->s3 = 0;
    game->s4 = 0;
    game->on_move = 0;
    game->axe_x = 0;
    game->axe_y = 0;
    game->current_map = 1;
    game->clock = sfClock_create();
    game->scroll_clock = sfClock_create();
    game->cinematic = 1;
}

void get_credits(game_t *game)
{
    game->perso_sprite = sfSprite_create();
    game->perso_texture = sfTexture_createFromFile("ressources/per.png", NULL);
    sfSprite_setTexture(game->perso_sprite, game->perso_texture, sfTrue);
    sfSprite_setPosition(game->perso_sprite, (sfVector2f) {1150, 350});
    sfSprite_setScale(game->perso_sprite, (sfVector2f) {4, 4});
    game->perso_rect.width = 70;
    game->perso_rect.height = 85;
    game->perso_rect.left = 0;
    game->perso_rect.top = 85;
    sfSprite_setTextureRect(game->perso_sprite, game->perso_rect);
}

void create_window(game_t *game)
{
    game->min = 0.00;
    game->hours = 17;
    game->mv = 0;
    game->cur = 0;
    game->pass = 0;
    game->credits = 0;
    game->perso_clock = sfClock_create();
    game->story = get_my_map("story");
    game->story2 = get_my_map("story2");
    game->temp = "\0";
    game->temp2 = "\0";
    get_credits(game);
    game->window = create_my_window(1920, 1080);
    init_values(game);
    sfMusic_play(game->music->cine);
    sfMusic_setLoop(game->music->cine, sfTrue);
    sfText_setString(game->text->open_inv, "e");
    sfText_setString(game->text->pause, "ESC");
    sfText_setString(game->text->stats, "c");
    sfText_setString(game->text->quest, "q");
}
