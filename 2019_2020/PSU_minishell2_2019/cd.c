/*
** EPITECH PROJECT, 2019
** builtin.c
** File description:
** yeee
*/

#include "my.h"

int slashes_pwd(void)
{
    char s[1000];
    char *current = getcwd(s, 1000);
    int slashes = 0;

    for (int a = 0; current[a] != '\0'; a++) {
        if (current[a] == '/') {
            slashes++;
        }
    }
    return (slashes);
}

int slashes_home(char *str)
{
    int slashes = 0;

    for (int a = 0; str[a] != '\0'; a++) {
        if (str[a] == '/')
            slashes++;
    }
    return (slashes);
}

int get_slashes(st_s *st)
{
    int a = 0;
    int b = 0;

    a = slashes_home(st->home_path);
    b = slashes_pwd();
    return (b - a);
}

void do_cd_dir(st_s *st)
{
    char s[500];

    if (st->noa > 2) {
        my_puterr("cd: Too many arguments.\n");
        return;
    }
    if (access(st->l_table[1], F_OK) == 0)
        chdir(st->l_table[1]);
    else {
        my_puterr(st->l_table[1]);
        my_puterr(": No such file or directory.\n");
    }
}

void do_cd(st_s *st)
{
    int total = 0;
    char s[500];

    set_home(st);
    if (st->noa == 2 && my_strcmp(st->l_table[1], "-") == 1) {
        do_cd_back(st);
        return;
    }
    if (st->noa == 1) {
        total = slashes_pwd();
        for (int a = 0; a < total; a++)
            chdir("..");
        chdir(st->home_path);
    }
    if (st->noa == 2) {
        update_cwd(st);
        do_cd_dir(st);
    }
}