/*
** EPITECH PROJECT, 2019
** 
** File description:
**
*/

#include <stdarg.h>
#include "my_lib.h"


int sum_stdarg(int i , int nb , ... )
{
    int a = 0;
    va_list ap;

    va_start(ap, nb);
    if (i == 1) {
        for (; nb != 0; nb--) {
            a = a + my_strlen(va_arg(ap, char*));
        }
    }
    for (; nb != 0; nb--) {
        a = a + va_arg(ap, int);
    }
    va_end(ap);
    return (a);
}