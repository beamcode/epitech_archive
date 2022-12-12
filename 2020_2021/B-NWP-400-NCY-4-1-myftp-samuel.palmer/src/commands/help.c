/*
** EPITECH PROJECT, 2021
** help.c
** File description:
** help
*/

#include "../../include/my_ftp.h"

bool execute_help(client_t *client)
{
    if (!strncmp(client->input, "HELP", 4)) {
        send_message(client->sd[client->i], CODE_214);
        return (true);
    }
    return (false);
}
