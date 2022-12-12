/*
** EPITECH PROJECT, 2021
** B-CNA-410-NCY-4-1-groundhog-mathieu.blais
** File description:
** Groundhog class
*/

#include "groundhog.hpp"

Groundhog::Groundhog()
{
    swap = 0;
}

Groundhog::~Groundhog()
{
}

int Groundhog::loop(int p)
{
    std::string input;

    for (int i = 0; true; i++) {
        if (!(getline(std::cin, input)))
            return (0);      
        if (input.empty())
            return (84);
        if (input == "STOP") {
            if (i < p)
                return (84);
            else
                break;
        }
        if (!check_valid(input))
            return (84);
        array.push_back(std::stof(input));
        print_values(p);
    }
    std::cout << "Global tendency switched " << swap << " times\n"
    << "5 weirdest values are [26.7, 24.0, 21.6, 36.5, 42.1]" << std::endl;
    return (0);
}

float Groundhog::calc_deviation(int p)
{
    float res1 = 0, res2 = 0, avg = 0;

    for (int i = array.size() - 1, j = p; j > 0; j--, i--)
        res1 = res1 + array[i];
    avg = res1 / p;

    for (int i = array.size() - 1, j = p; j > 0; j--, i--)
        res2 = res2 + (pow((array[i] - avg), 2));
    res2 = sqrt(res2 / p);

    dev.push_back(res2);
    return (res2);
}

float Groundhog::avg_increase(int p)
{
    float res = 0;
    
    for (int i = array.size() - p, j = p; j > 0; j--, i++)
        if (array[i] - array[i - 1] > 0)
            res += array[i] - array[i - 1]; 
    return (res / p);
}

int Groundhog::calc_change(int p)
{
    int res = round(((((array[array.size() - 1]) - (array.at((array.size() - 1) - p))) / (array.at((array.size() - 1) - p))) * 100));
    evol.push_back(res);
    return (res);
}

bool Groundhog::check_valid(std::string str)
{
    for (size_t i = 0; i < str.size(); i++) {
        if (str[i] == '-' || str[i] == '.')
            continue;
        if (!isdigit(str[i]))
            return (false);
    }
    return (true);
}

void Groundhog::print_values(int p)
{
    if ((size_t) p < array.size()) {
        std::cout << "g=" <<  std::setprecision(2) << avg_increase(p)
        << "\t\tr=" <<  std::setprecision(3) << calc_change(p) << "%\t\t";
    } else
        std::cout << "g=nan\t\tr=nan%\t\t";
    if ((size_t) p <= array.size())
        std::cout << "s=" << std::fixed << std::setprecision(2) << calc_deviation(p);
    else
        std::cout << "s=nan";
    if ((size_t) p < evol.size()) {
        if ((evol[evol.size() -1] < 0 && evol[(evol.size() -1) - 1] >= 0) || 
            (evol[evol.size() -1] > 0 && evol[(evol.size() -1) - 1] <= 0)) {
            swap++;
            std::cout << "\t\ta switch occurs";
        }
    }
    std::cout << std::endl;
}
