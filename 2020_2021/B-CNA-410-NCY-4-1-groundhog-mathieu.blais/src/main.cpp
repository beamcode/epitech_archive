/*
** EPITECH PROJECT, 2021
** B-CNA-410-NCY-4-1-groundhog-mathieu.blais
** File description:
** Main
*/

#include "groundhog.hpp"

bool is_num(const char *s)
{
    for (const char *i = s; *i; i++)
        if (!isdigit(*i))
            return (false);
    return (true);
}

int main(int ac, char **av)
{
    if (ac != 2 || !is_num(av[1]) || atoi(av[1]) < 1) {
        std::cout << "SYNOPSIS\n\t./groundhog period\n\nDESCRIPTION\n\tperiod\tthe number of days defining a period" << std::endl;
        return (84);
    }
    Groundhog tmp;
    return (tmp.loop(atoi(av[1])));
}