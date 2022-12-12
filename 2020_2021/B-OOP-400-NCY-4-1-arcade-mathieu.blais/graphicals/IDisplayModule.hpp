/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** IDisplayModule
*/

#ifndef IDISPLAYMODULE_H
#define IDISPLAYMODULE_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <map>

class IDisplayModule {
    public:
        virtual ~IDisplayModule() = 0;
        virtual void draw_sprite() = 0;
        virtual void initMap(std::map<int, std::vector<int>> map) = 0;
        virtual void refreshMap(std::map<int, std::vector<int>> map) = 0;
        virtual std::string getKey() = 0;
    protected:
    private:
};

#endif /* !IDISPLAYMODULE_HPP_ */
