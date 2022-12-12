/*
** EPITECH PROJECT, 2021
** Parser.cpp
** File description:
** Parser class file
*/

#include "Parser.hpp"

std::map<std::string, int> pins = {
    {"2716", 24}, {"4001", 14}, {"4004", 16},
    {"4008", 16}, {"4011", 14}, {"4013", 13},
    {"4030", 14}, {"4071", 14}, {"4081", 14},
    {"4069", 14}, {"4017", 16}, {"4040", 16},
    {"4094", 16}, {"4512", 24}, {"4801", 24},
    {"4514", 24}, {"input", 1}, {"output", 1},
    {"true", 1}, {"false", 1}, {"clock", 1},
    {"logger", 10}
};

std::vector<std::string> chips {
    "4001", "4011", "4030", "4071", "4081",
    "4069", "4008", "4013", "4017", "4040",
    "4094", "4512", "4514", "4801", "2716",
    "4004", "input", "output", "true", "false",
    "clock", "logger"
};

std::vector<std::string> blacklist {
    "4001", "4011", "4030", "4071",
    "4081", "4069", "4004", "input",
    "output", "true", "false", "clock"
};

//Ctor & Dtor
Parser::Parser(std::string path)
{
    rawfile = get_file_contents(path);
}

Parser::~Parser()
{
}

//Members
std::vector<std::vector<std::string>> Parser::get_chipsets() const
{
    return (chipsets);
}

std::vector<std::vector<std::string>> Parser::get_links() const
{
    return (links);
}

std::string Parser::get_file_contents(std::string path) const
{
    std::ifstream ntsfile(path, std::ios_base::in);
    std::string contents;

    if (!ntsfile.is_open() || ntsfile.peek() == std::ifstream::traits_type::eof())
        return (contents);
    for (std::string line; std::getline(ntsfile, line);) {
        contents += line;
        contents.push_back('\n');
    }
    ntsfile.close();
    return (contents);
}

unsigned int count_words(const std::string &str)
{
    std::stringstream stream(str);
    return std::distance(std::istream_iterator<std::string>(stream),
            std::istream_iterator<std::string>());
}

bool is_number(const std::string &str)
{
    for (char const &c : str)
        if (std::isdigit(c) == 0)
            return false;
    return true;
}

std::vector<std::string> split(const std::string &str, const std::string &delim)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    std::string token;

    while (pos < str.length() && prev < str.length()) {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
            token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
            prev = pos + delim.length();
    }
    return (tokens);
}

int Parser::check_syntax() const
{
    std::vector<std::string> tmp;
    int part = 0;

    if (lines[0] != ".chipsets:")
        return (84);
    for(size_t i = 1; i < lines.size(); i++) {
        if (lines[i].find(".links:") != std::string::npos) {
            part++;
            continue;
        }
        if (count_words(lines[i]) != 2)
            return (84);
        if (!part)
            continue;
        tmp = split(lines[i], " ");
        if (tmp.front().find(":") == std::string::npos || \
            tmp.back().find(":") == std::string::npos  || \
            tmp.front().find(":") == std::string::npos || \
            tmp.back().find(":") == std::string::npos  || \
            !is_number(split(tmp.front(), ":").back()) || \
            !is_number(split(tmp.back(), ":").back()))
            return (84);
    }
    if (!part)
        return (84);
    return (0);
}

int Parser::check_chipset_names() const
{
    for (size_t i = 0; i < chipsets.size(); i++)
        if (std::find(chips.begin(), chips.end(), chipsets.at(i).front()) == chips.end())
            return (84);
    return (0);
}

int Parser::check_link_names() const
{
    std::vector<std::string> names;

    for (size_t i = 0; i < chipsets.size(); i++)
        names.push_back(chipsets.at(i).back());
    for (size_t i = 0; i < links.size(); i++)
        if (std::find(names.begin(), names.end(), \
            split(links.at(i).front(), ":").front()) == names.end() || \
            std::find(names.begin(), names.end(), \
            split(links.at(i).back(), ":").front()) == names.end())
            return (84);
    return (0);
}

int Parser::check_dup_name() const
{
    std::vector<std::string> names;

    for (size_t i = 0; i < chipsets.size(); i++) {
        if (std::find(names.begin(), names.end(), chipsets.at(i).back()) != names.end())
            return (84);
        names.push_back(chipsets.at(i).back());
    }
    return (0);
}

int Parser::check_pins() const
{
    for (size_t i = 0; i < links.size(); i++) {
        for (size_t a = 0; a < chipsets.size(); a++) {
            if (split(links.at(i).front(), ":").front() == chipsets.at(a).back() &&
                std::find(chips.begin(), chips.end(), chipsets.at(a).front()) != chips.end()) {
                if (std::stoi(split(links.at(i).front(), ":").back()) >
                    pins.find(chipsets.at(a).front())->second)
                    return (84);
            }
            if (split(links.at(i).back(), ":").front() == chipsets.at(a).back() &&
                std::find(chips.begin(), chips.end(), chipsets.at(a).front()) != chips.end()) {
                if (std::stoi(split(links.at(i).back(), ":").back()) >
                    pins.find(chipsets.at(a).front())->second)
                    return (84);
            }
        }
    }
    return (0);
}

void Parser::fill_vectors()
{
    int nxt = 0;

    for(size_t i = 1; i < lines.size(); i++) {
        if (lines[i].find(".links:") != std::string::npos) {
            nxt++;
            continue;
        }
        if (!nxt)
            chipsets.push_back(split(lines[i], " "));
        else
            links.push_back(split(lines[i], " "));
    }
}

int Parser::fill_lines()
{
    std::stringstream tmp(rawfile);
    const char* t = " \t\n\r\f\v";

    for (std::string line; std::getline(tmp, line);) {
        if (line[0] == '#' || line[0] == '\0' || line[0] == '\n')
            continue;
        line = line.substr(0, line.find("#"));
        line.erase(line.find_last_not_of(t) + 1);
        std::replace(line.begin(), line.end(), '\t', ' ');
        lines.push_back(line);
    }
    if (lines.empty())
        return (84);
    return (0);
}

int Parser::check_blacklist() const
{
    for (size_t i = 0; i < chipsets.size(); i++) {
        if (std::find(blacklist.begin(), blacklist.end(), chipsets.at(i).front()) == blacklist.end())
            return (84);
    }
    return (0);
}

int Parser::check_input()
{
    if (rawfile.empty()) {
        std::cerr << FILE_ERROR << std::endl;
        return (84);
    }
    if (fill_lines()) {
        std::cerr << EMPTY_FILE << std::endl;
        return (84);
    }
    if (check_syntax()) {
        std::cerr << INVALID_SYNTAX << std::endl;
        return (84);
    }
    fill_vectors();
    if (check_blacklist())
        return(84);
    if (check_chipset_names()) {
        std::cerr << INVALID_CHIPSET_NAME << std::endl;
        return (84);
    }
    if (check_dup_name()) {
        std::cerr << DUP_CHIPSET_NAME << std::endl;
        return (84);
    }
    if (check_link_names()) {
        std::cerr << INVALID_LINK_NAME << std::endl;
        return (84);
    }
    if (check_pins()) {
        std::cerr << INVALID_PIN << std::endl;
        return (84);
    }
    return (0);
}
