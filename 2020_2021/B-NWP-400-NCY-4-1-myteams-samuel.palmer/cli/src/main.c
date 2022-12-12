/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "include.h"

void print_help()
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("\tip   is the server ip address on which the server socket listens\n");
    printf("\tport is the port number on which the server socket listens\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help")) {
        print_help();
        return (0);
    }
    return (0);
}