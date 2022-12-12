/*
** EPITECH PROJECT, 2019
** my_lib.h
** File description:
** Header file for lib
*/

#ifndef MY_H
#define MY_H

#include <math.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

void print_flags_s(va_list sam);
void print_flags_S(va_list sam);
void print_flags_d(va_list sam);
void print_flags_i(va_list sam);
void print_flags_c(va_list sam);
void print_flags_o(va_list sam);
void print_flags_u(va_list sam);
void print_flags_x(va_list sam);
void print_flags_X(va_list sam);
void print_flags_p(va_list sam);

typedef struct printsort 
{
    char flag;
    void (*pf)(va_list);
} print_t;

static const print_t flags[] = {
    {'s', print_flags_s}, 
    {'S', print_flags_S}, 
    {'d', print_flags_d}, 
    {'i', print_flags_i}, 
    {'c', print_flags_c}, 
    {'o', print_flags_o}, 
    {'u', print_flags_u}, 
    {'x', print_flags_x}, 
    {'X', print_flags_X}, 
    {'P', print_flags_p}, 
    {'\0', NULL}
};

void my_printf(char *s, ...);
int my_dec_to_oct(int decimalNumber);
int sum_stdarg(int i , int nb , ... );
int disp_stdarg(char *s , ... );
int my_getnbr(char const *str);
void my_putchar(char c);
int	my_putstr(char const *str);
int my_strlen(char const *str);
int	my_isneg(int n);
void my_swap(int *a, int *b);
int my_put_nbr(int nb);
int my_atoi(char* str);
int my_put_un_nbr(unsigned int nb);
char *my_revstr(char *str);
int my_dec_to_hex_min(unsigned int hex);
int my_dec_to_hex_maj(unsigned int hex);
void my_printf(char *s, ...);
char *my_itoa(int nbr);

#endif