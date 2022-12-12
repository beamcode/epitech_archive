/*
** EPITECH PROJECT, 2021
** server
** File description:
** teams
*/

#include "file.h"

struct client_s *add_socket(int new_socket, struct client_s *client, struct ftp_s *st)
{
    struct client_s *new = malloc(sizeof(struct client_s));

    new->control_socket = new_socket;
    new->path = st->path;
    new->path = strdup(st->path);
    new->is_log = false;
    new->user = false;
    new->is_passiv = false;
    new->data_socket = 0;
    if (client == NULL)
        return (client);
    else
        for (; client->entries.le_next != NULL; client = client->entries.le_next);
    LIST_INSERT_AFTER(client, new, entries);
    return (client);
}

int check_socket_action(struct ftp_s *st, struct client_s *c)
{
    int valread;
    char buffer[1024];
   // socklen_t addrlen = sizeof(st->add);

    if (FD_ISSET(st->control_socket, &st->readfds)) {
        if ((valread = read(st->control_socket, buffer, 1024)) == 0) {
            close(st->control_socket);
            c->control_socket = 0;
            return (0);
        } else if (buffer[valread -1] != '\n')
            return (0);
        else
            return (check_command(st, buffer, valread, c));
    }
    return (0);
}

int waiting_connection(struct ftp_s *st, int max_sd)
{
    int activity = 0;
    int new_socket = 0;
    socklen_t addrlen = sizeof(st->add);

    activity = select(max_sd + 1, &st->readfds, NULL, NULL, NULL);
    if ((activity < 0) && (errno != EINTR))
        printf("select error");
    if (FD_ISSET(st->master_socket, &st->readfds)) {
        new_socket = accept(st->master_socket, (struct sockaddr *)&st->add, 
        (socklen_t *) &addrlen);
        dprintf(new_socket, "220 Service ready for new user.\r\n");
        for (struct client_s *c = st->client; c != NULL; c = c->entries.le_next) {
            if (c->control_socket == 0) {
                c->control_socket = new_socket;
                break;
            }
            if (c->entries.le_next == NULL) {
                add_socket(new_socket, c, st);
                break;
            }
        }
    }
    return (0);
}

int get_file_descriptor(struct ftp_s *st, int max_sd)
{
    FD_ZERO(&st->readfds);
    FD_SET(st->master_socket, &st->readfds);
    max_sd = st->master_socket;
    for (struct client_s *c = st->client; c != NULL; c = c->entries.le_next) {
        st->control_socket = c->control_socket;
        if (st->control_socket > 0)
            FD_SET(st->control_socket, &st->readfds);
        if (st->control_socket > max_sd)
            max_sd = st->control_socket;
    }
    return (max_sd);
}

int connection_loop(struct ftp_s *st)
{
    int max_sd = 0;

    while (1) {
        max_sd = get_file_descriptor(st, max_sd);
        if (waiting_connection(st, max_sd) == 84)
            return (84);
       for (struct client_s *c = st->client; c != NULL; c = c->entries.le_next) {
            st->control_socket = c->control_socket;
            if (check_socket_action(st, c) == 84)
                return (84);
        }
    }
}