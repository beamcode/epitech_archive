/*
** EPITECH PROJECT , 2019
** my_compute_power_rec
** File description :
** task04
*/

#include <stdio.h>

int my_compute_power_rec(int nb, int p)
{
    if (nb == 0 || p == 0)
    {
		return(1);
	}
    if (p < 0)
    {
		return(0);
	}
    return (nb * my_compute_power_rec(nb, p - 1));
}