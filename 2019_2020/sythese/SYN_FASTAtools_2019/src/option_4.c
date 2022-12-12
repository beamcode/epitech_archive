/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "../include/my.h"

void sort_alpha_kerms(char **str)
{
    char *tmp = NULL;

    for (int i = 0; str[i]; i++) {
        for (int t = i + 1; str[t]; t++) {
            if (strcmp(str[i], str[t]) > 0) {
                tmp = strdup(str[i]);
                strcpy(str[i], str[t]);
                strcpy(str[t], tmp);
                free(tmp);
                tmp = NULL;
            }
        }
    }
}

void generate_kmers(char *str, char **kmers, int k)
{
    static int t = 0;
    char *tmp = NULL;

    for (int i = 0, a = 0; str[i] != '\0'; i++, a = 0) {
        if (strlen(str) - i >= k) {
            tmp = malloc(sizeof(char) * (k + 1));
            strncpy(tmp, str + i, k);
            for (int f = 0; kmers[f]; f++) {
                if (strcmp(kmers[f], tmp) == 0)
                    a = 1;
            }
            if (a == 0) {
                kmers[t] = malloc(sizeof(char) * (k + 1));
                strncpy(kmers[t], str + i, k);
                kmers[t][k] = '\0';
                t++;
            }
            tmp = NULL;
        }
    }
    kmers[t] = NULL;
}

void process_four(char **str, char **kmers, int k)
{
    for (int i = 0; str[i]; i++) {
        if (strchr(str[i], '>') != NULL)
            continue;
        generate_kmers(str[i], kmers, k);
    }
    sort_alpha_kerms(kmers);
}

void do_four(char **str, int k)
{
    char **kmers = malloc(sizeof(char *) * 2048);
    memset(kmers, 0, sizeof(char *) * 2048);

    process_one(str);
    process_four(str, kmers, k);
    my_putarray(kmers);
    for (int b = 0; kmers[b]; b++)
        free(kmers[b]);
}