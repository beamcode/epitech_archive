/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Ship_Proj
*/

#include "Ship_Proj.hpp"

Ship_Proj::Ship_Proj(int y, int x, int _dir) : color(120)
{
    moved = 0;
    dir = _dir;
    pos = {y, x};
}

Ship_Proj::~Ship_Proj()
{
}

std::pair<int, int> Ship_Proj::get_pos() const
{
    return (pos);
}

int Ship_Proj::get_color()
{
    return (color);
}

int Ship_Proj::decay()
{
    return (moved);
}

void Ship_Proj::move_proj()
{
    moved++;
    if (dir == 1)
        pos.first--;
    if (dir == 2)
        pos.second++;
    if (dir == 3)
        pos.first++;
    if (dir == 4)
        pos.second--;
}