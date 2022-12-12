/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** yeee yes
*/

#ifndef useful
#define useful

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stddef.h>
#include <sys/types.h>
#include <signal.h>
#include "lib/my/my_lib.h"

typedef struct global
{
    int pid;
    int global;
}vg_s;

extern vg_s vg;

typedef struct st
{
    pid_t my_pid;
    int x;
    int y;
    int win;
    int pid_player1;
    char **map;
    char **enemy_map;
}st_s;

char *get_input(st_s *st);
int verify_win(st_s *st);
void attack_ship(st_s *st);
void check_success(st_s *st, char *line);
void print_maps(st_s *st);
void send_signal(char *inp);
int check_input(char *input);
void receive_signal(st_s *st);
int check_map_error(char *map);
char *get_map(int ac, char *av);
void execute_player_one(st_s *st);
int generate_maps(st_s *st, char *map);
void execute_player_two(st_s *st, char *host_pid);
void sig_handler(int signum, siginfo_t *sig, void *c);

#endif