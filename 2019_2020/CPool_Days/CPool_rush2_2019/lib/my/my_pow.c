/*
** EPITECH PROJECT, 2019
** rush
** File description:
** rush
*/

int my_pow(int a, int b)
{
    int nb = 1;
    int i = 0;

    for (i = 0; i < b; i++)
        nb *= a;
    return (nb);
}
