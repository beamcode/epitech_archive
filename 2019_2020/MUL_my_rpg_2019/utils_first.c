/*
** EPITECH PROJECT, 2020
** utils script
** File description:
** ok
*/

#include "include/my.h"

void hero_take_damage(int attack, lifebar_t *lifebar)
{
    lifebar->size.x -= attack + 15;
    sfRectangleShape_setSize(lifebar->rect_s, lifebar->size);
}

void add_text(g_t *game)
{
    sfFont *font = sfFont_createFromFile("fight/arial.ttf");

    game->text_c = sfText_create();
    sfText_setFont(game->text_c, font);
    sfText_setCharacterSize(game->text_c, 75);
    sfText_setColor(game->text_c, sfWhite);
    sfText_setString(game->text_c, "Loading");
    sfText_setPosition(game->text_c,
    (sfVector2f) {1920 / 2 - 140, 1080 / 2 - 300});
}

void draw_background(g_t *game, background_t back)
{
    sfSprite_setTexture(back.spritemap, back.texturemap, sfTrue);
    sfRenderWindow_drawSprite(game->window, back.spritemap, NULL);
}

background_t init_back(void)
{
    background_t back;

    back.texturemap = sfTexture_createFromFile("fight/backkk.png", NULL);
    back.spritemap = sfSprite_create();
    return (back);
}
