#ifndef REC_H
#define REC_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>

class RectangleShape
{
  public:
    RectangleShape(int sizex, int sizey, int posx, int posy, sf::Color outColor, int thickness, sf::Color fillColor, int index);
    ~RectangleShape();
    void drawShape(sf::RenderWindow &window) const;
    int getIndex() const;
    void refreshShape(int sizex, int sizey, int posx, int posy, sf::Color fillColor, sf::Color outColor);
 private:
    sf::Vector2f _size;
    sf::Vector2f _pos;
    sf::Color _outColor;
    sf::Color _fillColor;
    int _thickness;
    sf::RectangleShape rec;
    int index;
};
#endif
