/*
** EPITECH PROJECT, 2021
** quit.c
** File description:
** quit
*/

#include "../../include/my_ftp.h"

bool execute_quit(client_t *client)
{
    if (!strncmp(client->input, "QUIT", 4)) {
        send_message(client->sd[client->i], CODE_221);
        close(client->sd[client->i]);
        client->client_val[client->i] = 0;
        return (true);
    }
    return (false);
}
