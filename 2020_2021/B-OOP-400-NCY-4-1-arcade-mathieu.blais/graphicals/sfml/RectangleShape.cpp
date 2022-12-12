/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** RectangleShape
*/

#include "RectangleShape.hpp"

RectangleShape::RectangleShape(int sizex, int sizey, int posx, int posy, sf::Color outColor, int thickness, sf::Color fillColor)
{
    this->_size.x = sizex;
    this->_size.y = sizey;
    this->_pos.x = posx;
    this->_pos.y = posy;
    this->_outColor = outColor;
    this->_fillColor = fillColor;
    this->_thickness = thickness;
    this->rec.setSize(this->_size);
    this->rec.setPosition(this->_pos);
    this->rec.setOutlineThickness(this->_thickness);
    this->rec.setOutlineColor(this->_outColor);
    this->rec.setFillColor(this->_fillColor);
    this->txt = new Text("", this->_pos.x, this->_pos.y, this->_size.x + 4.9, 0, sf::Color (255, 255, 255));
}

RectangleShape::~RectangleShape()
{
    delete this->txt;
}

int RectangleShape::getIndex() const
{
    return (this->index);
}

void RectangleShape::drawShape(sf::RenderWindow &window) const
{
    window.draw(this->rec);
    this->txt->drawText(window);
}

void RectangleShape::updateColor(sf::Color outColor, sf::Color fillColor)
{
    this->rec.setOutlineColor(outColor);
    this->rec.setFillColor(fillColor);
    this->txt->set_String("");
}

void RectangleShape::drawText(std::string text)
{
    this->rec.setOutlineColor(sf::Color (0, 0, 0));
    this->rec.setFillColor(sf::Color (0, 0, 0));
    this->txt->set_String(text);
}
