/*
** EPITECH PROJECT, 2021
** main.cpp
** File description:
** This is day 6 of c++ pool
*/

#include <iostream>
#include <iomanip>

int main(int ac, char **av)
{
    std::string first;
    std::string second;
    double res = 0;
    int padding = 16;

    std::cin >> first;
    std::cin >> second;

    if (second == "Celsius" || second == "celsius") {
        res = (((std::atof(first.c_str()) * 9) / 5) + 32);
        std::cout << std::setw(padding) << std::fixed;
        std::cout << std::fixed << std::setprecision(3) << res;
        std::cout << std::setw(padding) << std::fixed;
        std::cout << "Fahrenheit" << std::endl;
        return (0);
    }
    if (second == "Fahrenheit" || second == "fahrenheit") {
        res = 5.0 / 9.0 * (std::atof(first.c_str()) - 32);
        std::cout << std::setw(padding) << std::fixed;
        std::cout << std::fixed << std::setprecision(3) << res;
        std::cout << std::setw(padding) << std::fixed;
        std::cout << "Celsius" << std::endl;
        return (0);
    }
    return (84);
}