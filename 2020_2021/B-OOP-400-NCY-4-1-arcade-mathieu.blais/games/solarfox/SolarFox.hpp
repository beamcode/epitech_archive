/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** SolarFox
*/

#ifndef SolarFox_HPP_
#define SolarFox_HPP_

#include <chrono>
#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
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
#include <vector>
#include <map>

#include "../../graphicals/IDisplayModule.hpp"
#include "../IGameModule.hpp"
#include "Missile.hpp"
#include "Ship_Proj.hpp"

class SolarFox : public IGameModule {
    public:
        SolarFox();
        ~SolarFox();

        int endGame();
        void initMap();
        int get_score() const;
        void getEntityEvent();
        void manageEvents(const std::string &key);
        std::map<int, std::vector<int>> getMap() const;
    private:
        void print_end();
        void move_guns();
        void move_player();
        void print_score();
        void manage_proj();
        void manage_missiles();
        double get_time() const;
        void check_events();
        void write_leaderboard();
        void movePlayer(std::string key);

        std::vector<Missile *> missiles;
        std::vector<Ship_Proj *> ship_p;

        std::vector<std::vector<int>> map;
        std::vector<std::vector<int>> proj_map;
         
        std::pair<int, std::pair<int, int>> gun_1;
        std::pair<int, std::pair<int, int>> gun_2;
        std::pair<int, std::pair<int, int>> player;

        // Clocks
        double tmp_time;

        double last_time_proj;
        double last_time_guns;
        double last_time_player;
        double last_time_missiles;
        double last_time_gameover;
        double last_time_spawn_proj;
        double last_time_spawn_missiles;

        // Speeds
        double proj_speed;
        double guns_speed;
        double player_speed;
        double missiles_speed;
        double proj_spawn_speed;
        double missiles_spawn_speed;

        // Other
        bool end;
        bool win;
        int lives;
        int score;
        bool write;
        int guns_dir;
        int player_dir;
        int gameover_time;
        int prev_player_dir;
};

#endif /* !SolarFox_HPP_ */
