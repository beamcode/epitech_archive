/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** IGameModule
*/

#ifndef IGAMEMODULE_H
#define IGAMEMODULE_H

#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <map>

class IGameModule
{
    public:
        virtual ~IGameModule() = 0;

        virtual int endGame() = 0;
        virtual void initMap() = 0;
        virtual void getEntityEvent() = 0;
        virtual void manageEvents(const std::string &key) = 0;
        virtual std::map<int, std::vector<int>> getMap() const = 0;
    protected:
    private:
};

#endif /* !IGAMEMODULE_HPP_ */
