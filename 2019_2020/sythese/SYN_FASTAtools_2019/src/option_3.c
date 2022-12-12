/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "../include/my.h"

char *my_revstr(char *str)
{
    char a;
    int i = 0;
    int len = strlen(str);

    while (i < len / 2) {
        a = *(str + i);
        *(str + i) = *(str + len - i - 1);
        *(str + len - i - 1) = a;
        ++i;
    }
    return (str);
}

void process_three(char **str)
{
    char k;

    for (int a = 0; str[a]; a++) {
        if (strchr(str[a], '>') != NULL)
            continue;
        for (int b = 0; str[a][b] != '\0'; b++) {
            k = str[a][b];
            str[a][b] = k == 'A' ? 'T' : k == 'T' ? 'A' : \
            k == 'G' ? 'C' : k == 'C' ? 'G' : k;
        }
        my_revstr(str[a]);
    }
}

void do_three(char **str)
{
    process_one(str);
    process_three(str);
    my_putarray(str);
}