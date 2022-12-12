/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** main
*/

#include "../include/my_ftp.h"

int	main(int ac, char **av)
{
    if (check_args(ac, av))
        return (ERROR);
    return (init_server(av));
}
