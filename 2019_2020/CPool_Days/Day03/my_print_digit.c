/*
** EPITECH PROJECT , 2019
** my_print_digit
** File description :
**
*/

int my_putchar(char c);

int my_print_digit(void)
{
    int a = 48;

    while (a <= 57)
    {
        my_putchar(a);
        a++;
    }
    return (0);
}