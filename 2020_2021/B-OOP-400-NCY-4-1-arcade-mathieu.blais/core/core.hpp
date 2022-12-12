/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** core
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <dlfcn.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <thread>
#include <string>
#include <map>
#include "../graphicals/IDisplayModule.hpp"
#include "../games/IGameModule.hpp"
#include "exception.hpp"
#include "dlfcn.hpp"

class Core {
    public:
        Core();
        ~Core();
        void loadGraphicalLibrairies(const std::string &arg);
        void loadGame(const std::string &arg);
        void getBaseLib(const std::string &arg);
        void SetupGame() const;
        void displayGame();
    protected:
    private:
        double get_time() const;
        void refreshGame();
        void changeGraphicLib(const std::string &key);
        void changeGame(const std::string &key);
        void backToMenu();

        IDisplayModule *graphLib;
        IGameModule *game;
        std::vector<std::pair<std::string, std::string>> gameList;
        std::vector<std::pair<std::string, std::string>> graphList;
        std::string actualLib;
        std::string actualGame;
        void *graphHandler;
        void *gameHandler;
};

#endif /* !CORE_HPP_ */
