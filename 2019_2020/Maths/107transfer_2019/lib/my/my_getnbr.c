/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** String to int
*/

int my_getnbr(char const *str)
{
    int a = 0;
    int res = 0;
    int isitneg = 0;

    if (str[0] == '\0')
        return (0);
    for (; str[a] == '-' || str[a] == '+'; a++)
        if (str[a] == '-')
            isitneg++;
    for (; str[a] != '\0' && str[a] >= 48 && str[a] <= 57; a++)
        res = res * 10 + str[a] - 48;
    if (isitneg % 2 == 1)
        res = -res;
    return (res);
}