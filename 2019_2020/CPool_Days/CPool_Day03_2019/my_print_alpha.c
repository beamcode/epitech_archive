/*
** EPITECH PROJECT , 2019
** my_print_alpha
** File description :
** task01
*/

int    my_print_alpha(void)
{
    char  alphabet;

    alphabet = 97;
    while (alphabet <= 122)
    {
        my_putchar(alphabet);
        alphabet = alphabet + 1;
    }
}
