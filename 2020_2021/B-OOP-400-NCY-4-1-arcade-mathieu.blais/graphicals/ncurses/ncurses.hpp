/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <stddef.h>
#include <string.h>
#include <time.h>
#include <dlfcn.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <map>
#include <cmath>
#include "../IDisplayModule.hpp"
#include <cassert>

class Ncurses : public IDisplayModule {
    public:
        Ncurses();
        ~Ncurses();

        void draw_sprite();
        std::string getKey();
        void initMap(std::map<int, std::vector<int>> map);
        void refreshMap(std::map<int, std::vector<int>> map);
        void print_real(std::string map);
        void refresh_window();
        void close_window();
        void putRect(float x, float y, float w, float h) const;
        void putFillRect(float x, float y, float w, float h) const;
        void print_map();
        std::string get_name();

    private:
        void print(int x, int y, const std::string &s);
        WINDOW *window;
        std::map<int, std::vector<int>> map;
};

#endif /* !NCURSES_HPP_ */
