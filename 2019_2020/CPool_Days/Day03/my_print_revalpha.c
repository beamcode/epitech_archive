/*
** EPITECH PROJECT , 2019
** my_put_revalpha
** File description :
**
*/

int my_putchar(char c);

int my_print_revalpha(void)
{
    int a = 122;

    while (a >= 'a')
    {
        my_putchar(a);
        a--;
    }
    return (0);
}