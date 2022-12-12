/*
** EPITECH PROJECT, 2021
** ex02.hpp
** File description:
** ex02
*/

#ifndef EX02_HPP_
#define EX02_HPP_

int min(int a, int b)
{
    std::cout << "non-template min" << std::endl;
    if (a <= b)
        return (a);
    return (b);
}

template<typename T>
const T & min(const T &a, const T &b)
{
    std::cout << "template min" << std::endl;
    if (a <= b)
        return (a);
    return (b);
}

template<typename T>
const T &templateMin(const T *a, int size)
{
    T &m = const_cast<T&>(a[0]);

    for (int i = 1; i < size; i++)
        m = min<T>(m, a[i]);
    return (m);
}


int nonTemplateMin(const int *a, int size)
{
    int m = a[0];

    for (int i = 1; i < size; i++)
        m = min(m, a[i]);
    return (m);
}

#endif /* !EX02_HPP_ */
