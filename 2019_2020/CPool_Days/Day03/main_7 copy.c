/*
** EPITECH PROJECT , 2019
** 
** File description :
**
*/

#include <unistd.h>

int my_put_nbr();

int main()
{
    my_put_nbr(54);
}

int my_putchar(char c)
{
    write(1, &c, 1);
}