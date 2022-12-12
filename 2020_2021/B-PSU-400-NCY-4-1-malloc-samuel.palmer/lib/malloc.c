/*
** EPITECH PROJECT, 2021
** malloc.c
** File description:
** malloc
*/

#include "my_malloc.h"

static t_block tmp;

void free(void *ptr)
{
    t_block tmp;

    if (ptr == NULL)
        return;
    tmp = (void *)ptr - block;
    tmp->avlb++;
}

void add_heap(size_t pages)
{
    t_block new = tmp;

    if (!tmp) {
        tmp = sbrk(0);
        if ((void *) -1 == tmp)
            return;
        sbrk(pages);
        return;
    }
    sbrk(pages);
    while (new->next)
        new = new->next;
    new->size += pages;
}

void *assign_single(size_t size, size_t pages)
{
    tmp->avlb = false;
    tmp->size = size;

    tmp->next = (void *)tmp + (block + size);
    tmp->next->size = (pages - block) - size;
    tmp->next->next = NULL;
    tmp->next->avlb = true;
    return ((void *)tmp + block);
}

void *assign_nodes(size_t size, size_t pages)
{
    t_block new = tmp;

    if (!tmp->next)
        return (assign_single(size, pages));
    else {
        for (; new->next; new = new->next);
        if (!(new->size > size + block))
            add_heap(pages);
        new->avlb = true;
        new->next = (void *)new + block + size;
        new->next->size = (new->size - block) - size;
        new->next->avlb = false;
        new->next->next = NULL;
        new->size = size;
    }
    return ((void *)new + block);
}

void *malloc(size_t size)
{
    size_t page_size = getpagesize() * 2;
    size_t pages = page_size;
    t_block keep = tmp;

    if (size % 2 != 0)
        size += 1;
    for (;pages < size + (block * 2); pages += page_size);
    if (!tmp) {
        add_heap(pages);
        return assign_nodes(size, pages);
    }
    for (; keep->next ; keep = keep->next)
        if (keep->size == size && !keep->avlb)
            return (block + (void *)keep);
    return (assign_nodes(size, pages));
}