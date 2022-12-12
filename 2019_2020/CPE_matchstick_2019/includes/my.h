/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** yeee
*/

#ifndef matchstick
#define matchstick

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "../lib/my/my_lib.h"

typedef struct st
{
    int win;
    int turn;
    int ac;
    char **av;
    char **map;
    int rows;
    int max_matches;
    int line;
    int matches;
    int matches_check;
    int m_left;
    int most_line;
    int last;
}st_s;

void init_values(st_s *st);
void create_map(st_s *st);

int get_matches(st_s *st);
int get_line(st_s *st);

int check_getline_error(st_s *st, char *line);
int check_getmatches_error(st_s *st, char *line);
int check_invalid_input(char *line);
int check_matches(st_s *st);

void play_computer(st_s *st);
void print_action_played(st_s *st);
int remove_matches(st_s *st);
void check_win(st_s *st);
void print_map(st_s *st);

void print_end_messages(st_s *st);

#endif