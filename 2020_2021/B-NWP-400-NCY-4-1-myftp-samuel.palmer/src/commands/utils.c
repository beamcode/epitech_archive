/*
** EPITECH PROJECT, 2021
** utils.c
** File description:
** utils
*/

#include "../../include/my_ftp.h"

void send_message(int dst, char *msg)
{
    write(dst, msg, strlen(msg));
}