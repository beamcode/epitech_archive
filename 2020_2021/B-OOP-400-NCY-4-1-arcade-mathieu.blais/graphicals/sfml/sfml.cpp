/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** main
*/

#include "sfml.hpp"

extern "C"
{
    IDisplayModule *entryPoint();
}

IDisplayModule *entryPoint()
{
    return (new SFML());
}

IDisplayModule::~IDisplayModule()
{
}

SFML::SFML()
{
    this->window.create(sf::VideoMode(1200, 600), "SFML");
}

SFML::~SFML()
{
    for (size_t i = 0; i < this->squares.size(); i++) {
        for (size_t y = 0; y < this->squares.at(i).size(); y++)
            delete this->squares.at(i).at(y);
    }
    this->window.close();
}

void SFML::initMap(std::map<int, std::vector<int>> map)
{
    int size = 25;
    std::vector<RectangleShape*> tmp;

    for (size_t i = 0, y = 5; i < map.size(); i++, y += size) {
        for (size_t j = 0, x = 14; j < map.begin()->second.size(); j++, x += size)
            tmp.push_back(new RectangleShape(20, 20, x, y, sf::Color (0, 0, 0), 3, sf::Color (0, 0, 0)));
        this->squares.push_back(tmp);
        tmp.clear();
    }
}

void SFML::refreshMap(std::map<int, std::vector<int>> map)
{
    for (auto it = map.begin(); it != map.end(); ++it) {
        for (size_t i = 0, k = it->first - 1; i < it->second.size(); i++) {
            std::string str(1, (char)it->second.at(i));
            if (it->second.at(i) == 0)
                this->squares.at(k).at(i)->updateColor(sf::Color (0, 0, 0), sf::Color (0, 0, 0));
            if (it->second.at(i) == 1)
                this->squares.at(k).at(i)->updateColor(sf::Color (179, 0, 179), sf::Color (179, 0, 179));
            if (it->second.at(i) == 2)
                this->squares.at(k).at(i)->updateColor(sf::Color (0, 1, 178), sf::Color (0, 1, 178));
            if (it->second.at(i) == 3)
                this->squares.at(k).at(i)->updateColor(sf::Color (0, 66, 0), sf::Color (0, 66, 0));
            if (it->second.at(i) == 4)
                this->squares.at(k).at(i)->updateColor(sf::Color (1, 166, 178), sf::Color (1, 166, 178));
            if (it->second.at(i) == 5)
                this->squares.at(k).at(i)->updateColor(sf::Color (255, 19, 0), sf::Color (255, 19, 0));
            if (it->second.at(i) > 5)
                this->squares.at(k).at(i)->drawText(str);
        }
    }
}

std::string SFML::getKey()
{
    while (this->window.pollEvent(this->event)) {
        if (this->event.type == sf::Event::Closed) {
            this->window.close();
            return ("null");
        }
        if (this->event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Right)
                return ("right");
            if (event.key.code == sf::Keyboard::Escape)
                return ("null");
            if (event.key.code == sf::Keyboard::Left)
                return ("left");
            if (event.key.code == sf::Keyboard::A)
                return ("a");
            if (event.key.code == sf::Keyboard::Z)
                return ("z");
            if (event.key.code == sf::Keyboard::Q)
                return ("q");
            if (event.key.code == sf::Keyboard::S)
                return ("s");
            if (event.key.code == sf::Keyboard::P)
                return ("p");
            if (event.key.code == sf::Keyboard::Up)
                return ("up");
            if (event.key.code == sf::Keyboard::Down)
                return ("down");
            if (event.key.code == sf::Keyboard::Enter)
                return ("enter");
            if (event.key.code == sf::Keyboard::M)
                return ("m");
            if (event.key.code == sf::Keyboard::R)
                return ("r");
            if (event.key.code == sf::Keyboard::Space)
                return ("space");
        }
    }
    return ("other");
}

void SFML::draw_sprite()
{
    this->window.clear();
    for (auto &row:this->squares) {
        for (auto &col:row)
            col->drawShape(this->window);
    }
    this->window.display();
}
