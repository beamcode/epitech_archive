/*
** EPITECH PROJECT, 2019
** my_lib.h
** File description:
** Header file for lib
*/

#ifndef MY_H
#define MY_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

int my_isneg(int n);
int my_putnbr(int nb);
char *my_itoa(int nbr);
int my_atoi(char *str);
char *my_itoa(int nbr);
void my_putchar(char c);
char *my_revstr(char *str);
void my_puterr(char *error);
void my_printf(char *s, ...);
void my_swap(int *a, int *b);
int my_getnbr(char const *str);
int my_putstr(char const *str);
int my_strlen(char const *str);
void my_putarray(char **array);
int disp_stdarg(char *s , ... );
char *my_strdup(char const *src);
int my_put_un_nbr(unsigned int nb);
int sum_stdarg(int i , int nb , ... );
int my_dec_to_hex_min(unsigned int hex);
int my_dec_to_hex_maj(unsigned int hex);
char **my_dup_array(char **array, int b);
char *my_strconcat(char *dest, char *src);
char *my_strcpy(char *dest, char const *src);
int	my_strcmp(const char *s1, const char *s2);

#endif