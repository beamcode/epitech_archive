/*
** EPITECH PROJECT, 2019
** game_sprite_load.c
** File description:
** yes
*/

#include "../include/my.h"

void get_game_files(st_s *st)
{
    st->gf_bg1 = sfTexture_createFromFile ("assets/game_bg/1.png", NULL);
    st->gf_bg2 = sfTexture_createFromFile ("assets/game_bg/2.png", NULL);
    st->gf_bg3 = sfTexture_createFromFile ("assets/game_bg/3.png", NULL);
    st->gf_player_run = sfTexture_createFromFile
    ("assets/sprites/player1_run.png", NULL);
    st->gf_player_duck = sfTexture_createFromFile
    ("assets/sprites/player1_duck.png", NULL);
    st->gf_player_jump = sfTexture_createFromFile
    ("assets/sprites/player1_jump.png", NULL);
    st->gf_robot = sfTexture_createFromFile
    ("assets/sprites/robot.png", NULL);
    st->gf_slug = sfTexture_createFromFile
    ("assets/sprites/slug.png", NULL);
    st->gf_bg_lose = sfTexture_createFromFile
    ("assets/game_bg/lose.png", NULL);
    st->gf_bg_win = sfTexture_createFromFile ("assets/game_bg/win.png", NULL);
    st->game_music = sfMusic_createFromFile ("assets/music/game_music.ogg");
}

void associate_game_files(st_s *st)
{
    sfSprite_setTexture(st->game_bg1, st->gf_bg1, sfTrue);
    sfSprite_setTexture(st->game_bg2, st->gf_bg2, sfTrue);
    sfSprite_setTexture(st->game_bg3, st->gf_bg3, sfTrue);
    sfSprite_setTexture(st->gp_run, st->gf_player_run, sfTrue);
    sfSprite_setTexture(st->gp_duck, st->gf_player_duck, sfTrue);
    sfSprite_setTexture(st->gp_jump, st->gf_player_jump, sfTrue);
    sfSprite_setTexture(st->ge_robot1, st->gf_robot, sfTrue);
    sfSprite_setTexture(st->ge_robot2, st->gf_robot, sfTrue);
    sfSprite_setTexture(st->ge_slug1, st->gf_slug, sfTrue);
    sfSprite_setTexture(st->ge_slug2, st->gf_slug, sfTrue);
    sfSprite_setTexture(st->game_bg_win, st->gf_bg_win, sfTrue);
    sfSprite_setTexture(st->game_bg_lose, st->gf_bg_lose, sfTrue);
}

void create_game_sprites(st_s *st)
{
    st->game_bg1 = sfSprite_create();
    st->game_bg2 = sfSprite_create();
    st->game_bg3 = sfSprite_create();
    st->game_bg_win = sfSprite_create();
    st->game_bg_lose = sfSprite_create();

    st->gp_run = sfSprite_create();
    st->gp_duck = sfSprite_create();
    st->gp_jump = sfSprite_create();

    st->ge_robot1 = sfSprite_create();
    st->ge_robot2 = sfSprite_create();
    st->ge_slug1 = sfSprite_create();
    st->ge_slug2 = sfSprite_create();
}

void create_score(st_s *st)
{
    st->score_text = sfText_create();
    st->gf_font = sfFont_createFromFile("assets/fonts/tm.ttf");
    sfText_setFont(st->score_text, st->gf_font);
    sfText_setColor(st->score_text, sfWhite);
    sfText_setCharacterSize(st->score_text, 42);
}

void init_game_assets(st_s *st)
{
    create_game_sprites(st);
    get_game_files(st);
    associate_game_files(st);

    create_score(st);
}
