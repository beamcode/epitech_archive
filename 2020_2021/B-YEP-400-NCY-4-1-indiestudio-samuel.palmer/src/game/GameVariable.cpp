/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** gamevariable
*/


#include "GameVariable.hpp"

GameVariable::GameVariable()
{
    time = GetTime();
    time2 = GetTime();
    range = 30;
    delay = 30;
}

GameVariable::~GameVariable()
{
}

bool GameVariable::boomDistance()
{
    if (time + range < GetTime() || time == 0) {
        time = GetTime();
        return (true);
    }
    return (false);
}

bool GameVariable::bombTime()
{
    if (time2 + delay < GetTime() || time2 == 0) {
        time2 = GetTime();
        return (true);
    }
    return (false);
}

void GameVariable::setRange(int _range)
{
    range = _range;
}

void GameVariable::setDelay(int _delay)
{
    delay = _delay;
}
