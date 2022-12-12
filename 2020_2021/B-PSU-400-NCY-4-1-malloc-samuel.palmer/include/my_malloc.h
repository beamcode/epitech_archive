/*
** EPITECH PROJECT, 2021
** my_malloc.h
** File description:
** malloc
*/

#ifndef MALLOC_H_
#define MALLOC_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define block 32

typedef struct s_block *t_block;

struct s_block {
    t_block next;
    size_t size;
    bool avlb;
};

void free (void *ptr);
void *malloc (size_t size);
void *realloc (void *ptr, size_t size);
void *calloc (size_t nmemb, size_t size);
void *reallocarray (void *ptr, size_t nmemb, size_t size);

#endif /* !MALLOC_H_ */
