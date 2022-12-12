/*
** EPITECH PROJECT, 2021
** add_list.c
** File description:
** This is day 2 of c++ pool
*/

#include <stdlib.h>
#include <stdio.h>
#include "double_list.h"

bool double_list_add_elem_at_position(double_list_t *front_ptr, double elem,
unsigned int position)
{
    doublelist_node_t *new = malloc(sizeof(*new));
    double_list_t head = *front_ptr;
    double_list_t first = NULL;

    if (new == NULL)
        return (false);
    if (position == 0)
        return (double_list_add_elem_at_front(front_ptr, elem));
    for (unsigned int i = 0; i < position; i++) {
        if (head == NULL)
            return (false);
        first = head;
        head = head->next;
    }
    new->next = first->next;
    first->next = new;
    new->value = elem;
    return (true);
}

bool double_list_add_elem_at_back(double_list_t *front_ptr, double elem)
{
    double_list_t head = *front_ptr;
    doublelist_node_t *new = malloc(sizeof(*new));

    if (new == NULL)
        return (false);
    new->value = elem;
    new->next = NULL;
    if (*front_ptr != NULL) {
        while (head->next)
            head = head->next;
        head->next = new;
    }
    else
        *front_ptr = new;
    return (true);
}

bool double_list_add_elem_at_front(double_list_t *front_ptr, double elem)
{
    doublelist_node_t *new = malloc(sizeof(*new));

    if (new == NULL)
        return (false);
    new->value = elem;
    new->next = *front_ptr;
    *front_ptr = new;
    return (true);
}