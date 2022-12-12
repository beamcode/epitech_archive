#include "Sprite.hpp"

Sprite::Sprite(const std::string &img, const float &x, const float &y, const int index)
{
    if (!this->texture.loadFromFile(img)) {
        std::cerr << "Image error" << std::endl;
        return;
    }
    this->sprite.setTexture(this->texture);
    this->pos.x = x;
    this->pos.y = y;
    this->sprite.setPosition(this->pos);
    this->index = index;
}

Sprite::~Sprite()
{

}

int Sprite::getIndex()
{
    return (this->index);
}

void Sprite::drawSprite(sf::RenderWindow &window) const
{
    window.draw(this->sprite);
}
