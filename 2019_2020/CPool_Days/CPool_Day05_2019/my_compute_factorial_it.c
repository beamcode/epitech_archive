/*
** EPITECH PROJECT , 2019
** my_compute_factorial_rec
** File description :
** task02
*/

int my_compute_factorial_it(int nb)
{
    int a = 1;
    int b = 1;
    
    if (nb < 0 || nb >= 13)
    {
		return(0);
	}
    if (nb == 0)
    {
		return(1);
	}
    while (a <= nb)
    {
        b = b * a;
        a++;
    }
    return (b);
}