/*
** EPITECH PROJECT, 2021
** connection.c
** File description:
** connection
*/

#include "../include/my_ftp.h"

void set_fd(client_t *client)
{
    for (int i = 0; i < MAX_CLIENTS; i++) {
        client->sd[i] = client->client_val[i];
        if (client->sd[i] > 0)
            FD_SET(client->sd[i], &client->fd);
        if (client->sd[i] > client->max_socket)
            client->max_socket = client->sd[i];
    }
}

static void update_connection_list(client_t *client)
{
    for (int i = 0; i < MAX_CLIENTS && 1; i++) {
        if (client->client_val[i] == 0) {
            client->client_val[i] = client->client_socket;
            break;
        }
    }
}

int	accept_connections(client_t *client)
{
    struct sockaddr_in client_s;
    socklen_t size = sizeof(client_s);

    if (FD_ISSET(client->server_socket, &client->fd)) {
        client->client_socket = accept(client->server_socket, \
        (struct sockaddr *)&client_s, &size);
        if (client->client_socket == -1) {
            print_error_and_close(client->server_socket, CLIENT_SOCKET_FAILED);
            return (ERROR);
        }
        fprintf(stdout, "New connction with ip = %s and port %d\n", \
        inet_ntoa(client_s.sin_addr), ntohs(client_s.sin_port));
        send_message(client->client_socket, CODE_220);
        update_connection_list(client);
    }
    return (SUCESS);
}
