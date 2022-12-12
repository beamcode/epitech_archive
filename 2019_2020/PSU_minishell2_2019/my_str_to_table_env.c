/*
** EPITECH PROJECT, 2019
** str_to_wt_inp.c
** File description:
** yeee
*/

#include "my.h"

static char **malloc_rows(char **temp, char *str)
{
    int dots = 0;

    for (int a = 0; str[a] != '\0' ;a++) {
        if (str[a] == ':')
            dots++;
    }
    temp = malloc(sizeof(char *) * (dots + 2));
    if (temp == NULL)
        return (NULL);
    return (temp);
}

static char **malloc_table(char *str)
{
    int dots = 0;
    int count = 0;
    char **temp;

    temp = malloc_rows(temp, str);
    if (temp == NULL)
        return (NULL);
    for (int a = 0; str[a] != '\0' ;a++) {
        if (str[a + 1] == '\0')
            temp[dots] = malloc(sizeof(char) * (count + 3));
        if (str[a] == ':') {
            temp[dots] = malloc(sizeof(char) * (count + 2));
            count = 0;
            dots++;
            continue;
        }
        count++;
    }
    return (temp);
}

void fill_table(char **temp, char *str)
{
    int dots = 0;
    int b = 0;

    for (int a = 5; str[a] != '\0' ;a++) {
        if (str[a + 1] == '\0') {
            temp[dots][b] = str[a];
            temp[dots][b + 1] = '/';
            temp[dots][b + 2] = '\0';
            continue;
        }
        if (str[a] == ':') {
            temp[dots][b] = '/';
            temp[dots][b + 1] = '\0';
            dots++;
            b = 0;
            continue;
        }
        temp[dots][b] = str[a];
        b++;
    }
}

char **get_wordtab_env(char **str)
{
    int y = 0;
    char **temp;

    while (str[y][0] != 'P' && str[y][1] != 'A' && str[y][2] != 'T')
        y++;
    temp = malloc_table(str[y]);
    if (temp == NULL)
        return (NULL);
    fill_table(temp, str[y]);
    return (temp);
}