/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** my_getnbr.c
*/

int lim(long *n)
{
    if (*n < -2147483648 || *n > 2147483647) {
        *n = 0;
    }
    return n;
}

int my_getnbr(char const *str)
{
    int nb = 0;
    long n = 0;
    int a = 0;
    int isn = 0;
    
    for (int i = 0; str[i] >= '\0'; i++)
    {
        for (;str[i] >= '0' && str[i] <= '9'; i++)
        {
            if (i != 0 && str[i - 1] == '-')
                isn = 1;
            n *= 10;
            n += (str[i] - '0');
        }
    }
    lim(&n);
    return (n);
}