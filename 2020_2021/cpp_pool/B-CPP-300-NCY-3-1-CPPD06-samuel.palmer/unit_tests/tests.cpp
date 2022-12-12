/*
** EPITECH PROJECT, 2021
** tests.c
** File description:
** This is day 6 of c++ pool
*/

#include <criterion/criterion.h>

Test(string, default_value)
{
    std::string s;
    cr_assert_eq(s, "");
}

Test(string, assign)
{
    std::string s;
    s = "test";
    cr_assert_eq(s, "test");
}

Test(string, append)
{
    std::string s("test");
    s += "ing";
    cr_assert_eq(s, "testing");
}