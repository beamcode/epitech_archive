#include <iostream>
#include <string>
#include "ex02.hpp"

int main()
{
    //char tab[2] = {'c', 'd'};
    //char minimum = templateMin(tab, 2);
    //cout << "templateMin(tab , 2) = " << minimum << endl;
    //minimum = nonTemplateMin(tab, 2);
    //cout << "nonTemplateMin(tab , 2) = " << minimum << endl;
    std::cout << min<>(56, 12) << std::endl;
}