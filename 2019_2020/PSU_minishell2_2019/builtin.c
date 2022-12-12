/*
** EPITECH PROJECT, 2019
** builtin.c
** File description:
** yeee
*/

#include "my.h"

void update_cwd(st_s *st)
{
    char *s = malloc(sizeof(char) * 500);

    if (my_strcmp(st->current, getcwd(s, 500)) == 0)
        st->current = getcwd(s, 500);
}

static void check_all(st_s *st)
{
    if (my_strcmp(st->l_table[0], "exit") == 1) {
        my_putstr("exit\n");
        exit(0);
    }
    if (my_strcmp(st->l_table[0], "cd") == 1) {
        st->builtin = 1;
        do_cd(st);
    }
    if (my_strcmp(st->l_table[0], "setenv") == 1) {
        st->builtin = 1;
        do_setenv(st);
    }
    if (my_strcmp(st->l_table[0], "unsetenv") == 1) {
        st->builtin = 1;
        do_unsetenv(st);
    }
    if (my_strcmp(st->l_table[0], "env") == 1) {
        st->builtin = 1;
        my_putarray(st->env);
    }
}

void check_builtin(st_s *st)
{
    st->builtin = 0;
    check_all(st);
}