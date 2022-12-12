/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

int check_possible(char *map, int a)
{
    if (map[a + 2] != map[a + 5] && map[a + 3] != map[a + 6])
        return (1);
    if (map[a + 2] != map[a + 5]) {
        if ((map[a + 5] - map[a + 2] + 1 + 48) != map[a])
            return (84);
    }
    else {
        if ((map[a + 6] - map[a + 3] + 1 + 48) != map[a])
            return (84);
    }
    if (map[a] < '2' || map[a] > '5')
        return (84);
    if (a == 24)
        return (0);
    if (check_possible(map, (a + 8)) == 1)
        return (84);
    return (0);
}

int check_size(char *map, int a)
{
    for (int c = 0; c < 32; c += 8) {
        if (c == a)
            continue;
        if (map[a] == map[c])
            return (84);
    }
    if (a == 24)
        return (0);
    if (check_size(map, (a + 8)) == 84)
        return (84);
    return (0);
}

int check_syntax(char *map, int a)
{
    if ((map[a] < '2' || map[a] > '5') || map[a + 1] != ':')
        return (84);
    if ((map[a + 2] < 'A' || map[a + 2] > 'H') || (map[a + 3] < '0' || \
        map[a + 3] > '9') || map[a + 4] != ':')
        return (84);
    if ((map[a + 5] < 'A' || map[a + 5] > 'H') || (map[a + 6] < '0' || \
        map[a + 6] > '9'))
        return (84);
    if (a == 24)
        return (0);
    if (check_syntax(map, (a + 8)) == 84)
        return (84);
    return (0);
}

int check_map_error(char *map)
{
    if (my_strlen(map) < 31 || my_strlen(map) > 32)
        return (84);
    if (check_syntax(map, 0) == 84)
        return (84);
    if (check_size(map, 0) == 84)
        return (84);
    if (check_possible(map, 0) == 84)
        return (84);
    return (0);
}