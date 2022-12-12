/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** malloc
*/

#include "my_malloc.h"

void *realloc(void *ptr, size_t size)
{
    void *keep = ptr;
    t_block keep_second = (void *)keep - block;

    if (!ptr)
        return (malloc(size));
    if (size == 0 && ptr) {
        free(ptr);
        return (NULL);
    }
    free(ptr);
    ptr = malloc(size);
    if (size > keep_second->size) {
        ptr = memcpy(ptr, keep, size);
        return (ptr);
    }
    if (size > keep_second->size) {
        ptr = memcpy(ptr, keep, keep_second->size);
        return (ptr);
    }
    return (ptr);
}

void *calloc(size_t nmemb, size_t size)
{
    void *ptr = malloc(size * nmemb);

    memset(ptr, 0, size * nmemb);
    return (ptr);
}