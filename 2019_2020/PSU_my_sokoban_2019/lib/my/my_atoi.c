/*
** EPITECH PROJECT, 2019
** my_isneg.c
** File description:
** Determins if int is positive or negative
*/

int my_atoi(char *str)
{
    int neg = 1;
    int a = 0;
    int nb = 0;

    while ((str[a] != '\0' && str[a] >= '0'
        && str[a] <= '9') || str[a] == '-') {
        if (str[a] == '-')
            neg = neg * -1;
        else
            nb = (nb * 10) + (str[a] - '0');
        a++;
    }
    return (nb * neg);
}