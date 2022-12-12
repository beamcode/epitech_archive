/*
** EPITECH PROJECT, 2021
** misc_list.c
** File description:
** This is day 2 of c++ pool
*/

#include <stdlib.h>
#include <stdio.h>
#include "double_list.h"

void double_list_dump(double_list_t list)
{
    for (; list != NULL; list = list->next)
        printf("%f\n", list->value);
}

bool double_list_is_empty(double_list_t list)
{
    return (list == NULL ? true : false);
}

int  main(void)
{
    double_list_t list_head = NULL;
    doublelist_node_t *node3 = malloc(sizeof(*node3));

    double_list_add_elem_at_back (&list_head , 4);
    double_list_add_elem_at_front (&list_head , 3);
    double_list_add_elem_at_back (&list_head , 10);
    double_list_add_elem_at_front (&list_head , 8);
    double_list_add_elem_at_position(&list_head, 77, 2);
    double_list_add_elem_at_position(&list_head, 126, 0);
    double_list_add_elem_at_position(&list_head, 11, 6);
    double_list_del_elem_at_position(&list_head, 0);
    double_list_del_elem_at_position(&list_head, 5);
    double_list_del_elem_at_position(&list_head, 3);
    double_list_del_elem_at_position(&list_head, 0);
    printf("==>%f\n", double_list_get_elem_at_position (list_head, 2));

    node3 = double_list_get_first_node_with_value(list_head, 1);
   // printf("node == %f\n", node3->value);
    printf("size ==> %d\n", double_list_get_size(list_head));
    double_list_dump(list_head);

    return (0);
}