#include "RectangleShape.hpp"

RectangleShape::RectangleShape(int sizex, int sizey, int posx, int posy, sf::Color outColor, int thickness, sf::Color fillColor, int index)
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
    this->index = index;
}

RectangleShape::~RectangleShape()
{

}

int RectangleShape::getIndex() const
{
    return (this->index);
}

void RectangleShape::drawShape(sf::RenderWindow &window) const
{
    window.draw(this->rec);
}

void RectangleShape::refreshShape(int sizex, int sizey, int posx, int posy, sf::Color fillColor, sf::Color outColor)
{
    this->_size.x = sizex;
    this->_size.y = sizey;
    this->_pos.x = posx;
    this->_pos.y = posy;
    this->_outColor = outColor;
    this->_fillColor = fillColor;
    this->rec.setSize(this->_size);
    this->rec.setPosition(this->_pos);
    this->rec.setFillColor(this->_fillColor);
    this->rec.setOutlineColor(this->_outColor);
}
