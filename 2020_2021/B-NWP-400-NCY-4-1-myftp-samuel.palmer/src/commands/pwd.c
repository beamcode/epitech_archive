/*
** EPITECH PROJECT, 2021
** pwd.c
** File description:
** pwd
*/

#include "../../include/my_ftp.h"

int	execute_pwd(client_t *client)
{
    if (strncmp(client->input, "PWD", 3))
        return (ERROR);
    char *dir = malloc(sizeof(char) * 2048);

    if (getcwd(dir, 2048) == NULL) {
        send_message(client->sd[client->i], CODE_550);
        free(dir);
        return (SUCESS);
    }
    else {
        send_message(client->sd[client->i], "257 \"");
        send_message(client->sd[client->i], dir);
        send_message(client->sd[client->i], "\" is current directory.\r\n");
    }
    free(dir);
    return (ERROR);
}
