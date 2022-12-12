/*
** EPITECH PROJECT, 2021
** ex00.hpp
** File description:
** ex00
*/

#ifndef EX00_HPP_
#define EX00_HPP_

template<typename T>
void swap(T &a, T &b)
{
    T c = a;
    a = b;
    b = c;
}

template<typename T>
T min(T &a, T &b)
{
    if (a >= b)
        return (b);
    return (a);
}

template<typename T>
T max(T &a, T &b)
{
    if (a <= b)
        return (b);
    return (a);
}

template<typename T>
T add(T &a, T &b)
{
    return (a + b);
}

#endif /* !EX00_HPP_ */