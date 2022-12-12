/*
** EPITECH PROJECT, 2020
** bombyx
** File description:
** bombyx.c
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++);
    return a;
}

int first_case(char **argv)
{
    double n = atof(argv[1]);
    double x = n;
    double k = atof(argv[2]);

    if (k < 1 || k > 4)
        return (84);
    for (int i = 1; i <= 100; i++) {
        printf("%d %.2f\n", i, x);
        x = k * x * ((1000.0 - x) / 1000.0);
    }
    return (0);
}

int second_case(char **argv)
{
    double k = 1;
    double n = atof(argv[1]);
    double x = n;
    double i0 = atof(argv[2]);
    double i = 1;
    double i1 = atof(argv[3]);

    for (k = 1; k <= 4; k += 0.01) {
        for (i = 1; i <= i1; i++) {
            for (; i < i0; i++) {
                x = k * x * ((1000.0 - x) / 1000.0);
            }
            printf("%.2f %.2f\n", k, x);
            x = k * x * ((1000.0 - x) / 1000.0);
        }            
    }
    return (0);
}

int check_error(int ac, char **av)
{
    if (ac < 3 || ac > 4)
        return (84);
    for (int y = 1; y < ac; y++) {
        for (int x = 0; av[y][x] != '\0'; x++) {
            if (av[y][x] == '.')
                continue;
            if (av[y][x] < '0' || av[y][x] > '9')
                return (84);
        }
    }
    //printf("%c\n", av[2][0]);
    //if (my_strlen(av[2]) != 1 || av[2][0] < '1' || av[2][0] > '4')
    //    return (84);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h' && my_strlen(argv[1]) == 2) {
        printf("USAGE\n    ./106bombyx n [k | i0 i1]\n\n"               \
               "DESCRIPTION\n    n       number of first generation"    \
               " individuals\n    k       growth rate from 1 to 4\n"    \
               "    i0      initial generation (included)\n    i1      " \
               "final generation (included)\n");
        return (0);
    }
    if (check_error(argc, argv) == 84)
        return (84);
    if (argc == 3) {
        if (first_case(argv) == 84)
            return (84);
    }
    if (argc == 4)
        second_case(argv);
    return (0);
}