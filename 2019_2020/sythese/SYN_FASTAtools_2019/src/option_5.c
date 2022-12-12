/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "../include/my.h"

int check_end_seq(char *str, int i)
{
    if (str[i] == 'T' && str[i + 1] == 'A' && str[i + 2] == 'A')
        return (1);
    if (str[i] == 'T' && str[i + 1] == 'A' && str[i + 2] == 'G')
        return (1);
    if (str[i] == 'T' && str[i + 1] == 'G' && str[i + 2] == 'A')
        return (1);
    return (0);
}

void find_codon(char *str, char **cod)
{
    static int t = 0;
    char *tmp = "\0";
    char *qw = strdup("000\0");
    int bounds = strlen(str);

    for (int g = 0; g < bounds ; g++, tmp = "\0") {
        for (int i = g; i < (bounds - 1); i += 3) {
            if (check_end_seq(str, i) == 1 &&
                (tmp[0] == 'A' && tmp[1] == 'T' && tmp[2] == 'G')) {
                cod[t] = strdup(tmp);
                tmp = "\0";
                t++;
                break;
            }
            for (int v = 0; v <= 2; qw[v] = str[i + v], v++);
            tmp = my_strcat_dup(tmp, qw);
        }
    }
    cod[t] = NULL;
}

void process_five(char **str, char **cod)
{
    for (int i = 0; str[i]; i++) {
        if (strchr(str[i], '>') != NULL)
            i++;
        find_codon(str[i], cod);
    }
}

void do_five(char **str)
{
    char **cod = malloc(sizeof(char *) * 2048);
    cod[0] = NULL;

    if (cod == NULL)
        return;
    process_one(str);
    process_five(str, cod);
    process_three(str);
    process_five(str, cod);
    sort_alpha(cod);
    my_putarray(cod);
    for (int b = 0; cod[b]; b++)
        free(cod[b]);
}