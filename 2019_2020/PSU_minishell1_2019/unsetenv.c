/*
** EPITECH PROJECT, 2019
** builtin.c
** File description:
** yeee
*/

#include "my.h"
static int check_array(st_s *st, int av)
{
    int line = -1;
    char *temp = NULL;

    for (int y = 0; st->env[y] != NULL; y++) {
        line = y;
        for (int x = 0; st->env[y][x] != 61; x++) {
            if (st->env[y][x] != st->l_table[av][x])
                line = -1;
            if ((st->l_table[av][x + 1] == '\0' && st->env[y][x + 1] != 61) ||
                (st->l_table[av][x + 1] == 61 && st->env[y][x + 1] == 61))
                line = -1;
        }
        if (line != -1)
            break;
    }
    return (line);
}

static void remove_line(st_s *st, int line)
{
    int x = 0;
    char **temp;

    for (; x != line; x++);
    for (; st->env[x]; x++)
        st->env[x] = st->env[x + 1];
    temp = my_dup_array(st->env, 0);
    free(st->env);
    st->env = temp;
}

static void check_line(st_s *st)
{
    int line = 0;

    for (int x = 1; st->l_table[x]; x++) {
        line = check_array(st, x);
        if (line == -1)
            continue;
        else
            remove_line(st, line);
    }
}

void do_unsetenv(st_s *st)
{
    for (st->noa = 0; st->l_table[st->noa] != NULL; st->noa++);
    if (st->noa == 1) {
        my_puterr("unsetenv: Too few arguments.\n");
        return;
    }
    else
        check_line(st);
}