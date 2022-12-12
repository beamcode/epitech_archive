/*
** EPITECH PROJECT, 2021
** main.c
** File description:
** This is day 6 of c++ pool
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

int cat(char *av)
{
    std::ifstream file(av);

    if(file) {
        std::string line;
        while (getline(file, line))
            std::cout << line << std::endl;
    }
    else
        return (-1);
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 2) {
        std::cerr << "my_cat: Usage: ./my_cat file [...]" << std::endl;
        return (0);
    }

    for (int i = 1; av[i]; i++) {
        if (cat(av[i]) == -1)
            std::cerr << "my_cat: " << av[i] << ": No such file or directory" << std::endl;
    }
    return (0);
}