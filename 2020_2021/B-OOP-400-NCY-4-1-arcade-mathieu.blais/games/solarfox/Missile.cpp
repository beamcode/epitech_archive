/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Missile
*/

#include "Missile.hpp"

Missile::Missile(int val, int _dir, int y, int x)
{
    proj = {val, {y, x}};
    dir = _dir;
}

Missile::~Missile()
{
}

std::pair<int, int> Missile::get_pos() const
{
    std::pair<int, int> pos = {proj.second.first, proj.second.second};
    return (pos);
}

void Missile::set_dir(int _dir)
{
    dir = _dir;
}

int Missile::get_dir()
{
    return (dir);
}

void Missile::move_proj()
{
    if (dir == 1)
        proj.second.first--;
    if (dir == 2)
        proj.second.second++;
    if (dir == 3)
        proj.second.first++;
    if (dir == 4)
        proj.second.second--;
}