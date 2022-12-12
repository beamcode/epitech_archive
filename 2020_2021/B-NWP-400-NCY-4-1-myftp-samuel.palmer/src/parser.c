/*
** EPITECH PROJECT, 2021
** parser.c
** File description:
** parser
*/

#include "../include/my_ftp.h"

bool check_cmd(char *str)
{
    if (!strncmp(str, "QUIT", 4) || \
        !strncmp(str, "USER", 4) || \
        !strncmp(str, "LIST", 4) || \
        !strncmp(str, "PASS", 4) || \
        !strncmp(str, "DELE", 4) || \
        !strncmp(str, "CDUP", 4) || \
        !strncmp(str, "PASV", 4) || \
        !strncmp(str, "HELP", 4) || \
        !strncmp(str, "NOOP", 4) || \
        !strncmp(str, "CWD", 3) || \
        !strncmp(str, "PWD", 3))
        return (true);
    return (false);
}

void parse_commands(client_t *client)
{
    if (check_cmd(client->input)) {
        if (execute_help(client) ||
            execute_quit(client))
            return;
        if (!execute_user(client) || !execute_password(client))
            return;
        if (client->logged_in[client->i]) {
            execute_cwd(client);
            execute_pwd(client);
            execute_cdup(client);
            execute_list(client);
            execute_pasv(client);
            execute_noop(client);
            execute_delete(client);
        } else
            send_message(client->sd[client->i], CODE_530);
    } else
        send_message(client->sd[client->i], CODE_500);
}
