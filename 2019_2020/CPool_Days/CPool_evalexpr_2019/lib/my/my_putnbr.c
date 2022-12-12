/*
** EPITECH PROJECT, 2019
** my_putnbr.c
** File description:
** my_putnbr.c
*/

void my_putchar(char c);

int my_putnbr(int nb)
{
    if (nb > 9)
        my_putnbr(nb/10);
    else if (nb < 0){
        my_putchar('-');
        nb *= -1;
        my_putnbr(nb/10);
    }
    my_putchar(nb % 10 + '0');
    return (0);
}