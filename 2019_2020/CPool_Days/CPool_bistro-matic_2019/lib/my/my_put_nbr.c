/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** Write a char
*/

void my_putchar(char c);

int my_put_nbr(int nb) 
{
    int a = 0;

    if (nb < 0) {
        my_putchar('-');
        nb = nb * -1;
    }
    if (nb <= 9) {
        my_putchar(nb + 48);
        return (0);
    }
    a = nb % 10;
    my_put_nbr(nb / 10);
    my_putchar(a + 48);
	return (0);
}