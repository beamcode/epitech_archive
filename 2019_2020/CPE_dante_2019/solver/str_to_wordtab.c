/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

void fill_array(char *string, char **temp, char sep)
{
    int y = 0;
    int x = 0;

    for (int t = 0; string[t] != '\0'; t++) {
        if (string[t] == sep) {
            temp[y][x] = '\0';
            y++;
            x = 0;
            continue;
        }
        temp[y][x] = string[t];
        x++;
    }
    temp[y][x] = '\0';
    temp[y + 1] = NULL;
}

char **str_to_wordtab(char *string, char sep)
{
    char **temp = NULL;
    int rows = 1;
    int colums = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == sep)
            rows++;
    }
    temp = malloc(sizeof(char *) * (rows + 1));
    rows = 0;
    for (int i = 0; string[i] != '\0'; i++, colums++) {
        if (string[i] == sep) {
            temp[rows] = malloc(sizeof(char) * (colums + 1));
            rows++;
            colums = -1;
        }
    }
    temp[rows] = malloc(sizeof(char) * (colums + 1));
    fill_array(string, temp, sep);
    return (temp);
}