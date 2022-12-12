/*
** EPITECH PROJECT, 2019
** builtin.c
** File description:
** yeee
*/

#include "my.h"

static int check_setenv(st_s *st)
{
    if (st->noa > 3) {
        my_puterr("setenv: Too many arguments.\n");
        return (1);
    }
    for (int x = 0; st->l_table[1][x] != '\0'; x++) {
        if ((st->l_table[1][x] < 'a' || st->l_table[1][x] > 'x') &&
            (st->l_table[1][x] < 'A' || st->l_table[1][x] > 'X') &&
            (st->l_table[1][x] < '0' || st->l_table[1][x] > '9')) {
            my_puterr("setenv: Variable name must contain alphanumeric");
            my_puterr(" characters.\n");
            return (1);
        }
    }
    return (0);
}

static int check_array(st_s *st)
{
    int line = -1;

    for (int y = 0; st->env[y]; y++) {
        line = y;
        for (int x = 0; st->env[y][x] != 61; x++) {
            if (st->env[y][x] != st->l_table[1][x])
                line = -1;
            if (st->l_table[1][x + 1] == '\0' && st->env[y][x + 1] != 61)
                line = -1;
        }
        if (line != -1)
            break;
    }
    return (line);
}

static void modify_line(st_s *st, int line)
{
    char *temp = my_strconcat(st->l_table[1], "=");

    if (st->noa > 2)
        st->env[line] = my_strconcat(temp, st->l_table[2]);
    else
        st->env[line] = temp;
}

static void modify_array(st_s *st)
{
    int line = check_array(st);
    int a = 0;

    if (line == -1) {
        for (;st->env[a]; a++);
        st->env = my_dup_array(st->env, 1);
        modify_line(st, a);
    }
    else
        modify_line(st, line);
}

void do_setenv(st_s *st)
{
    for (st->noa = 0; st->l_table[st->noa]; st->noa++);
    if (st->noa == 1) {
        my_putarray(st->env);
        return;
    }
    if (check_setenv(st) == 1)
        return;
    else
        modify_array(st);
}