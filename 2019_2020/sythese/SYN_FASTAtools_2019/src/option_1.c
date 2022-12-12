/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "../include/my.h"

int check_illegal(char c)
{
    if (c == 'a' || c == 't' || c == 'g' || c == 'c' || c == 'n')
        return (0);
    if (c == 'A' || c == 'T' || c == 'G' || c == 'C' || c == 'N')
        return (0);
    return (1);
}

char *remove_illegal(char *input)
{
    char *tmp = input;
    int j = 0;

    for (int i = 0; input[i] != '\0'; i++, j++) {
        if (check_illegal(input[i]) == 0)
            tmp[j] = input[i];
        else
            j--;
    }
    tmp[j] = '\0';
    tmp = strdup(input);
    return (tmp);
}

void process_one(char **str)
{
    for (int a = 0; str[a] != NULL; a++) {
        if (strchr(str[a], '>') != NULL)
            continue;
        remove_illegal(str[a]);
        for (int b = 0; str[a][b] != '\0'; b++) {
            if (str[a][b] >= 'a' && str[a][b] <= 'z')
                str[a][b] -= 32;
        }
    }
}

void do_one(char **str)
{
    process_one(str);
    my_putarray(str);
}