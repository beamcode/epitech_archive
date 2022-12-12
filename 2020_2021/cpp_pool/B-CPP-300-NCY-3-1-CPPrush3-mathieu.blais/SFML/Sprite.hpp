#ifndef SPRITE_H
#define SPRITE_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>

class Sprite {
  public:
    Sprite() {}
    Sprite(const std::string &img, const float &x, const float &y, const int index);
    virtual ~Sprite();
    void drawSprite(sf::RenderWindow &window) const;
    int getIndex();
  protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f pos;
    int index;
};
#endif
