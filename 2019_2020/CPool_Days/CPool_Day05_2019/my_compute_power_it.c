/*
** EPITECH PROJECT , 2019
** my_compute_power_it
** File description :
** task03
*/

int my_compute_power_it(int nb, int p)
{
    int a = 1;
    int b = nb;

    if (nb == 0 || p == 0)
    {
        return(1);
    }
    if (p < 0)
    {
        return (0);
    }

    while (a < p)
    {
        nb = nb * b;
        a++;
    }
    return (nb);
}