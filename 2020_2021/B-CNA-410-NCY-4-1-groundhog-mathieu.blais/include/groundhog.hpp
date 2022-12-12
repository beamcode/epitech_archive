/*
** EPITECH PROJECT, 2021
** B-CNA-410-NCY-4-1-groundhog-mathieu.blais
** File description:
** Groundhog Hpp
*/

#ifndef GROUNDHOG_HPP_
#define GROUNDHOG_HPP_

#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <iomanip>
#include <vector>
#include <string>
#include <math.h>

class Groundhog {
    public:
        //Ctor & Dtor
        Groundhog();
        ~Groundhog();
        
        //Members
        bool check_valid(std::string str);
        float calc_deviation(int p);
        float avg_increase(int p);
        void print_values(int p);  
        int calc_change(int p);
        int loop(int p);

    protected:
    private:
        int swap;
        std::vector<float> array, evol, dev;
};

#endif /* !GROUNDHOG_HPP_ */
