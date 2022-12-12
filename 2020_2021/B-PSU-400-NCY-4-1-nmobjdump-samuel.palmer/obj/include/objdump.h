/*
** EPITECH PROJECT, 2021
** objdump.h
** File description:
** objdump
*/

#ifndef OBJDUMP_H_
#define OBJDUMP_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <string.h>
#include <elf.h>
#include "flags.h"

typedef struct elf_s {
    Elf64_Shdr *data;
    char *strtab;
    size_t fsize;
    Elf64_Ehdr *ehdr;
    Elf64_Shdr *shdr;
    void *end;
    size_t len;
    char *name;
} elf_t;

typedef struct flags_s {
    int index;
    char *name;
} flags_t;

int print_body(elf_t *elf);
int print_header(elf_t *elf);

#endif /* !OBJDUMP_H_ */
