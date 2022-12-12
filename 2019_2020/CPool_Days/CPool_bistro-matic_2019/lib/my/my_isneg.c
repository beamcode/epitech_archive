/*
** EPITECH PROJECT, 2019
** my_isneg.c
** File description:
** Determins if int is positive or negative
*/

void my_putchar(char c);

int my_isneg(int n)	
{
	if (n < 0)
		my_putchar('N');
       	else
		my_putchar('P');
	return (0);
}