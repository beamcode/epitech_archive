/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

int get_charpos(char **map, char a)
{
    int x = 0;

    for (; map[0][x] != a; x++);
    return (x);
}

int apply_map_settings(st_s *st, char *map, int a)
{
    if (map[a + 2] != map[a + 5]) {
        for (int b = get_charpos(st->map, map[a + 2]), n = map[a + 2] - 65; \
            n <= map[a + 5] - 65; n++, b += 2) {
            if (st->map[map[a + 3] - 47][b] != '.')
                return (84);
            st->map[map[a + 3] - 47][b] = map[a];
        }
    }
    else {
        for (int n = map[a + 3] - 47; n <= map[a + 6] - 47; n++) {
            if (st->map[n][get_charpos(st->map, map[a + 2])] != '.')
                return (84);
            st->map[n][get_charpos(st->map, map[a + 2])] = map[a];
        }
    }
    if (a == 24)
        return (0);
    if (apply_map_settings(st, map, a + 8) == 84)
        return (84);
    return (0);
}

int create_template(char **map, int x, int y)
{
    map[0] = " |A B C D E F G H\0";
    map[1] = "-+---------------\0";
    for (int a = 2, b = 0; a < y; map[a][1] = '|', a++, b++) {
        map[a][0] = 49 + b;
        for (int c = 2; c < x; map[a][c + 1] = ' ', c += 2)
            map[a][c] = '.';
        map[a][x] = '\0';
    }
    return (0);
}

int generate_maps(st_s *st, char *map)
{
    int x = 17;
    int y = 10;

    st->map = malloc(sizeof(char *) * y + 1);
    st->enemy_map = malloc(sizeof(char *) * y + 1);
    for (int a = 0; a < y; a++)
        st->map[a] = malloc(sizeof(char) * x + 1);
    for (int a = 0; a < y; a++)
        st->enemy_map[a] = malloc(sizeof(char) * x + 1);

    create_template(st->map, x, y);
    create_template(st->enemy_map, x, y);
    if (apply_map_settings(st, map, 0) == 84)
        return (84);
    return (0);
}