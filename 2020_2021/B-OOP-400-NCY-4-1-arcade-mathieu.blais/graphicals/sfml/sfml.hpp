/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** core
*/

#ifndef SFML_HPP_
#define SFML_HPP_

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
#include <vector>
#include <map>
#include "../IDisplayModule.hpp"
#include <SFML/Graphics.hpp>
#include "RectangleShape.hpp"
#include "Text.hpp"

class SFML : public IDisplayModule {
    public:
        SFML();
        ~SFML();

        void draw_sprite();
        void initMap(std::map<int, std::vector<int>> map);
        void refreshMap(std::map<int, std::vector<int>> map);
        std::string getKey();

    private:
        sf::RenderWindow window;
        sf::Event event;
        std::map<int, std::vector<int>> map;
        std::vector<std::vector<RectangleShape*>> squares;
};

#endif /* !SFML_HPP_ */
