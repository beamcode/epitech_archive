/*
** EPITECH PROJECT, 2021
** delete.c
** File description:
** delete
*/

#include "../../include/my_ftp.h"

int	execute_delete(client_t *client)
{

    if (!strncmp(client->input, "DELE", 4)) {
        char *str = client->input + 5;
        str[strlen(str) - 1] = '\0';
        if (strlen(client->input) < 6)
            send_message(client->sd[client->i], CODE_550);
        else if (remove(str) == -1)
            send_message(client->sd[client->i], CODE_550);
        else {
            send_message(client->sd[client->i], CODE_250);
            return (SUCESS);
        }
    }
    return (ERROR);
}