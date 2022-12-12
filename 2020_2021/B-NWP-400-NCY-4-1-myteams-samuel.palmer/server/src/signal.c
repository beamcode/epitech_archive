/*
** EPITECH PROJECT, 2021
** signal
** File description:
** teams
*/

#include "file.h"


void signal_handler(int sig)
{
    char *message;

    if (sig == 2) {
        printf("\n");
        return;
    }
    message = strsignal(sig);
    printf("%s\n", message);
}
