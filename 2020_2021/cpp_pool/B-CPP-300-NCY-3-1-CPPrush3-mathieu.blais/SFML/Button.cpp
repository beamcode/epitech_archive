#include "Button.hpp"

Button::Button(const std::string &img, const float &x, const float &y, const int index) : Sprite(img, x, y, index)
{
    this->posMax.x = x + 140;
    this->posMax.y = y + 100;
    this->posMin.x = x;
    this->posMin.y = y + 30;
    this->on = 0;
}

Button::~Button()
{

}
