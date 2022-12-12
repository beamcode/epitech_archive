/*
** EPITECH PROJECT, 2021
** find.hpp
** File description:
** find
*/

#ifndef FIND_HPP_
#define FIND_HPP_

#include <algorithm>

template<typename T>
typename T::iterator do_find(T &a, int b)
{
    return (std::find(a.begin(), a.end(), b));
}

#endif /* !FIND_HPP_ */
