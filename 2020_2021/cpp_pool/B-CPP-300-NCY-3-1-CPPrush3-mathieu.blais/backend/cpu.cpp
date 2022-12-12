/*
** EPITECH PROJECT, 2021
** core
** File description:
** cppoolrush3
*/

#include <chrono>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <thread>
#include <vector>
#include <sys/sysinfo.h>
#include "cpu.hpp"
#include <algorithm>

const std::string cpu::path = "/proc/stat";
const std::string cpu::_cpu = "cpu";
const std::string cpu::_total = "tot";

cpu::cpu()
{
	this->_len_cpu = 3;
}
cpu::~cpu()
{
}

bool cpu::isCpu(const std::string & line)
{
	if(line.compare(0, this->_len_cpu, this->_cpu) == 0)
		return (true);
	else
		return (false);
}

int cpu::get_number_cpu() {
  return sysconf(_SC_NPROCESSORS_ONLN);
}

std::string cpu::more_space_string(std::string in)
{
    std::string newname;
    for(size_t i = 0; i < in.size(); i++)
    {
        if( in[i] == ' ' && i != 0)
            newname += "   ";
        newname += in[i];
    }
    return newname;
}

void cpu::refresh()
{
	std::ifstream file(path);
	std::string line;

	while (std::getline(file, line)) {
		if (cpu::isCpu(line) == true)
			victor.push_back(line);
	}
	total = std::move(victor.front());
    total = more_space_string(total);
	victor.erase(victor.begin());
	for (auto& value: victor) 
		value = more_space_string(value);
}

std::string const &cpu::getTotal() const
{
	return (this->total);
}

std::vector<std::string> const &cpu::getcpu() const
{
	return (this->victor);
}