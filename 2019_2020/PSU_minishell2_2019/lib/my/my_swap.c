/*
** EPITECH PROJECT, 2019
** my_swap.c
** File description:
** Reverses an int
*/

void my_swap(int *a, int *b)
{
    int name1;

    name1 = *a;
    *a = *b;
    *b = name1;
}