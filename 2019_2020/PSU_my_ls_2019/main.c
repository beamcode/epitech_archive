/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** yeee
*/

#include "my.h"

void do_ls(char *str)
{
    struct dirent *dirent;
    DIR *dir = opendir(str);

    if (dir == NULL)
        return;
    while ((dirent = readdir(dir)) != 0) {
        if ((dirent->d_name[0] != '.')) {
            my_putstr(dirent->d_name);
            my_putchar('\n');
        }
    }
}

int main(int ac, char **av)
{
    if (ac == 1)
        do_ls("./");
    if (ac == 2)
        do_ls(av[1]);
    return (0);
}