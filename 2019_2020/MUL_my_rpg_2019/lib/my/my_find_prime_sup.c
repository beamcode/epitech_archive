/*
** EPITECH PROJECT, 2019
** my find prime sup
** File description:
** found the smallest prime number that is egal or greater than the argument
*/

int check_simple_nbr(int nb)
{
    int three = 3;
    int two = 2;
    two = nb % 2;
    three = nb % 3;
    if (nb == 2)
        return (1);
    if (nb == 3)
        return (1);
    if (two == 0)
        return (0);
    if (three == 0)
        return (0);
    return (1);
}

int more_than_ten(int nb)
{
    int mod = 2;
    int result;

    while (mod < 10) {
        result = nb % mod;
        if (result == 0) {
            return (0);
        }
        mod++;
    }
    return (nb);
}

int my_find_prime_sup(int nb)
{
    int less = 0;
    int more = 0;

    if (nb <= 1)
        return (0);
    if (nb <= 10) {
        less = check_simple_nbr(nb);
        if (less == 0)
            my_find_prime_sup(nb + 1);
        if (less == 1)
            return (nb);
    }
    more = more_than_ten(nb);
    if (more > 0)
        return (nb);
    my_find_prime_sup(nb + 1);
    return (0);
}
