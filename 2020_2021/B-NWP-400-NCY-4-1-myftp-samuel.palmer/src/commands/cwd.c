/*
** EPITECH PROJECT, 2021
** cwd.c
** File description:
** cwd
*/

#include "../../include/my_ftp.h"

int serach_dir(client_t *client)
{
    char *path = client->input + 4;
    path[strlen(path) - 1] = '\0';

    if (path == NULL)
        send_message(client->sd[client->i], CODE_550);
    if (!chdir(path)) {
        send_message(client->sd[client->i], CODE_250);
        return (SUCESS);
    }
    else
        send_message(client->sd[client->i], CODE_550);
    return (ERROR);
}

int	execute_cwd(client_t *client)
{
    if (!strncmp(client->input, "CWD", 3)) {
        if (strlen(client->input) < 5) {
            send_message(client->sd[client->i], CODE_550);
            return (ERROR);
        }
        return (serach_dir(client));
    }
    return (ERROR);
}