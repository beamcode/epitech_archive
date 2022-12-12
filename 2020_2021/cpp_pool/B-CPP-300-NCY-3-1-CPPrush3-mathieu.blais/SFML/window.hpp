#ifndef WINDOW_H
#define WINDOW_H
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <ostream>
#include <fstream>
#include "Sprite.hpp"
#include "Text.hpp"
#include "RectangleShape.hpp"
#include "Button.hpp"
#include "IMonitorModule.hpp"
#include "IMonitorDisplay.hpp"
#include "../backend/ram.hpp"
#include "../backend/info.hpp"
#include "../backend/hardware.hpp"

int openGraphicDisplay();

class Window : public IMonitorModule, public IMonitorDisplay
{
  public:
    Window();
    virtual ~Window();
    void closeWindow(Window *win);
    void refreshModule();
    void refreshRam();
    void initializeObject();
    void initCpu();
    void drawObject();
    void getEvent();
    void createSprite();
    void drawSprite();
    void drawButton();
    void drawRectangle();
    void createRectangleShape();
    void initRectangle(int sizex, int sizey, int posx, int posy, sf::Color outColor, int thickness, sf::Color fillColor, int index);
    void drawText();
    void initText(const std::string &txt, const float &x, const float &y, const int &cSize, const int index);
    void createText();
    void initSprite(const std::string &txt, const float &x, const float &y, const int index);
    void initButton(const std::string &txt, const float &x, const float &y, const int index);
    void search_button_event();
    void lookForAnimation();
    std::vector<Sprite*> vec;
    std::vector<Button*> but;
    std::vector<Text*> txt;
    std::vector<RectangleShape*> rec;
    sf::RenderWindow window;
    sf::Event event;
    sf::Clock clock;
    float time = 0;
    int sizex;
    int sizey;
    int posx;
    int posy;
    sf::Color fillColor;
    sf::Color outColor;
    std::string total;
    std::vector<std::string> stvec;
    ram a;
    info inf;
    hardware h;
  private:
    int display;
    sf::Font font;
    sf::Vector2i posClic;
    sf::Vector2i posMouse;
};
#endif
