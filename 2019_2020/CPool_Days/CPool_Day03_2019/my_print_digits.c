/*
** EPITECH PROJECT , 2019
** my_print_alpha
** File description :
** task02
*/

void my_putchar(char c);

int     my_print_digits(void)	
{
  char  digits;

  digits = 48;
  while (digits <= 57)
  {
	  my_putchar(digits);
	  digits = digits + 1;
  }
}
