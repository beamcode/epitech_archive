/*
** EPITECH PROJECT, 2021
** add_mul.c
** File description:
** This is second day of c++ pool
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
    return;
}

void add_mul_2param(int *first, int *second)
{
    int tmp = *first;
    int pmt = *second;

    *first = tmp + pmt;
    *second = tmp * pmt;
    return;
}
