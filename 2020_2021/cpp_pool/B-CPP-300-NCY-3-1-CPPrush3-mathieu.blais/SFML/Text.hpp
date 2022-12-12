#ifndef TEXT_H
#define TEXT_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>

class Text
{
  public:
    Text(const std::string &img, const float &x, const float &y, const int &cSize, const int index);
    ~Text();
    void drawText(sf::RenderWindow &window) const;
    int getIndex() const;
    void set_String(const std::string&);
  private:
    sf::Text text;
    sf::Font font;
    sf::Vector2f pos;
    int index;
};
#endif
