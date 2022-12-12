/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** Counts characters in a string
*/

int my_strlen(char const *str)
{
    int a = 0;

    for (; str[a] != '\0'; a++);
    return a;
}