/*
** EPITECH PROJECT, 2019
** my_strconcat.c
** File description:
** concatinate 2 string and returns new string
*/

#include "my_lib.h"

char *my_strconcat(char *dest, char *src)
{
    char *temp = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
    int a = 0;

    for (; dest[a] != '\0'; a++)
        temp[a] = dest[a];
    for (int b = 0; src[b] != '\0'; b++) {
        temp[a] = src[b];
        a++;
    }
    temp[a] = '\0';
    return (temp);
}