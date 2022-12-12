/*
** EPITECH PROJECT, 2020
** myputerr
** File description:
** ok
*/

#include "my.h"

void my_puterr(char const *error)
{
    write(2, error, my_strlen(error));
}
