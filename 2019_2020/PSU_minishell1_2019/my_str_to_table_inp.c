/*
** EPITECH PROJECT, 2019
** str_to_wt_env.c
** File description:
** yeee
*/

#include "my.h"

static char *clean_string(char *str)
{
    int b = 0;
    int a = 0;
    char *temp = malloc(sizeof(char) * (my_strlen(str) + 1));

    if (temp == NULL)
        return (NULL);
    for (; str[a] == '\t' || str[a] == ' '; a++);
    for (int space = 0; str[a] != '\0'; a++) {
        if (str[a] == '\t' || str[a] == ' ') {
            temp[b] = ' ';
            b++;
            continue;
        }
        temp[b] = str[a];
        b++;
    }
    temp[b] = '\0';
    return (temp);
}

static int count_cols(char *str)
{
    int dots = 0;

    for (int a = 0; str[a] != '\0' ;a++) {
        if (str[a] == ' ' || str[a + 1] == '\0')
            dots++;
    }
    return (dots);
}

static char **malloc_table(char *str)
{
    int dots = 0;
    char **temp = malloc(sizeof(char *) * (count_cols(str) + 1));

    if (temp == NULL)
        return (NULL);
    for (int a = 0, count = 0, cols = 0; str[a] != '\0' ;a++) {
        if (str[a] == ' ' || str[a + 1] == '\0') {
            temp[cols] = malloc(sizeof(char) * (count + 2));
            if (temp[cols] == NULL)
                return (NULL);
            count = 0;
            cols++;
            continue;
        }
        count++;
    }
    return (temp);
}

static void fill_table(char *cleaned, char **temp)
{
    for (int a = 0, b = 0, dots = 0; cleaned[a] != '\0' ;a++) {
        if (cleaned[a] == ' ') {
            temp[dots][b] = '\0';
            dots++;
            b = 0;
            continue;
        }
        if (cleaned[a + 1] == '\0') {
            temp[dots][b] = cleaned[a];
            temp[dots][b + 1] = '\0';
            continue;
        }
        temp[dots][b] = cleaned[a];
        b++;
    }
}

char **get_wordtab_inp(char *str)
{
    char *cleaned = clean_string(str);
    char **temp = malloc_table(cleaned);

    fill_table(cleaned, temp);
    return (temp);
}