/*
** EPITECH PROJECT, 2021
** ftp_core.c
** File description:
** ftp_core
*/

#include "../include/my_ftp.h"

client_t *init_client_struct(client_t *client, int port, \
int server_socket, char *dir)
{
    client->i = 0;
    client->port = port;
    client->server_socket = server_socket;
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client->sd[i] = 0;
        client->pasv[i] = false;
        client->client_val[i] = 0;
        client->logged_in[i] = false;
        client->authed[i] = false;
        client->dir[i] = strdup(dir);
    }
    return (client);
}

void read_commands(client_t *client)
{
    for (client->i = 0; client->i < MAX_CLIENTS; client->i++) {
        client->sd[client->i] = client->client_val[client->i];
        if (FD_ISSET(client->sd[client->i], &client->fd)) {
            if (read(client->sd[client->i], client->line, 1024) == 0) {
                close(client->sd[client->i]);
                printf("Client %d has disconnected.\n", client->i + 1);
                client->client_val[client->i] = 0;
            } else {
                client->input = clean_str(client->line);
                parse_commands(client);
            }
            memset(client->input, 0, strlen(client->input));
            memset(client->line, 0, strlen(client->line));
        }
    }
}

void get_max_socket(client_t *client)
{
    FD_ZERO(&client->fd);
    FD_SET(client->server_socket, &client->fd);
    client->max_socket = client->server_socket;
}

int	select_clients(client_t *client)
{
    if (select(client->max_socket + 1, &client->fd, NULL, NULL, NULL) == -1)
        return (ERROR);
    if (accept_connections(client))
        return (ERROR);
    return (SUCESS);
}

int	run_loop(int port, int server_socket, char *dir)
{
    client_t *client = malloc(sizeof(client_t));
    client = init_client_struct(client, port, server_socket, dir);

    printf("Server up on port %d, waiting for clients...\n", port);
    while (true) {
        get_max_socket(client);
        if (client->max_socket == -1) {
            print_error_and_close(server_socket, MAX_SOCKET_FAILED);
            return (ERROR);
        }
        set_fd(client);
        if (select_clients(client) != SUCESS) {
            print_error_and_close(server_socket, SELECT_FAILED);
            return (ERROR);
        }
        read_commands(client);
    }
    close(server_socket);
    return (SUCESS);
}
