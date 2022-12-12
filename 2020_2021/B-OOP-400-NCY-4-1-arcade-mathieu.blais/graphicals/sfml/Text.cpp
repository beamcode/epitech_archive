#include "Text.hpp"

Text::Text(const std::string &txt, const float &x, const float &y, const int &cSize, const int index, sf::Color color)
{
    if (!this->font.loadFromFile("graphicals/sfml/font.ttf")) {
        std::cerr << "Font Error" << std::endl;
        return;
    }
    this->text.setFont(this->font);
    this->text.setString(txt);
    this->text.setCharacterSize(cSize);
    this->text.setFillColor(color);
    this->pos.x = x;
    this->pos.y = y;
    this->text.setPosition(this->pos);
    this->index = index;
}

Text::~Text()
{

}

int Text::getIndex() const
{
    return (this->index);
}

void Text::drawText(sf::RenderWindow &window) const
{
    window.draw(this->text);
}

void Text::set_String(const std::string &tmp)
{
    this->text.setString(tmp);
}
