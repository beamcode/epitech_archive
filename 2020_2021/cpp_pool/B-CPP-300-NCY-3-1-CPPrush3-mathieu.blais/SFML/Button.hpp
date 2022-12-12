#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>
#include "Sprite.hpp"

class Button : public Sprite
{
  public:
    Button(const std::string &img, const float &x, const float &y, const int index);
    virtual ~Button();
    sf::Vector2f posMax;
    sf::Vector2f posMin;
    int on;
  private:
};
#endif
