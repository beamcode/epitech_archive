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

int	my_strcmp(const char *s1, const char *s2);
char *my_strconcat(char *dest, char *src);
void my_puterr(char *error);
int sum_stdarg(int i , int nb , ... );
int disp_stdarg(char *s , ... );
int my_getnbr(char const *str);
void my_putchar(char c);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_isneg(int n);
void my_swap(int *a, int *b);
int my_putnbr(int nb);
int my_atoi(char *str);
int my_put_un_nbr(unsigned int nb);
char *my_revstr(char *str);
int my_dec_to_hex_min(unsigned int hex);
int my_dec_to_hex_maj(unsigned int hex);
void my_printf(char *s, ...);
char *my_itoa(int nbr);

#endif