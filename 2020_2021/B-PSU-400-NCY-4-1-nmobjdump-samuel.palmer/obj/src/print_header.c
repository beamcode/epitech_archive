/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** Main
*/

#include "../include/objdump.h"

char *get_name(int num)
{
    const flags_t flag_names[] = {
        {HAS_RELOC, "HAS_RELOC"},
        {HAS_SYMS, "HAS_SYMS"},
        {DYNAMIC, "DYNAMIC"},
        {D_PAGED, "D_PAGED"},
        {EXEC_P, "EXEC_P"}};

    for (int i = 0; i < 5; i++)
        if (num == flag_names[i].index)
            return flag_names[i].name;
    return ("UNKNOWN");
}

void dump_flags(uint32_t flags)
{
    int first = 1;

    for (int i = 1; i <= 0x100; i *= 2) {
        if ((flags & i) != 0) {
            if (first) {
                printf("%s", get_name(i));
                first = 0;
            }
            else
                printf(", %s", get_name(i));
        }
    }
}

uint32_t create_flags(elf_t *elf)
{
    char *sh;
    uint32_t flags = 0;

    flags = flags | (elf->ehdr->e_type == ET_REL ? (unsigned) HAS_RELOC : 0);
    flags = flags | (elf->ehdr->e_type == ET_EXEC ? (unsigned) EXEC_P : 0);
    flags = flags | (elf->ehdr->e_type == ET_DYN ? (unsigned) DYNAMIC : 0);
    flags = flags | (elf->ehdr->e_phnum ? (unsigned) D_PAGED : 0);
    if (elf->strtab != NULL) {
        for (int i = 0; i < elf->ehdr->e_shnum; i++) {
            sh = elf->strtab + elf->shdr[i].sh_name;
            if (strcmp(sh, ".symtab") == 0 ||
                strcmp(sh, ".dynsym") == 0) {
                flags = flags | (unsigned)HAS_SYMS;
                break;
            }
        }
    }
    return (flags);
}

int print_header(elf_t *val)
{
    uint32_t flags = create_flags(val);

    printf("\n%s:     file format elf64-x86-64\n", val->name);
    printf("architecture: i386:x86-64, flags 0x%08x:\n", flags);
    dump_flags(flags);
    printf("\nstart address 0x%016lx\n\n", (unsigned long)val->ehdr->e_entry);
    return (0);
}