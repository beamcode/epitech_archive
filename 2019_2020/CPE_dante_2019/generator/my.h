/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** yeee yes
*/

#ifndef useful
#define useful

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "lib/my/my_lib.h"

typedef struct st
{
    int x;
    int y;
    char **maze;
} st_s;

void fill_star(char **temp);
void debug(st_s *st);
char **generate_array(int x, int y);
void print_maze(char **array);
int search_begin(st_s *st, int x, int y);
#endif