/*
** EPITECH PROJECT, 2021
** mem_ptr.c
** File description:
** This is second day of c++ pool
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "mem_ptr.h"

void add_str(const char *str1, const char *str2, char **res)
{
    *res = malloc(sizeof(char) * (strlen(str1) + strlen(str2)));

    *res = strcat(*res, str1);
    *res = strcat(*res, str2);
    return;
}

void add_str_struct(str_op_t *str_op)
{
    str_op->res = malloc(sizeof(char) * (strlen(str_op->str1) + \
    	strlen(str_op->str2)));

    str_op->res = strcat(str_op->res, str_op->str1);
    str_op->res = strcat(str_op->res, str_op->str2);
    return;
}