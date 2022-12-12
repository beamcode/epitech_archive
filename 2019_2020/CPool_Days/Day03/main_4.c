/*
** EPITECH PROJECT , 2019
** 
** File description :
**
*/

#include <unistd.h>

int my_isneg();

int main()
{
    my_isneg(-3);
}

int my_putchar(char c)
{
    write(1, &c, 1);
}