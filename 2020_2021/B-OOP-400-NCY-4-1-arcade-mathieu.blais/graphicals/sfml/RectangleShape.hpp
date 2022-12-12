/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** RectangleShape
*/

#ifndef RECTANGLESHAPE_HPP_
#define RECTANGLESHAPE_HPP_

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>
#include "Text.hpp"

class RectangleShape
{
    public:
        RectangleShape(int sizex, int sizey, int posx, int posy, sf::Color outColor, int thickness, sf::Color fillColor);
        ~RectangleShape();

        void drawShape(sf::RenderWindow &window) const;
        int getIndex() const;
        void updateColor(sf::Color outcolor, sf::Color fillcolor);
        void drawText(std::string text);
    protected:
    private:
        sf::Vector2f _size;
        sf::Vector2f _pos;
        sf::Color _outColor;
        sf::Color _fillColor;
        int _thickness;
        sf::RectangleShape rec;
        int index;
        Text *txt;
};

#endif /* !RECTANGLESHAPE_HPP_ */
