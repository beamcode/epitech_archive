/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** yeee yes
*/

#ifndef useful
#define useful

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/stat.h>

typedef struct st
{
    int xb;
    int yb;
    char **map;
} st_s;

char *open_file(char *av);
void print_map(char **array);
int search_begin(st_s *st, int x, int y);
char **create_map(char *av);
char **str_to_wordtab(char *string, char sep);

#endif