/*
** EPITECH PROJECT, 2019
** sprite_settings.c
** File description:
** gets files
*/

#include "include/my.h"

void create_sprites(display_s *toto)
{
    toto->bg = sfSprite_create();
    toto->respawn = sfSprite_create();
    toto->death = sfSprite_create();
    toto->fish = sfSprite_create();
    toto->heart1 = sfSprite_create();
    toto->heart2 = sfSprite_create();
    toto->heart3 = sfSprite_create();
    toto->crosshair = sfSprite_create();
    toto->score_bg = sfSprite_create();
    toto->score_text = sfText_create();
    toto->text = sfText_create();
}

void set_files(files_s *files, display_s *toto)
{
    files->respawn_texture = sfTexture_createFromFile("RSR/respawn.png", NULL);
    files->death_texture = sfTexture_createFromFile("RSR/death.png", NULL);

    files->font = sfFont_createFromFile("RSR/arial.ttf");

    files->texture_bg = sfTexture_createFromFile("RSR/bg.png", NULL);
    files->texture_heart = sfTexture_createFromFile("RSR/heart.png", NULL);
    files->texture_fish = sfTexture_createFromFile("RSR/fish.png", NULL);
    files->texture_crosshair = sfTexture_createFromFile("RSR/cross.png", NULL);
    files->texture_score_bg = sfTexture_createFromFile("RSR/score_bg.png", NULL);

    toto->music1 = sfMusic_createFromFile("RSR/mc.ogg");
    toto->music2 = sfMusic_createFromFile("RSR/orb.ogg");
    toto->music3 = sfMusic_createFromFile("RSR/fail_sound.ogg");
}

void set_textures(display_s *toto, files_s *files)
{
    sfSprite_setTexture(toto->respawn, files->respawn_texture, sfTrue);
    sfSprite_setTexture(toto->death, files->death_texture, sfTrue);
    sfSprite_setTexture(toto->heart1, files->texture_heart, sfTrue);
    sfSprite_setTexture(toto->heart2, files->texture_heart, sfTrue);
    sfSprite_setTexture(toto->heart3, files->texture_heart, sfTrue);
    sfSprite_setTexture(toto->bg, files->texture_bg, sfTrue);
    sfSprite_setTexture(toto->fish, files->texture_fish, sfTrue);
    sfSprite_setTexture(toto->crosshair, files->texture_crosshair, sfTrue);
    sfSprite_setTexture(toto->score_bg, files->texture_score_bg, sfTrue);
    sfText_setFont(toto->score_text, files->font);
    sfText_setColor(toto->score_text, sfBlack);
    sfText_setCharacterSize(toto->score_text, 60);
    sfText_setString(toto->score_text, "0");



    sfText_setFont(toto->text, files->font);
    sfText_setColor(toto->text, sfBlack);
    sfText_setCharacterSize(toto->text, 42);
    sfText_setString(toto->text, "Score:");
    sfSprite_setTextureRect(toto->fish, toto->fish_rect);
}

void init_sprites(display_s *toto, files_s *files)
{
    set_files(files, toto);
    create_sprites(toto);
    set_textures(toto, files);
}