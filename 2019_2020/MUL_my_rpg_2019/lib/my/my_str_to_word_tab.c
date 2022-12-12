/*
** EPITECH PROJECT, 2020
** str_to_tab
** File description:
** ok
*/

#include "my.h"

char *cleaning_str_tab(char *str)
{
    int i = 0;

    for (; str[i] == '\t'; i++)
        str[i] = ' ';
    for (; str[i] != '\0'; i++) {
        for (; str[i] == '\t'; i++)
            str[i] = ' ';
    }
    return (str);
}

char *cleaning_str(char *str, char c)
{
    char *res = NULL;
    int x = 0;
    int i = 0;

    if ((res = malloc(sizeof(char) * my_strlen(str) + 1)) == NULL)
        return (NULL);
    for (; str[i] == c; i++);
    for (; str[i] != '\0'; i++) {
        while (str[i + 1] == c && str[i + 1] != '\0' && str[i] == c)
            i++;
        if (str[i] != '\n') {
            res[x] = str[i];
            x++;
        }
    }
    if (res[x - 1] == c) {
        res[x - 1] = '\0';
        return (res);
    }
    res[x] = '\0';
    return (res);
}

int count_lines(char *str, char c)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c && str[i + 1] == c)
            i++;
        if (str[i] == c)
            count++;
    }
    count++;
    return (count);
}

int size_of_word(char *str, char c)
{
    int count = 0;
    int i = 0;

    for (; str[i] != c && str[i] != '\0'; i++)
        count++;
    if (str[i] != '\0')
        i++;
    return (count);
}

char **my_str_to_word_tab(char *line, char c)
{
    char *str = cleaning_str(line, c);
    int lines = count_lines(str, c);
    char **array = NULL;
    int i = 0;
    int x = 0;
    int len = 0;

    array = malloc(sizeof(char *) * (lines + 1));
    for (; i < lines; i++) {
        len = size_of_word(&str[x], c);
        array[i] = malloc(sizeof(char) * len + 1);
        for (int j = 0; j < len; j++) {
            array[i][j] = str[x];
            x++;
        }
        x++;
        array[i][len] = '\0';
    }
    array[i] = NULL;
    free(str);
    return (array);
}
