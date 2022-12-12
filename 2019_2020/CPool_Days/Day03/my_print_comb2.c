/*
** EPITECH PROJECT , 2019
** my_put_comb
** File description :
**
*/

#include <stdio.h>

int my_putchar(char c);

int my_print_comb(void)
{
    int a = 48;
    int b = 48;
    int c = 48;
    int d = 48;

    while (a <= 57) {
        while (b <= 56) {
            while (c <= 57) {
                while (d <= 57) {
                  display(a, b, c, d);
                  d++;
                }
                d = 48;
                c++;
            }
            c = 48;
            b++;
        }
        b = 48;
        a++;
    }
    return (0);
}

int display(int a, int b, int c, int d)
{
    if (a == 57 && b == 56 && c == 57 && d == 57) {
        my_putchar(a);
        my_putchar(b);
        my_putchar(' ');
        my_putchar(c);
        my_putchar(d);
        return (0);
    }

    my_putchar(a);
    my_putchar(b);
    my_putchar(' ');
    my_putchar(c);
    my_putchar(d);
    my_putchar(',');
    my_putchar(' ');
}