/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** variable
*/

#ifndef GAMEVARIABLE_HPP_
#define GAMEVARIABLE_HPP_

#include <raylib.h>
#include <raymath.h>
#include <string>
#include <memory>
#include <vector>
#include <iostream>

class GameVariable {
  public:
    GameVariable();
    ~GameVariable();
    bool boomDistance();
    bool bombTime();
    void setRange(int _range);
    void setDelay(int _delay);

  private:
    float time;
    float time2;
    int range;
    int delay;
};

#endif /* !GAMEVARIABLE_HPP_ */
