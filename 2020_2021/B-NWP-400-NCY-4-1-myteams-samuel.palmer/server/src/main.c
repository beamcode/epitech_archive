/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "file.h"

void print_help()
{
    printf("USAGE: ./myteams_server port\n\n");
    printf("\tport is the port number on which the server socket listens.\n");
}

struct client_s *init_client ()
{
    struct client_s *client = malloc(sizeof(struct client_s));
    //struct HEADNAME *listhead;
    LIST_INIT(&head);
    if (client != NULL) {
        client->is_log = false;
        client->user = false;
        client->is_passiv = false;
        client->control_socket = 0;
        client->data_socket = 0;
        client->next = NULL;
    } else
        exit (84);
    return (client);
}

struct ftp_s *init_struct(int port)
{
    struct ftp_s *st = malloc(sizeof(struct ftp_s));
    if (st != NULL)
        st->client = init_client();
    else
        exit (84);
    st->master_socket = 0;
    st->add.sin_family = AF_INET;
    st->add.sin_addr.s_addr = INADDR_ANY;
    st->control_socket = 0;
    st->add.sin_port = htons(port);
    return (st);
}

int create_master_socket(int port)
{
    struct ftp_s *st = init_struct(port);
    int opt = true;

    st->master_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (st->master_socket < 0)
        return (84);
    if (setsockopt(st->master_socket, SOL_SOCKET, 
    SO_REUSEADDR, (char *)&opt, sizeof(opt)) < 0 )
        return (84);
    if (bind(st->master_socket, (struct sockaddr *) &st->add, 
    sizeof(st->add)) == -1)
        return (84);
    if (listen(st->master_socket, 3) == -1)
        return (84);
    puts("Waiting for connections ...");
    return (connection_loop(st));
}

int main(int argc, char **argv)
{
    int port = 0;

    if (argc != 2) {
        print_help();
        return (84);
    }
    signal(SIGINT, signal_handler);
   // if ((realpath(argv[2], path)) == NULL)
     //   handle_error("path");
    //if (chdir(path) != 0)
      //  return (84);
    port = atoi(argv[1]);
    if (port < 0 && port > 65535) {
        print_help();
        return (84);
    }
    return (create_master_socket(port));
}