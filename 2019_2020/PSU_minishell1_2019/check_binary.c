/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeees
*/

#include "my.h"

static char *fetch_now(void)
{
    char *s = malloc(sizeof(char) * 500);
    char *temp = NULL;

    if (s == NULL)
        return (NULL);
    temp = getcwd(s, 500);
    return (temp);
}

int check_binary(st_s *st)
{
    char *name;

    if (st->l_table[0][0] == '.' && st->l_table[0][1] == '/') {
        name = malloc(sizeof(char) * my_strlen(st->l_table[0]) - 2);
        if (name == NULL)
            return (0);
        for (int a = 2, x = 0; st->l_table[0][a] != '\0'; a++) {
            name[x] = st->l_table[0][a];
            x++;
        }
        st->binary_path = my_strconcat(fetch_now(), "/");
        st->binary_path = my_strconcat(st->binary_path, name);
        if (access(name, F_OK) == -1)
            return (0);
        return (1);
    }
    return (0);
}