/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** core
*/

#ifndef MENU_HPP_
#define MENU_HPP_

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

class Menu : public IGameModule {
    public:
        Menu();
        ~Menu();

        int endGame();
        void initMap();
        void getEntityEvent();
        void manageEvents(const std::string &key);
        std::map<int, std::vector<int>> getMap() const;
    private:
        void setMenuGameChoices(const int &direction);
        void setMenuGraphChoices(const int &direction);
        double get_time() const;
        void changeLetterPosition(std::string key);
        void changeLetter();
        void getScoreBoard();
        void printSolarFoxScoreboard(std::map<int, std::string> mapSolarfox);
        void printNibblerScoreboard(std::map<int, std::string> mapNibbler);
        void printLastScore();

        std::map<int, std::vector<int>> map;
        std::vector<int> mapSave;
        std::vector<std::string> gameList;
        std::vector<std::string> graphList;
        int index1;
        int index2;
        int event;
        double last_time;
        double ticks_ps;
        int letter;
        std::string name;
        std::string score;
};

#endif /* !menu_HPP_ */
