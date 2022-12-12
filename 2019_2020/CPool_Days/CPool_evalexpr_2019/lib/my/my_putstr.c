/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** my_putstr.c
*/

void my_putchar(char c);

int my_putstr(char const *str)
{
    int a = 0;
    
    for(; str[a] != '\0' ; a++) {
        my_putchar(str[a]);
    }
    return a;
}