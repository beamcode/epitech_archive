/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** hardware
*/

#ifndef HARDWARE_HPP_
#define HARDWARE_HPP_

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <stdlib.h>

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <istream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <thread>
#include <unistd.h>
#include <sys/utsname.h>

class hardware {
    public:
        hardware();
        ~hardware();

        std::string getVendor() const { return _vendor; }
        std::string getModel() const { return _model; }
        std::string getFreq() const { return _freq; }
        std::string getCores() const { return _cores; }
        std::string getCache() const { return _cache; }
        void getNames();
        static const std::string path;
    private:
        std::string _vendor;
        std::string _model;
        std::string _freq;
        std::string _cores;
        std::string _cache;
};

#endif /* !HARDWARE_HPP_ */
