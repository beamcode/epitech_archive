/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** bomb
*/

#include "Fire.hpp"

Fire::Fire(const std::string &obj, const std::string &_texture) :  _Model(obj, _texture)
{
    set_scale(0.9, 0.9, 0.9);
    time = GetTime();
}

Fire::~Fire()
{

}

bool Fire::timeToStop()
{
    if (time + 0.5 < GetTime() || time == 0)
        return (true);
    return (false);
}
