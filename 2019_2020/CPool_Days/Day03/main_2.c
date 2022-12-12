/*
** EPITECH PROJECT , 2019
** 
** File description :
**
*/

#include <unistd.h>

int my_print_revalpha(void);

int main()
{
    my_print_revalpha();
}

int my_putchar(char c)
{
    write(1, &c, 1);
}