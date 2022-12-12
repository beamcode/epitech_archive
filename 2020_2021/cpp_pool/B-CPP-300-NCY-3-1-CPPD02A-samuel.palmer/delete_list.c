/*
** EPITECH PROJECT, 2021
** delete_list.c
** File description:
** This is day 2 of c++ pool
*/

#include <stdlib.h>
#include <stdio.h>
#include "double_list.h"

bool double_list_del_elem_at_position(double_list_t *front_ptr, unsigned int
position)
{
    double_list_t head = *front_ptr;
    double_list_t first = NULL;
    double_list_t second = NULL;

    if (head == NULL)
        return (false);
    if (position == 0)
        return (double_list_del_elem_at_front(front_ptr));

    for (unsigned int i = 0; i < position; i++) {
        if (head == NULL)
            return (false);
        first = head;
        head = head->next;
        second = head->next;
    }
    first->next = second;
    free(head);
    return (true);
}

bool double_list_del_elem_at_back(double_list_t *front_ptr)
{
    double_list_t head = *front_ptr;
    double_list_t second = NULL;

    if (head == NULL)
        return (false);

    while (head->next) {
        second = head;
        head = head->next;
    }
    second->next = NULL;
    free(head);
    return (true);
}

bool double_list_del_elem_at_front(double_list_t *front_ptr)
{
    double_list_t head = *front_ptr;

    if (head == NULL)
        return (false);
    *front_ptr = head->next;
    free(head);
    return (true);
}