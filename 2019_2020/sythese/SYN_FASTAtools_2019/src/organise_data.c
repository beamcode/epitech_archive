/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "../include/my.h"

char **copy_to_new(char **str)
{
    char **new = NULL;
    int a = 0;
    int b = 0;

    for (int t = 0; str[t]; t++) {
        if (strcmp(str[t], "\0") != 0)
            a++;
    }
    new = malloc(sizeof(char *) * (a + 1));
    for (int t = 0; str[t]; t++) {
        if (strcmp(str[t], "\0") != 0) {
            new[b] = malloc(sizeof(char) * (strlen(str[t]) + 1));
            new[b] = strdup(str[t]);
            b++;
        }
    }
    new[b] = NULL;
    for (b = 0; str[b]; b++)
        free(str[b]);
    return (new);
}

char *my_strcat_dup(const char *str1, const char *str2)
{
    int str1_len;
    int str2_len;
    char *new_str;

    if (str1 == NULL || str2 == NULL)
        return (NULL);
    str1_len = strlen(str1);
    str2_len = strlen(str2);
    new_str = malloc(str1_len + str2_len + 1);
    if (new_str == NULL)
        return (NULL);
    memcpy(new_str, str1, str1_len);
    memcpy(new_str + str1_len, str2, str2_len + 1);
    return (new_str);
}

char **organize_data(char **str)
{
    for (int a = 0, b = 0; str[a]; a++) {
        if (strchr(str[a], '>') != NULL) {
            a++;
            b = a;
            continue;
        }
        str[b] = my_strcat_dup(str[b], str[a]);
        str[a] = strdup("\0");
    }
    return (copy_to_new(str));
}