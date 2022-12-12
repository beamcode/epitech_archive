/*
** EPITECH PROJECT, 2021
** list.c
** File description:
** list
*/

#include "../../include/my_ftp.h"

int	execute_list(client_t *client)
{
    if (!strncmp(client->input, "LIST", 4)) {
        send_message(client->sd[client->i], CODE_150);
        send_message(client->sd[client->i], CODE_226);
    }
    return (ERROR);
}
