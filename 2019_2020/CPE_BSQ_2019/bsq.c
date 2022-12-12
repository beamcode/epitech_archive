/*
** EPITECH PROJECT, 2019
** bsq.c
** File description:
** square finder
*/

#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include "lib/my/my_lib.h"

int bsq(char **av)
{
    char file_name[100] = av[1];
    char ch;
    FILE *fp;

    //FILE *fp;

    fp = fopen(file_name, "r"); // read mode

    if (fp == NULL) {
        my_putstr("Error while opening the test file.\n");
        return 84;;
    }

    fclose(fp);
    return 0;
}

int main(int ac, char **av)
{
    if (ac > 1)
        return 84;
    bsq(av);
    return 0;
}