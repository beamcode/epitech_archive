/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** header
*/

#ifndef useful
#define useful

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//Premade
char **str_to_wordtab(char *string, char sep);
void my_putarray(char **array);

//Random
int select_option(char **av, char **str);
char **organize_data(char **str);
char *my_strcat_dup(const char *str1, const char *str2);
void sort_alpha(char **str);

//Functions for prerequisits
void do_one(char **str);
void do_two(char **str);
void do_three(char **str);
void do_four(char **str, int k);
void do_five(char **str);
void do_six(char **str);

//Processes
void process_one(char **str);
void process_two(char **str);
void process_three(char **str);
void process_four(char **str, char **kmers, int k);
void process_five(char **str, char **cod);

#endif
