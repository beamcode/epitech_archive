/*
** EPITECH PROJECT, 2019
** my_strncpy.c
** File description:
** my_strncpy.c
*/

#include <string.h>
#include <stdio.h>

char *my_strncpy(char *dest, char const *src, int n)
{
    int i;

    for(i = 0; i < n && src[i] != '\0'; i++){
        dest[i] = src[i];
    }
    dest[i] = '\0';
    for(; i < n; i++)
        dest[i] = '\0';
    return(dest);
}