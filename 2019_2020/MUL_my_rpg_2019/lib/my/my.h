/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** ok
*/

#ifndef _MY_H_
#define _MY_H_

#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void free_array(char **array);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int my_atoi(char *str);
void my_putchar(char c);
int my_find_prime_sup(int nb);
char *my_strcat(char *buf, char *tmp);
void my_put_nbr(int nb);
char **my_str_to_word_tab(char *line, char c);
int my_strcmp(char const *str1, char const *str2);
void my_puterr(char const *error);
char *my_itoa(int nbr);
int my_putstr(char const *str);
void display_array(char **array);
#endif /*MY_H_ */