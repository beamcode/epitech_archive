/*
** EPITECH PROJECT, 2021
** check_inputs.c
** File description:
** check_inputs
*/

#include "../include/my_ftp.h"

bool is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (!(str[i] <= '9' && str[i] >= '0'))
            return (true);
    return (false);
}

bool check_dir(int ac, char **av)
{
    DIR* dir;

    if (ac == 3) {
        dir = opendir(av[2]);
        if (dir == NULL) {
            fprintf(stderr, INVALID_DIR);
            return (true);
        }
        closedir(dir);
        if (is_number(av[1]) || atoi(av[1]) < 1) {
            fprintf(stderr, INVALID_PORT);
            return (true);
        }
    }
    return (false);
}

bool check_args(int ac, char **av)
{
    if (ac < 2 || ac > 3) {
        printf("HELP: type /help for usage.\n");
        return (true);
    }
    if (ac == 2 && !strcmp(av[1], "-help")) {
        printf("USAGE: ./myftp port path\n");
        printf("\tport is the port number on which \
            the server socket listens\n");
        printf("\tpath is the path to the home directory \
            for the Anonymous user\n");
        return (true);
    }
    if (ac != 3) {
        printf("HELP: type /help for usage.\n");
        return (true);
    }
    if (check_dir(ac, av))
        return (true);
    return (false);
}