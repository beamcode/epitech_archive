/*
** EPITECH PROJECT, 2019
** my_dec_to_oct.c
** File description:
** int(dec) to oct
*/

int my_dec_to_oct(int decimalNumber)
{
    int octalNumber = 0;
    int i = 1;

    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }
    return octalNumber;
}