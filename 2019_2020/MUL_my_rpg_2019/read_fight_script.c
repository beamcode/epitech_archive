/*
** EPITECH PROJECT, 2020
** read_script
** File description:
** ok
*/

#include "include/my.h"

hero_t *add_hero(hero_t *hero)
{
    hero->pos.x = 1500;
    hero->pos.y = 600;
    hero->rec.top = 0;
    hero->rec.left = 0;
    hero->rec.width = 90;
    hero->rec.height = 50;
    hero->texture = sfTexture_createFromFile("fight/player.png", NULL);
    hero->sprite = sfSprite_create();
    sfSprite_setTexture(hero->sprite, hero->texture, sfTrue);
    sfSprite_setPosition(hero->sprite, hero->pos);
    return (hero);
}

enemy_t *add_ene(char **tab, enemy_t *enemy)
{
    enemy_t *new = malloc(sizeof(enemy_t));

    new->sprite = sfSprite_create();
    new->texture = sfTexture_createFromFile(tab[5], NULL);
    sfSprite_setTexture(new->sprite, new->texture, sfTrue);
    new->pos.x = my_atoi(tab[1]);
    new->pos.y = my_atoi(tab[2]);
    new->mark = my_atoi(tab[6]);
    sfSprite_setPosition(new->sprite, new->pos);
    if (enemy == NULL)
        return (enemy);
    else
        for (; enemy->next != NULL; enemy = enemy->next);
    enemy->next = new;
    new->next = NULL;
    return (enemy);
}

but_t *add_but(char **tab, but_t *button)
{
    but_t *new = malloc(sizeof(but_t));

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

int put_fight_in_struct(char **tab, g_t *game)
{
    add_hero(game->hero);
    add_text(game);
    if (tab[0][0] == 'K')
        add_but(tab, game->but);
    if (tab[0][0] == 'N')
        add_ene(tab, game->enemy);
    if (tab[0][0] != 'N' && tab[0][0] != 'K')
        return (-1);
    return (0);
}

int get_fight_map(char *file, g_t *game)
{
    char *buffer = NULL;
    size_t len = 0;
    FILE *fp;
    char **tab = NULL;
    int ret = 0;

    if ((fp = fopen(file, "r")) == NULL)
        return (-1);
    while ((ret = (getline(&buffer, &len, fp))) > 0) {
        buffer = cleaning_str_tab(buffer);
        tab = my_str_to_word_tab(buffer, ' ');
        if ((put_fight_in_struct(tab, game)) == -1)
            return (-1);
    }
    fclose(fp);
    if (ret == -1)
        return (ret);
    else
        return (0);
}
