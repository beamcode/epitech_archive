/*
** EPITECH PROJECT, 2020
** cdup.c
** File description:
** cdup
*/

#include "../../include/my_ftp.h"

int count_slash(char *str)
{
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == '/')
            count++;
    return (count);
}

void remove_slash(char *str)
{
    for (int i = strlen(str); i > 0; i--) {
        if (str[i] == '/') {
            str[i] = '\0';
            break;
        }
    }
}

int	execute_cdup(client_t *client)
{
    if (!strncmp(client->input, "CDUP", 4)) {
        char *str = strdup(client->dir[client->i]);
        remove_slash(str);
        DIR *dir = opendir(str);
        if (dir && count_slash(client->dir[client->i]) > 1) {
            if (!opendir(str))
                send_message(client->sd[client->i], CODE_550);
            else {
                client->dir[client->i] = strdup(str);
                chdir(client->dir[client->i]);
                send_message(client->sd[client->i], CODE_200);
                closedir(dir);
                return (SUCESS);
            }
        } else {
            send_message(client->sd[client->i], CODE_550);
            return (SUCESS);
        }
    }
    return (ERROR);
}
