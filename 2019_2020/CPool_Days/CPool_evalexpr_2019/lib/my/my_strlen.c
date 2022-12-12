/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int a;
    
    for (a = 0; str[a] != '\0' ; a++);
    return(a); 
}