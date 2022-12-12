/*
** EPITECH PROJECT, 2019
** my_swap.c
** File description:
** my_swap.c
*/

void my_swap(int *a, int *b)
{
    int c = *a;
    
    *a = *b;
    *b = c;
}