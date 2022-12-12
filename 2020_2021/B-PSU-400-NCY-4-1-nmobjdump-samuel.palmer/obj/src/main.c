/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** Main
*/

#include "../include/objdump.h"

int check_format(const unsigned char ident[EI_NIDENT])
{
    if (!(ident == NULL) && \
        ident[EI_MAG0] == ELFMAG0 && \
        ident[EI_MAG1] == ELFMAG1 && \
        ident[EI_MAG2] == ELFMAG2 && \
        ident[EI_MAG3] == ELFMAG3)
        return (1);
    return (0);
}

elf_t *assign_val(elf_t *val, char *name)
{
    val->ehdr = (Elf64_Ehdr *)val->data;
    if (!check_format(val->ehdr->e_ident)) {
        fprintf(stderr, "%s: Unknown File format.\n", name);
        return (NULL);
    }
    val->shdr = (Elf64_Shdr *)((uint8_t *)val->data + val->ehdr->e_shoff);
    val->strtab = (char *)val->data + \
    val->shdr[val->ehdr->e_shstrndx].sh_offset;
    val->end = (void *)val->ehdr + val->len;
    val->name = name;
    return (val);
}

elf_t *extract_file(char *name)
{
    elf_t *val = malloc(sizeof(elf_t));
    struct stat st;
    int fd;

    if (lstat(name, &st) == -1)
        return (NULL);
    fd = open(name, O_RDONLY);
    if (fd == -1)
        return (NULL);
    val->data = mmap(NULL, st.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
    if (val->data == MAP_FAILED)
        return (NULL);
    val->len = lseek(fd, 0, SEEK_END);
    if (val->len == (size_t)-1)
        return (NULL);
    if (!(val = assign_val(val, name)))
        return (NULL);
    close(fd);
    return (val);
}

int main(int ac, char **av)
{
    if (ac != 2) {
        fprintf(stderr, "Must provide input file!\n");
        return (84);
    }
    elf_t *tmp = extract_file(av[1]);

    if (tmp == NULL)
        return (84);
    print_header(tmp);
    print_body(tmp);
    return (84);
}