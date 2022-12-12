/*
** EPITECH PROJECT, 2021
** pasv.c
** File description:
** pasv
*/

#include "../../include/my_ftp.h"

int	execute_pasv(client_t *client)
{
    if (!strncmp(client->input, "PASV", 4)) {
        if (!client->pasv[client->i]) {
            client->pasv[client->i] = true;
            send_message(client->sd[client->i], CODE_227);
            return (SUCESS);
        } else {
            send_message(client->sd[client->i], CODE_500_PASV_ON);
            return (SUCESS);
        }
    }
    return (ERROR);
}
