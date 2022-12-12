/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>

class Text
{
    public:
        Text(const std::string &img, const float &x, const float &y, const int &cSize, const int index, sf::Color color);
        ~Text();

        int getIndex() const;
        void drawText(sf::RenderWindow &window) const;
        void set_String(const std::string&);
    protected:
    private:
        sf::Text text;
        sf::Font font;
        sf::Vector2f pos;
        int index;
};

#endif /* !TEXT_HPP_ */
