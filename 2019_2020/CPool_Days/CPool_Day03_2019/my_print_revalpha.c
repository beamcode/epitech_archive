/*
** EPITECH PROJECT , 2019
** my_print_alpha
** File description :
** task02
*/

void my_putchar(char c);

int     my_print_revalpha(void)	
{
  char  revalpha;

  revalpha = 122;
  while (revalpha >= 97 )
  {
	  my_putchar(revalpha);
	  revalpha = revalpha - 1;
  }
}
