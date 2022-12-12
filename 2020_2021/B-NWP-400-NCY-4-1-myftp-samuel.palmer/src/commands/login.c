/*
** EPITECH PROJECT, 2021
** login.c
** File description:
** login
*/

#include "../../include/my_ftp.h"

int	execute_password(client_t *client)
{
    if (strncmp(client->input, "PASS", 4))
        return (ERROR);
    if (client->logged_in[client->i] &&
        ((strstr(client->input, "PASS ") &&
        (strlen(client->input) == 6)) ||
        strncmp(client->input, "PASS", 4))) {
        client->authed[client->i] = true;
        send_message(client->sd[client->i], CODE_230);
        return (SUCESS);
    }
    return (ERROR);
}

int	execute_user(client_t *client)
{
    if (strncmp(client->input, "USER", 4))
        return (ERROR);
    if (strlen(client->input) > 4) {
        if (!strncmp(client->input, "USER Anonymous", 14))
            client->logged_in[client->i] = true;
        send_message(client->sd[client->i], CODE_331);
        return (SUCESS);
    }
    return (ERROR);
}
