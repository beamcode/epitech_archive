/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Nibbler
*/

#ifndef NIBLLER_HPP_
#define NIBLLER_HPP_

#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
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
#include <fstream>
#include <vector>
#include <map>
#include <chrono>
#include "../../graphicals/IDisplayModule.hpp"
#include "../IGameModule.hpp"

class Nibbler : public IGameModule {
    public:
        Nibbler();
        ~Nibbler();

        std::map<int, std::vector<int>> getMap() const;
        void manageEvents(const std::string &key);
        void getEntityEvent();
        void initMap();
        int endGame();
    private:
        void write_leaderboard();
        void set_dir(const std::string &key);
        double get_time() const;
        int get_score() const;
        void print_score();
        void move_snake();
        void spawnFood();
        void print_end();

        std::vector<std::pair<int, std::pair<int, int>>> snake;
        std::vector<std::vector<int>> map;
        std::string prev_dir;
        std::string dir;
        unsigned int score;
        double last_time;
        bool end;
        int lives;
        bool write;
};

#endif /* !NIBBLER_HPP_ */
