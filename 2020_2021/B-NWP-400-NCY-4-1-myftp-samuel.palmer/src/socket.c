/*
** EPITECH PROJECT, 2021
** socket.c
** File description:
** socket
*/

#include "../include/my_ftp.h"

void print_error_and_close(int server_socket, char *msg)
{
    fprintf(stderr, "%s", msg);
    close(server_socket);
}

int	create_server(int port)
{
    int	server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in srv_address;
    socklen_t size = sizeof(srv_address);

    if (server_socket == -1) {
        print_error_and_close(server_socket, SOCKET_FAILED);
        return (ERROR);
    }
    srv_address.sin_family = AF_INET;
    srv_address.sin_port = htons(port);
    srv_address.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(server_socket, (struct sockaddr *)&srv_address, size) == -1) {
        print_error_and_close(server_socket, BIND_FAILED);
        return (ERROR);
    }
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        print_error_and_close(server_socket, LISTEN_FAILED);
        return (ERROR);
    }
    return (server_socket);
}

int	init_server(char **av)
{
    int port = atoi(av[1]);
    char *dir = av[2];
    int server_socket = create_server(port);

    if (server_socket == ERROR)
        return (ERROR);
    if (run_loop(port, server_socket, dir))
        return (ERROR);
    return (SUCESS);
}