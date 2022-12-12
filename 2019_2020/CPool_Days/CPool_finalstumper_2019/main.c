/*
** EPITECH PROJECT, 2019
** rush3.c
** File description:
** rush3
*/

#include "rush3.h"
#include <stdio.h>
#include <unistd.h>
#define BUFF_SIZE 4096

int main()
{
    char buff[BUFF_SIZE + 1];
    int offset = 0;
    int len;
    
    while ((len = read(0, buff + offset, BUFF_SIZE - offset)) > 0) {
        offset = offset + len;
    }
    buff[offset] = '\0';
    if (len < 0)
        return (84);
    my_rush3(buff);
    return (0);
}
