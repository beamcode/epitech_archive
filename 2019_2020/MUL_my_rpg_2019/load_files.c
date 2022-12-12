/*
** EPITECH PROJECT, 2020
** load files
** File description:
** load files
*/
#include "include/my.h"

void save_item(game_t *game, char *save, char *file)
{
    char *tmp = NULL;
    int fd;

    for (item_t *t = game->item; t->mark != 70; t = t->next) {
        if (t->sprite && t->get == 1) {
            tmp = my_itoa(t->mark);
            save = my_strcat(save, tmp);
            save = my_strcat(save, " ");
        }
    }
    free(tmp);
    fd = open(file, O_WRONLY | O_CREAT);
    if (fd != -1) {
        write(fd, save, my_strlen(save));
        free(save);
        close(fd);
    }
}

void save_file(char *file, game_t *game)
{
    char *save = NULL;
    char *x = save_val_first(game);

    save = my_strcat(save, x);
    x = save_val_sec(game);
    save = my_strcat(save, x);
    x = save_val_three(game);
    save = my_strcat(save, x);
    x = save_val_four(game);
    save = my_strcat(save, x);
    x = save_val_five(game);
    save = my_strcat(save, x);
    x = save_val_six(game);
    save = my_strcat(save, x);
    x = save_val_seven(game);
    save = my_strcat(save, x);
    x = save_val_eight(game);
    save = my_strcat(save, x);
    free(x);
    save_item(game, save, file);
}

void save_game(game_t *game)
{
    save_file("scripts/save_var", game);
}

int get_save(char *file, game_t *game)
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
    }
    apply_save(tab, game);
    free(buffer);
    fclose(fp);
    if (ret == -1)
        return (ret);
    else
        return (0);
}

int load_file(game_t *game, int tmp)
{
    if (tmp == 0) {
        if (get_save("scripts/save_var", game) == -1) {
            my_puterr("bad file\n");
            return (84);
        }
    }
    if (tmp == 1) {
        if (get_save("scripts/new_game", game) == -1) {
            my_puterr("bad file\n");
            return (84);
        }
    }
    return (0);
}
