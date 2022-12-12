/*
** EPITECH PROJECT, 2019
** my_atoi.c
** File description:
** String to int
*/

int my_atoi(char* str)
{
    int res = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';
    return res;
}