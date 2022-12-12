/*
** EPITECH PROJECT, 2021
** my_ftp.h
** File description:
** ftp header file
*/

#ifndef MY_FTP_H
#define MY_FTP_H

#include <errno.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define SUCESS 0
#define ERROR 84
#define MAX_CLIENTS 50

#define BIND_FAILED "ERROR: bind failed.\n"
#define LISTEN_FAILED "ERROR: listen failed.\n"
#define INVALID_PORT "ERROR: port is invalid.\n"
#define INVALID_DIR "ERROR: unable to open directory.\n"
#define SOCKET_FAILED "ERROR: failed to create socket.\n"
#define MAX_SOCKET_FAILED "ERROR: max_socket exceeded.\n"
#define CLIENT_SOCKET_FAILED "ERROR: client socket had failed.\n"
#define SELECT_FAILED "ERROR: client select experienced a failure.\n"

#define CODE_257 "257 path created.\r\n"
#define CODE_221 "221 connection closed.\r\n"
#define CODE_230 "230 User logged in, proceed.\r\n"
#define CODE_226 "226 Closing data connection.\r\n"
#define CODE_550 "550 No such file or directory.\r\n"
#define CODE_220 "220 Service ready for new user.\r\n"
#define CODE_331 "331 User name okay, need password.\r\n"
#define CODE_200 "200 Command successfully completed.\r\n"
#define CODE_500_PASV_EN "500 Please enable passive mode.\r\n"
#define CODE_500_PASV_ON "500 Passive mode already enabled.\r\n"
#define CODE_250 "250 Requested file action okay, completed.\r\n"
#define CODE_227 "227 Entering Passive Mode (h1,h2,h3,h4,p1,p2).\r\n"
#define CODE_500 "500 Syntax error, command unrecognized or action.\r\n"
#define CODE_150 "150 File status okay; about to open data connection.\r\n"
#define CODE_530 "530 Not logged in or credentials error, login with USER \
and PASS.\r\n"
#define CODE_214 "214 Help: Use one of the following commands: \
USER, PASS, QUIT, PWD, CWD, HELP, NOOP, DELE, CDUP, PORT, PASV, \
STOR, RETR, LIST.\r\n"

typedef struct client {
    int i;
    int port;
    fd_set fd;
    int max_socket;
    char *input;
    int server_socket;
    int client_socket;

    char line[1025];
    int sd[MAX_CLIENTS];
    bool pasv[MAX_CLIENTS];
    char *dir[MAX_CLIENTS];
    int client_val[MAX_CLIENTS];
    bool authed[MAX_CLIENTS];
    bool logged_in[MAX_CLIENTS];
} client_t;

int	init_server(char **av);
char *clean_str(char *str);
void set_fd(client_t *client);
bool check_args(int ac, char **av);
int select_clients(client_t *client);
void send_message(int dst, char *msg);
void parse_commands(client_t *client);
int accept_connections(client_t *client);
int run_loop(int port, int server_socket, char *dir);
void print_error_and_close(int server_socket, char *msg);
client_t *init_client_struct(client_t *client, int port, \
    int server_socket, char *dir);

int execute_cwd(client_t *client);
int execute_pwd(client_t *client);
int execute_user(client_t *client);
bool execute_quit(client_t *client);
int execute_list(client_t *client);
int execute_pasv(client_t *client);
int execute_cdup(client_t *client);
bool execute_help(client_t *client);
void execute_noop(client_t *client);
int execute_delete(client_t *client);
int execute_password(client_t *client);

#endif /* MY_FTP_H */
