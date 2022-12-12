/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** yeee yes
*/

#ifndef minishell
#define minishell

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <errno.h>
#include "lib/my/my_lib.h"

typedef struct st
{
    char **path;
    char **l_table;
    char *temp;
    char *input;
    char *ac_path;
    char **env;
    char *home_path;
    char *current;
    char *binary_path;
    int home_line;
    int home_update;
    int noa;
    int error;
    int pid;
    int status;
    int builtin;
}st_s;

void check_signal();
void do_cd(st_s *st);
int get_line(st_s *st);
int get_home(st_s *st);
void set_home(st_s *st);
void do_setenv(st_s *st);
void do_cd_back(st_s *st);
void update_cwd(st_s *st);
int check_binary(st_s *st);
void do_unsetenv(st_s *st);
void check_builtin(st_s *st);
void execute_sysfunction(st_s *st);
char **get_wordtab_inp(char *str);
char **get_wordtab_env(char **str);
void get_path(st_s *st, char **env);

#endif