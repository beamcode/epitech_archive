/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** main.c
*/

#include "../include/my.h"

void sort_alpha(char **str)
{
    char *tmp = NULL;

    for (int i = 0; str[i]; i++) {
        for (int t = i + 1; str[t]; t++) {
            if (strcmp(str[i], str[t]) > 0) {
                tmp = strdup(str[i]);
                str[i] = strdup(str[t]);
                free(str[t]);
                str[t] = strdup(tmp);
                tmp = NULL;
            }
        }
    }
}

char search_amino_lib(char *str)
{
    char acid[65] = "AAAACCDDEEFFGGGGHHIIIKKLLLLLLMNNPPPPQQRRRRRRSSSSSSTT"
        "TTVVVVWYYOOOX";
    char cod[64][3] = {"GCT", "GCC", "GCA", "GCG", "TGT", "TGC",
        "GAT", "GAC", "GAA", "GAG", "TTT", "TTC", "GGT", "GGC", "GGA", "GGG",
        "CAT", "CAC", "ATT", "ATC", "ATA", "AAA", "AAG", "TTA", "TTG", "CTT",
        "CTC", "CTA", "CTG", "ATG", "AAT", "AAC", "CCT", "CCC", "CCA", "CCG",
        "CAA", "CAG", "AGA", "AGG", "CGT", "CGC", "CGA", "CGG", "TCT", "TCC",
        "TCA", "TCG", "AGT", "AGC", "ACT", "ACC", "ACA", "ACG", "GTT", "GTC",
        "GTA", "GTG", "TGG", "TAT", "TAC", "TAA", "TAG", "TGA"};
    int i = 0;

    while (strncmp(cod[i], str, 3) && i < 64)
        i++;
    return (acid[i]);
}

char *get_amino(char *str)
{
    int l = strlen(str) / 3;
    char *tmp = malloc(sizeof(char) * (l + 1));

    for (int a = 0; a < l; a++)
        tmp[a] = search_amino_lib(&str[a * 3]);
    tmp[l] = '\0';
    free(str);
    return (tmp);
}

void process_six(char **str)
{
    int i = 0;

    for (; str[i]; i++) {
        if (strchr(str[i], '>') != NULL)
            continue;
        str[i] = get_amino(str[i]);
    }
}

void do_six(char **str)
{
    char **cod = malloc(sizeof(char *) * 2048);
    cod[0] = NULL;

    if (cod == NULL)
        return;
    process_one(str);
    process_five(str, cod);
    process_three(str);
    process_five(str, cod);
    process_six(cod);
    sort_alpha(cod);

    my_putarray(cod);
    for (int b = 0; cod[b]; b++)
        free(cod[b]);
}