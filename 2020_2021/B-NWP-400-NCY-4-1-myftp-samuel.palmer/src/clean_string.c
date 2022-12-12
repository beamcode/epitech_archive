/*
** EPITECH PROJECT, 2021
** clean_string.c
** File description:
** clean_string
*/

#include "../include/my_ftp.h"

bool check_space(char c)
{
    if (c == ' ' || c == '\t')
        return (true);
    return (false);
}

char *clean_str(char *str)
{
    char *tmp = malloc(sizeof(char) * strlen(str) + 1);
    int i = 0;
    int j = 0;

    for (; check_space(str[i]); i++);
    for (; str[i] != '\0'; tmp[j] = ' ', j++) {
        for (; str[i] != '\0' && !check_space(str[i]); j++, i++)
            tmp[j] = str[i];
        for (; str[i] != '\0' && check_space(str[i]); i++);
    }
    tmp[j - 1] = '\0';
    tmp[strlen(tmp) - 1] = '\0';
    return (tmp);
}
