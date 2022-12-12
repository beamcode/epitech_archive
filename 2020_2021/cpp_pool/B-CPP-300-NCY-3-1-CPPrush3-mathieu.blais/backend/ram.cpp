/*
** EPITECH PROJECT, 2021
** ram
** File description:
** cppoolrush3
*/

#include "ram.hpp"

ram::ram() 
{
}

ram::~ram()
{

}

bool ram::is_legit()
{
    struct sysinfo info;
    if (sysinfo(&info) == -1) {
      return (false);
    } else
        this->_sysinfo = info;
    return (true);
}

int ram::get_total_ram()
{
    if (this->is_legit() == true)
        return (this->_sysinfo.totalram / 1024 / 1024);
    else
        return (0);
}

int ram::get_free_ram()
{
    if (this->is_legit() == true)
        return (this->_sysinfo.freeram / 1024 / 1024);
    else
        return (0);
}
int ram::get_shared_ram()
{
    if (this->is_legit() == true)
        return (this->_sysinfo.sharedram / 1024 / 1024);
    else
        return (0);
}
