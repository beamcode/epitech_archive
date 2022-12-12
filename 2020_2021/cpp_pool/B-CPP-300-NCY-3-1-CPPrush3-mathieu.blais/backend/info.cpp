/*
** EPITECH PROJECT, 2021
** info
** File description:
** cppoolrus3
*/

#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <string>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include "info.hpp"

info::info()
{
}

info::~info()
{
}

bool info::is_time_legit()
{
    time_t ct = time(0);
    std::string cc;
    if (!ct)
        return (false);
    cc = ctime(&ct);
    if (cc == "")
        return (false);
    this->_time = cc;
    return (true);
}

const std::string info::get_user()
{
  if (this->is_uname_legit() == true)
        return (this->_utsname.nodename);
    else
        return (nullptr);
}

std::string info::get_time()
{
    if (this->is_time_legit() == true)
        return (this->_time);
    else
        return (nullptr);
}

bool info::is_uname_legit()
{
    struct utsname my_uname;

    if (uname(&my_uname) == -1)
        return (false);
    else
        this->_utsname = my_uname;
    return (true);
}

const std::string info::get_sys()
{
    if (is_uname_legit() == true)
        return (this->_utsname.sysname);
    else
        return (nullptr);
}

const std::string info::get_machine()
{
    if (is_uname_legit() == true)
        return (this->_utsname.machine);
    else
        return (nullptr);
}

bool info::is_name_legit()
{
    std::string name;

    name = getlogin();
    if (name == "")
        return (false);
    else
        this->_name = name;
    return (true);
}

const std::string info::get_uname ()
{
    if (this->is_name_legit() == false)
        return (nullptr);
    else
        return (this->_name);
}

const std::string info::get_version()
{
    if (is_uname_legit() == true)
        return (this->_utsname.version);
    else
        return (nullptr);
}
