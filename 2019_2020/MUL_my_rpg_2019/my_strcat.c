/*
** EPITECH PROJECT, 2020
** my_strcat
** File description:
** my_strcat
*/
#include "include/my.h"

char *my_strcat(char *buf, char *tmp)
{
    int i = my_strlen(buf);
    int x = 0;
    char *result = NULL;
    int r = 0;

    if (i == 0)
        return (tmp);
    result = malloc(sizeof(char) * i + my_strlen(tmp) + 1);
    for ( ; buf[r] != '\0'; r++)
        result[r] = buf[r];
    if (tmp != NULL) {
        while (tmp[x] != '\0') {
            result[r] = tmp[x];
            x++;
            r++;
        }
        result[r] = '\0';
        return (result);
    }
    result[r] = '\0';
    return (result);
}
