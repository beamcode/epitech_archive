/*
** EPITECH PROJECT, 2019
** fozzbazz.c
** File description:
**
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int check_casses(int a, int b)
{
    if (b < a)
        return (84);
    return (0);
}

int check_errors(int ac, char** av)
{
    int a = 0;

    if (ac != 3)
        return (84);
    while (av[1][a]) {
        if (av[1][a] > 57 || av[1][a] < 48)
	    return (84);
	a++;
    }
    a = 0;
    while (av[2][a]) {
        if (av[2][a] > 57 || av[2][a] < 48)
	    return (84);
        a++;
    }
    return (0);
}

static int check_fozzbazz(int a, int b)
{
    int g = 0;

    if (0 == (a % 2))
        g += 1;
    if (0 == (a % 9))
        g += 2;
    if (g == 1) {
        printf("Fozz\n");
        return (1);
    }
    if (g == 2) {
        printf("Bazz\n");
        return (1);
    }
    if (g == 3) {
        printf("FozzBazz\n");
        return (1);
    }
    return (0);
}

int main(int ac, char** av)
{
    int a = 0;
    int b = 0;
    int casse_d = 0;
    
    if (check_errors(ac, av) == 84)
        return (84);
    a = atoi(av[1]);
    b = atoi(av[2]);
   
    check_casses(a, b);
    while (a <= b) {
        casse_d = check_fozzbazz(a, b);
        if (casse_d == 0)
            printf("%d\n", a);
        a++;
        casse_d = 0;
    }
    return (0);
}
