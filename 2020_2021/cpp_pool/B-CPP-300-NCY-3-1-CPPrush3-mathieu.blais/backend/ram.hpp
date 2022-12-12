/*
** EPITECH PROJECT, 2021
** ram
** File description:
** cppoolrush3
*/

#ifndef _RAM_
#define _RAM_

#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <iostream>

class ram {
    public:
        ram();
        ~ram();
        int get_free_ram();
        int get_shared_ram();
        int get_total_ram();
        struct sysinfo _sysinfo;
    private:
        bool is_legit();
};

#endif /* !_RAM_ */
