/*
** EPITECH PROJECT, 2021
** noop.c
** File description:
** noop
*/

#include "../../include/my_ftp.h"

void execute_noop(client_t *client)
{
    if (!strncmp(client->input, "NOOP", 4))
        send_message(client->client_socket, CODE_200);
}
