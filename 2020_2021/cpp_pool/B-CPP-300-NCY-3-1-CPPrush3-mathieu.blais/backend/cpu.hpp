/*
** EPITECH PROJECT, 2021
** monitor
** File description:
** cppoolrush3
*/

#ifndef _MONITOR_
#define _MONITOR_

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

class cpu {
	public:
		cpu();
		~cpu();
		void refresh();
		void ReadFile(const std::string & line);
		bool isCpu(const std::string & line);
		std::string const & getTotal() const;
		std::vector<std::string> const & getcpu() const;
		static const std::string path;
		static const std::string _cpu;
		static const std::string _total;
		int _nbr_cpu;
		size_t _len_cpu;
		std::vector<std::string> victor;
		std::string lab;
		std::string total;
	private:
		std::string more_space_string(std::string in);
		int get_number_cpu(); 
		size_t times;
	};
#endif /* !_MONITOR_ */
