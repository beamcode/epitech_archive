/*
** EPITECH PROJECT, 2021
** info
** File description:
** cppoolrush3
*/

#ifndef _INFO_
#define _INFO_

#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <iostream>

class info {
    public:
        info();
        ~info();
        const std::string get_sys();
        const std::string get_machine();
        std::string get_time();
        const std::string get_uname ();
        const std::string get_version();
        struct utsname _utsname;
        const std::string get_user();
        std::string _name;
        std::string _time;
    private:
        bool is_uname_legit();
        bool is_name_legit();
        bool is_time_legit();
};
#endif /* !_INFO_ */
