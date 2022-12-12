/*
** EPITECH PROJECT, 2021
** parser.hpp
** File description:
** parser class header
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <map>

#define INVALID_SYNTAX "ERROR: file contains invalid syntax."
#define INVALID_CHIPSET_NAME "ERROR: unknown component type."
#define INVALID_LINK_NAME "ERROR: unknown component name."
#define INVALID_ARGS "USAGE: ./nanotekspice '.nts file'."
#define DUP_CHIPSET_NAME "ERROR: found duplicate names."
#define FILE_ERROR "ERROR: unable to open file."
#define EMPTY_FILE "ERROR: file is empty."
#define INVALID_PIN "ERROR: requested pin does not exist."

extern std::map<std::string, int> pins;

class Parser {
    public:
        //Ctor & Dtor
        Parser(std::string path);
        ~Parser();

        //Members
        std::string get_file_contents(std::string path) const;
        std::vector<std::vector<std::string>> get_chipsets() const;
        std::vector<std::vector<std::string>> get_links() const;
        int check_input();
    private:
        int fill_lines();
        void fill_vectors();
        int check_chipset_names() const;
        int check_link_names() const;
        int check_blacklist() const;
        int check_dup_name() const;
        int check_syntax() const;
        int check_pins() const;
        std::string rawfile;
        std::vector<std::string> lines;
        std::vector<std::vector<std::string>> chipsets;
        std::vector<std::vector<std::string>> links;
    protected:
};

#endif /* !PARSER_HPP_ */
