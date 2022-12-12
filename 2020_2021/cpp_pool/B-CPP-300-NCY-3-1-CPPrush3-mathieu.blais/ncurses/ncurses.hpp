/*
** EPITECH PROJECT, 2021
** header.hpp
** File description:
** header
*/

#ifndef HEADER_HPP_
#define HEADER_HPP_

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <unistd.h>
#include <ctime>
#include <vector>

#include <ncurses.h>
#include <sys/statvfs.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>

#include "../backend/cpu.hpp"
#include "../backend/ram.hpp"
#include "../backend/hardware.hpp"
#include "../backend/info.hpp"

int start_ncurses(); 

#endif /* !HEADER_HPP_ */
