/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** include
*/

#ifndef FILE_H_
#define FILE_H_

#include <signal.h>
#include <string.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <errno.h>
#include <stdlib.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <limits.h>
#include <sys/mman.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/queue.h>

#define handle_error(msg) \
           do { perror(msg); exit(EXIT_FAILURE); } while (0)


struct client_s
{
    char *path;
    bool is_log;
    bool user;
    struct sockaddr_in data;
    struct client_s *next;
    bool is_passiv;
    LIST_ENTRY(client_s) entries; 
    int control_socket;
    int data_socket;
};

struct ftp_s
{
    int master_socket;
    int control_socket;
    struct sockaddr_in add;
    fd_set readfds;
    struct client_s *client;
    char *path;
};

LIST_HEAD(listhead, client_s) head;
int my_retr(char *buffer, struct client_s *c);
int my_pasv(struct ftp_s *st, struct client_s *c);
int my_stor(char *buffer, struct client_s *c);
int my_user(char *str, struct client_s *c);
int my_pass(char *str, struct client_s *c);
void my_pwd(struct client_s *c);
void my_cwd(struct client_s *c, char *str);
void my_cdup(struct client_s *c);
char *cleaning_str_tab(char *str);
char **my_str_to_word_tab(char *line, char c);
int my_help(struct client_s *c);
int my_ls(char *buffer, struct client_s *c);
bool connect_data(struct client_s *c);
int get_file_descriptor(struct ftp_s *st, int max_sd);
int waiting_connection(struct ftp_s *st, int max_sd);
int check_socket_action(struct ftp_s *st, struct client_s *c);
struct client_s *add_socket(int new_socket, struct client_s *client, struct ftp_s *st);
char *my_mmap(char *path);
int check_command(struct ftp_s *st, char *buffer, int valread, struct client_s *c);
int check_mode_command(char *buffer, struct client_s *c);
int my_delete(char *buffer, struct client_s *c);
int check_my_stor(struct client_s *c);
int check_my_retr(struct client_s *c);
int connection_loop(struct ftp_s *st);
void signal_handler(int sig);
#endif /* !FILE_H_ */
