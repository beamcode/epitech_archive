/*
** EPITECH PROJECT, 2021
** network
** File description:
** teams
*/

#include "file.h"

int my_user(char *str, struct client_s *c)
{
    int i = 0;
    int j = 0;

    for (i = 0; str[i] != ' '; i++);
    for (j = 0; str[j] != '\n'; j++);
    str[j - 1] = '\0';
    if (strcmp("Anonymous", &str[i + 1]) == 0) {
        c->user = true;
    }
    dprintf(c->control_socket, "331 User name okay, need password.\r\n");
    return (0);
}

int check_command(struct ftp_s *st, char *buffer, int valread, struct client_s *c)
{
    buffer[valread] = '\0';
    //if (strstr(buffer, "USER") != NULL)
      //  my_user(buffer, c);
    /*if (strstr(buffer, "PASS") != NULL)
        my_pass(buffer, c);
    if (strcmp(buffer, "HELP\r\n") == 0)
        my_help(c);
    if (strcmp(buffer, "QUIT\r\n") == 0) {
        dprintf(c->control_socket, "221 Service closing control connect.\r\n");
        close(c->control_socket);
        c->control_socket = 0;
    }*/
    if (strcmp(buffer, "NOOP\r\n") == 0)
        write(c->control_socket, "200 Ok\r\n", strlen("200 Ok\r\n"));
    //my_need_log(buffer, st, c);
    //check_mode_command(buffer, c);
    return (0);
}