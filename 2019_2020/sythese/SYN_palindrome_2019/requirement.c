/*
** EPITECH PROJECT, 2019
** requirement.c
** File description:
** yeeet
*/

int my_factrec_synthesis(int nb)
{
    if (nb < 0 || nb >= 13)
        return (0);
    if (nb == 0)
        return (1);
    return (nb * my_factrec_synthesis(nb - 1));
}

int my_squareroot_synthesis(int nb)
{
    int a = 0;

    if (nb < 0)
        return (-1);
    for (; (a * a) != nb; a++) {
        if ((a * a) > nb)
            return (-1);
    }
    return (a);
}