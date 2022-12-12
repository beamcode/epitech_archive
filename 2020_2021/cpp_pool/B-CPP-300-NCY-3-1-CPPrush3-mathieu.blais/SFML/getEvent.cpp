#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "window.hpp"

void Window::search_button_event()
{
    for (size_t i = 0; i < this->but.size(); i++) {
        if (this->posClic.x < this->but[i]->posMax.x && this->posClic.x > this->but[i]->posMin.x
        && this->posClic.y < this->but[i]->posMax.y && this->posClic.y > this->but[i]->posMin.y) {
            this->display = i;
        }
    }
}

void Window::lookForAnimation()
{
    for (size_t i = 0; i < this->but.size(); i++) {
        if (this->posMouse.x < this->but[i]->posMax.x && this->posMouse.x > this->but[i]->posMin.x
        && this->posMouse.y < this->but[i]->posMax.y && this->posMouse.y > this->but[i]->posMin.y)
            this->but[i]->on = 1;
        else
            this->but[i]->on = 0;
    }
}

void Window::getEvent()
{
    if (this->event.type == sf::Event::Closed)
        this->window.close();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        this->window.close();
    this->posMouse = sf::Mouse::getPosition(this->window);
    if (this->event.type == sf::Event::MouseButtonPressed) {
      this->posClic = sf::Mouse::getPosition(this->window);
      this->search_button_event();
    }
    this->lookForAnimation();
}
