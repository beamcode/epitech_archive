/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

int check_numeric(char *optarg)
{
    for (int a = 0; optarg[a] != '\0'; a++) {
        if (optarg[a] < '0' || optarg[a] > '9')
            return (84);
    }
    return (0);
}

int check_max_min(const char *str, char *optarg, st_s *st)
{
    if (strcmp(str, "imax") == 0) {
        if (check_numeric(optarg) == 84)
            return (84);
        st->imax = atoi(optarg);
    }
    if (strcmp(str, "imin") == 0) {
        if (check_numeric(optarg) == 84)
            return (84);
        st->imin = atoi(optarg);
    }
    return (0);
}

int detect_flag_error(int opt)
{
    switch (opt) {
        case '?':
            if (optopt == 0)
                printf("error\n");
            return (0);
        break;
        case ':':
            return (84);
            break;
    }
    return (0);
}

int get_options(int opt, int optt, char *optarg, st_s *st)
{
    switch (opt) {
        case 0:
            if (check_max_min(long_options[optt].name, optarg, st) == 84)
                return (84);
            break;
        case 'n':
            if (check_numeric(optarg) == 84)
                return (84);
            execute_sorry(st, optarg, 1);
            break;
        case 'p':
            if (check_numeric(optarg) == 84)
                return (84);
            execute_sorry(st, optarg, 2);
            break;
        case 'b':
            st->base = atoi(optarg);
            break;
    }
    return (0);
}

int get_flags(int ac, char **av, st_s *st)
{
    int opt = 0;
    int optt = 0;

    while ((opt = getopt_long_only(ac, av, "n:p:b:", long_options, \
    &optt)) != -1) {
        if (get_options(opt, optt, optarg, st) == 84)
            return (84);
        if (detect_flag_error(opt) == 84)
            return (84);
    }
    return (0);
}