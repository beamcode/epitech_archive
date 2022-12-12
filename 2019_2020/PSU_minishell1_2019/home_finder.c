/*
** EPITECH PROJECT, 2019
** builtin.c
** File description:
** yeee
*/

#include "my.h"

int get_home(st_s *st)
{
    int line = -1;
    char *home = my_strdup("HOME=\0");

    for (int y = 0; st->env[y]; y++) {
        line = y;
        for (int x = 0; home[x] != '\0'; x++) {
            if (st->env[y][x] != home[x])
                line = -1;
        }
        if (line != -1)
            break;
    }
    return (line);
}

char *get_home_path(st_s *st, int line)
{
    int x = 0;
    char *home = malloc(sizeof(char) * (my_strlen(st->env[line]) - 5));

    if (home == NULL)
        return (NULL);
    for (int a = 5; st->env[line][a] != '\0'; a++) {
        home[x] = st->env[line][a];
        x++;
    }
    home[x] = '\0';
    if (my_strcmp(st->home_path, home) == 0)
        st->home_update = 1;
    return (home);
}

void set_home(st_s *st)
{
    int line = get_home(st);

    st->home_update = 0;
    if (line == -1)
        return;
    else
        st->home_path = get_home_path(st, line);
}