/*
** EPITECH PROJECT, 2021
** ex01.hpp
** File description:
** ex01
*/

#ifndef EX01_HPP_
#define EX01_HPP_

#include <iostream>
#include <string>
#include <cstring>

template<typename T>
int compare(const T &a, const T &b)
{
    if (a == b)
        return (0);
    if (a < b)
        return (-1);
    return (1);
}

template<>
int compare<const char *>(const char * const &a, const char * const &b)
{
    if (strcmp(a, b) < 0)
        return (-1);
    else if (strcmp(a, b) == 0)
        return (0);
    return (1);
}

#endif /* !EX01_HPP_ */