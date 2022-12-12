/*
** EPITECH PROJECT , 2019
** 
** File description :
**
*/

#include <unistd.h>

int my_print_alpha(void);

int main()
{
    my_print_alpha();
}

int my_putchar(char c)
{
    write(1, &c, 1);
}