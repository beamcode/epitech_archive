/*
** EPITECH PROJECT, 2019
** lol.c
** File description:
** ggtt
*/

int lol(int ac, char **av)
{
    if (ac == 2) {
        summands(&av[1]);
        return (0);
    }
    return (84);
}