/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

char *open_file(char *av)
{
    int fd = open(av, O_RDONLY);
    struct stat buf;
    char *map = NULL;

    if (fd == -1)
        return (NULL);
    stat(av, &buf);
    map = malloc(sizeof(char) * (buf.st_size + 1));
    read(fd, map, buf.st_size);
    map[buf.st_size] = '\0';
    close(fd);
    return (map);
}

int check_errors(char **temp)
{
    int rows = 0;
    int colums = 0;
    int len = 0;

    for (; temp[rows] != NULL; rows++);
    for (; temp[0][len] != '\0'; len++);
    if (rows == 0)
        return (84);
    for (int a = 0, count = 0; a < (rows - 1); a++, count = 0) {
        for (; temp[a][count] != '\0'; count++);
        if (count != len)
            return (84);
    }
    return (0);
}

int check_string(char *temp)
{
    if (temp[0] == '\0' || temp[0] == '\n')
        return (84);
    for (int y = 0; temp[y] != '\0'; y++) {
        if (temp[y] == 'X' || temp[y] == '*'
        || temp[y] == '\n' || temp[y] == '\0')
            continue;
        return (84);
    }
    return (0);
}

char **create_map(char *av)
{
    char *string = open_file(av);
    char **temp = NULL;

    if (string == NULL)
        return (NULL);
    if (check_string(string) == 84)
        return (NULL);
    temp = str_to_wordtab(string, '\n');
    if (check_errors(temp) == 84)
        return (NULL);
    alarm(4);
    return (temp);
}