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
#include <getopt.h>
#include <string.h>

static struct option long_options[] = {
    {"imin",     required_argument, 0,  0 },
    {"imax",     required_argument, 0,  0 },
    {0,         0,                 0,  0 }
};

typedef struct st
{
    int option;
    int num;
    int base;
    int imax;
    int imin;
} st_s;

char *my_itoa(int nb);
char *my_revstr(char *str);
int check_pal(int num);
void execute_sorry(st_s *st, char *optarg, int a);
int check_errors(st_s *st);
int get_flags(int ac, char **av, st_s *st);
void print_help(void);
void do_algo(st_s *st);
int convert_to_base(int num, int base);
int convert_to_dec(int nb, int base);

int my_factrec_synthesis(int nb);
int my_squareroot_synthesis(int nb);
#endif