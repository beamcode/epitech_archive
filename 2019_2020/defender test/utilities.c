/*
** EPITECH PROJECT, 2019
** clock_func.c
** File description:
** yes
*/

#include "include/my.h"

char *get_config(char *av)
{
    int fd = open(av, O_RDONLY);
    struct stat buf;
    char *map = NULL;

    if (fd == -1)
        return (NULL);
    stat(av, &buf);
    map = malloc(sizeof(char) * (buf.st_size + 1));
    if (map == NULL)
        return (NULL);
    if (read(fd, map, buf.st_size) == -1)
        return (NULL);
    map[buf.st_size] = '\0';
    close(fd);
    return (map);
}

sfVector2f pos(double x, double y)
{
    sfVector2f vector;

    vector.x = x;
    vector.y = y;
    return (vector);
}

sfVector2f pos_mouse(st_s *st, sfRenderWindow *window)
{
    sfVector2f vector1;

    //printf("x = %d\ny = %d\n\n", st->pos_cursor.x, st->pos_cursor.y);
    vector1.x = st->pos_cursor.x - 2;
    vector1.y = st->pos_cursor.y - 2;
    return (vector1);
}