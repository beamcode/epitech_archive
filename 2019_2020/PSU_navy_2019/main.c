/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

vg_s vg = {0, 0};

void print_help(void)
{
    const char *help = "USAGE\n"
    "     ./navy [first_player_pid] navy_positions\n"
    "DESCRIPTION\n"
    "     first_player_pid: only for the 2nd player. pid of the first player.\n"
    "     navy_positions: file representing the positions of the ships.\n";
    my_putstr(help);
}

char *get_map(int ac, char *av)
{
    int fd = open(av, O_RDONLY);
    struct stat buf;
    char *map;

    if (fd == -1)
        return (NULL);
    stat(av, &buf);
    map = malloc(sizeof(char) * (buf.st_size + 1));
    read(fd, map, buf.st_size);
    map[buf.st_size] = '\0';
    close(fd);
    return (map);
}

int create_maps(st_s *st, int ac, char *temp)
{
    char *map = get_map(ac, temp);

    if (map == NULL)
        return (84);
    if (check_map_error(map) == 84)
        return (84);
    if (generate_maps(st, map) == 84)
        return (84);
    return (0);
}

int open_game(st_s *st, int ac, char **av)
{
    if (ac == 2) {
        if (create_maps(st, ac, av[1]) == 84)
            return (84);
        execute_player_one(st);
    }
    if (ac == 3) {
        if (create_maps(st, ac, av[2]) == 84)
            return (84);
        execute_player_two(st, av[1]);
    }
    return (0);
}

int main(int ac, char **av)
{
    st_s *st = malloc(sizeof(st_s));
    st->win = 0;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' \
        && my_strlen(av[1]) == 2) {
        print_help();
        return (0);
    }
    if (ac < 2 || ac > 3)
        return (84);
    if (open_game(st, ac, av) == 84)
        return (84);
    return (0);
}