/*
** EPITECH PROJECT , 2019
** 
** File description :
**
*/

#include <unistd.h>

int my_print_digit();

int main()
{
    my_print_digit();
}

int my_putchar(char c)
{
    write(1, &c, 1);
}