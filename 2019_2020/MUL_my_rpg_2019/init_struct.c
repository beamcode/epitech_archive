/*
** EPITECH PROJECT, 2020
** init
** File description:
** init
*/
#include "include/my.h"

text_t *get_text(void)
{
    text_t *text = malloc(sizeof(text_t));

    if (text != NULL) {
        create_text(text);
        text->font = sfFont_createFromFile("ressources/font2.ttf");
        init_text(text);
    }
    return (text);
}

int put_map_in_struct(char **tab, game_t *game)
{
    if (tab[0][0] == 'B')
        add_button(tab, game->button);
    if (tab[0][0] == 'E')
        add_mob(tab, game->mob);
    if (tab[0][0] == 'I')
        add_item(tab, game->item);
    if (tab[0][0] == 'M')
        add_map(tab, game->map);
    if (tab[0][0] == 'O')
        add_obs(tab, game->map->obs);
    if (tab[0][0] == 'P')
        add_pnj(tab, game->pnj);
    if (tab[0][0] == 'N')
        add_info(tab, game->info);
    if (tab[0][0] != 'B' && tab[0][0] != 'E' && tab[0][0] != 'I'
        && tab[0][0] != 'M' && tab[0][0] != 'O' && tab[0][0] != 'P'
        && tab[0][0] != 'N')
        return (-1);
    free_array(tab);
    return (0);
}

int get_map(char *file, game_t *game)
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
        if ((put_map_in_struct(tab, game)) == -1)
            return (-1);
    }
    free(buffer);
    fclose(fp);
    if (ret == -1)
        return (ret);
    else
        return (0);
}

game_t *fill_my_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (game != NULL) {
        game->button = fill_my_button();
        game->mob = fill_my_mob();
        game->pnj = fill_my_pnj();
        game->item = fill_my_item();
        game->player = get_player();
        game->stat = get_item_stat();
        game->text = get_text();
        game->music = get_music();
        game->map = fill_game_map();
        game->info = fill_game_info();
        game->quest = fill_quest();
        game->map->obs = fill_game_obstacles();
    }
    return (game);
}
