/*
** EPITECH PROJECT, 2021
** get_list.c
** File description:
** This is day 2 of c++ pool
*/

#include <stdlib.h>
#include <stdio.h>
#include "double_list.h"

double double_list_get_elem_at_front(double_list_t list)
{
    return (!list ? 0 : list->value);
}

unsigned int double_list_get_size(double_list_t list)
{
    unsigned int a = 0;

    for ( ; list != NULL; a++)
        list = list->next;
    return (a);
}

doublelist_node_t *double_list_get_first_node_with_value(double_list_t list,
double value)
{
    double_list_t head = list;

    if (head == NULL)
        return (NULL);

    for (unsigned int i = 0; head != NULL; i++) {
        if (head->value == value)
            return (head);
        head = head->next;
    }
    return (NULL);
}

double double_list_get_elem_at_position(double_list_t list, unsigned int
position)
{
    double_list_t head = list;

    if (head == NULL)
        return (0);
    if (position == 0)
        return (double_list_get_elem_at_front(head));
    for (unsigned int i = 0; i < position; i++) {
        if (head == NULL)
            return (0);
        head = head->next;
    }
    return (head->value);
}

double double_list_get_elem_at_back(double_list_t list)
{
    double_list_t head = list;

    if (head == NULL)
        return (0);
    while (head->next != NULL) {
        head = head->next;
        if (head->next == NULL)
            return (head->value);
    }
    return (0);
}