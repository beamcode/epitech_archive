/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** hardware
*/

#include "hardware.hpp"

const std::string hardware::path = "/proc/cpuinfo";

hardware::hardware()
{
    getNames();
}

hardware::~hardware()
{

}

void hardware::getNames()
{
    std::ifstream file(path);
	std::string line;

    while (std::getline(file, line)) {
        if (line.find("model name	: ") != std::string::npos)
            this->_model = line.substr(line.find("model name	: ") + 13);
        if (line.find("cache size	: ") != std::string::npos)
            this->_cache = line.substr(line.find("cache size	: ") + 13);
        if (line.find("cpu MHz		: ") != std::string::npos)
            this->_freq = line.substr(line.find("cpu MHz		: ") + 11);
        if (line.find("vendor_id	: ") != std::string::npos)
            this->_vendor = line.substr(line.find("vendor_id	: ") + 12);
        if (line.find("cpu cores	: ") != std::string::npos)
            this->_cores = line.substr(line.find("cpu cores	: ") + 12);
	}
}