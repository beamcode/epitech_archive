#ifndef IMOD_H
#define IMOD_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>

class IMonitorModule
{
  public:
    virtual void refreshModule() = 0;
    virtual void createSprite() = 0;
    virtual void createRectangleShape() = 0;
    virtual void createText() = 0;
    virtual void initializeObject() = 0;
    virtual void initCpu() = 0;
    virtual void initRectangle(int sizex, int sizey, int posx, int posy, sf::Color outColor, int thickness, sf::Color fillColor, int index) = 0;
    virtual void initText(const std::string &txt, const float &x, const float &y, const int &cSize, const int index) = 0;
    virtual void initSprite(const std::string &txt, const float &x, const float &y, const int index) = 0;
    virtual void initButton(const std::string &txt, const float &x, const float &y, const int index) = 0;
    virtual void getEvent() = 0;
    virtual void search_button_event() = 0;
    virtual void lookForAnimation() = 0;
};
#endif
