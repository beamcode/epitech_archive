#ifndef IDIS_H
#define IDIS_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>

class IMonitorDisplay
{
  public:
    virtual void drawSprite() = 0;
    virtual void drawButton() = 0;
    virtual void drawRectangle() = 0;
    virtual void drawObject() = 0;
    virtual void drawText() = 0;
};
#endif
