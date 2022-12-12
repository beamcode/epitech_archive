/*
** EPITECH PROJECT , 2019
** my_put_alpha
** File description :
**
*/

int my_putchar(char c);

int my_print_alpha(void)
{
    int a = 97;

    while (a <= 'z')
    {
        my_putchar(a);
        a++;
    }
    return (0);
}