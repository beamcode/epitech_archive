/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** Main
*/

#include "../include/objdump.h"

void print_hexa(uint8_t *data, int size)
{
    for (int i = 0; i < 16; i++) {
        if (i < size)
            printf("%02x", data[i]);
        else
            printf("  ");
        if (!((i + 1) % 4))
            printf(" ");
    }
}

void print_ascii(uint8_t *data, int size)
{
    for (int i = 0; i < 16; i++) {
        if (i < size) {
            if (data[i] <= '~' && data[i] >= ' ')
                printf("%c", data[i]);
            else
                printf(".");
        }
        else
            printf(" ");
    }
}

void print_all(elf_t *val, int i, int t)
{
    printf(" %04x ", (int)(val->shdr[i].sh_addr + \
    t - val->shdr[i].sh_offset));
    print_hexa((unsigned char *)val->ehdr + t, \
    val->shdr[i].sh_offset + val->shdr[i].sh_size - t);
    printf(" ");
    print_ascii((unsigned char *)val->ehdr + t, \
    val->shdr[i].sh_offset + val->shdr[i].sh_size - t);
    printf("\n");
}

int print_body(elf_t *elf)
{
    for (int i = 0, t = 0; i < elf->ehdr->e_shnum; i++) {
        if ((void *)&elf->shdr[i] > elf->end ||
            (void *)&elf->strtab[elf->shdr[i].sh_name] > elf->end) {
            fprintf(stderr, "Error: invalid file\n");
            return (84);
        }
        if (((elf->shdr[i].sh_type == SHT_SYMTAB ||
            elf->shdr[i].sh_type == SHT_STRTAB ||
            elf->shdr[i].sh_type == SHT_NOBITS) &&
            strcmp(&elf->strtab[elf->shdr[i].sh_name], ".dynstr")) ||
            !elf->shdr[i].sh_size)
            continue;
        printf("Contents of section %s:\n", &elf->strtab[elf->shdr[i].sh_name]);
        t = elf->shdr[i].sh_offset;
        for (;(unsigned long int)t < elf->shdr[i].sh_offset + \
            elf->shdr[i].sh_size; t += 16) {
            print_all(elf, i, t);
        }
    }
    return (0);
}