/*
** EPITECH PROJECT, 2019
** function
** File description:
**
*/

#include <unistd.h>
#include "rush3.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char const *str)
{
    int i;

    for (i = 0; str[i] != '\0'; i++);

    return (i);
}

void my_putstr(char *str)
{
    write(1, str, my_strlen(str));
}
