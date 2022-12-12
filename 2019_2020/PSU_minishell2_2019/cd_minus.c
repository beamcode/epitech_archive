/*
** EPITECH PROJECT, 2019
** builtin.c
** File description:
** yeee
*/

#include "my.h"
static int slashes_count(void)
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

static char *fetch_cwd(st_s *st)
{
    char *s = malloc(sizeof(char) * 500);
    char *temp = NULL;

    if (s == NULL)
        return (NULL);
    temp = getcwd(s, 500);
    return (temp);
}

void do_cd_back(st_s *st)
{
    int total = slashes_count();
    char *temp = fetch_cwd(st);

    for (int a = 0; a < total; a++)
        chdir("..");
    if (access(st->current, F_OK) == 0)
        chdir(st->current);
    else {
        my_puterr(st->l_table[1]);
        my_puterr(": No such file or directory.\n");
        return;
    }
    st->current = temp;
}