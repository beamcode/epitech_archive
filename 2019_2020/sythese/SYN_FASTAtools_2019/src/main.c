/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "../include/my.h"

int check_error(int ac, char **av)
{
    if (ac < 2 || ac > 3)
        return (84);
    if (strlen(av[1]) != 1 || (av[1][0] < '1' || av[1][0] > '7'))
        return (84);
    if (av[1][0] == '4' && ac != 3)
        return (84);
    return (0);
}

char *get_stdin(void)
{
    char *line = NULL;
    char *string = "\0";
    size_t len;

    while (getline(&line, &len, stdin) != -1) {
        string = my_strcat_dup(string, line);
        if (string == NULL)
            return (NULL);
    }
    return (string);
}

void free_all(char **dna, char *str)
{
    for (int b = 0; dna[b]; b++)
        free(dna[b]);
    free(str);
}

int main(int ac, char **av)
{
    char **dna = NULL;
    char *string = NULL;

    if (check_error(ac, av) == 84)
        return (84);
    string = get_stdin();
    if (string == NULL)
        return (84);
    dna = str_to_wordtab(string, '\n');
    dna = organize_data(dna);

    select_option(av, dna);
    free_all(dna, string);
    return (0);
}