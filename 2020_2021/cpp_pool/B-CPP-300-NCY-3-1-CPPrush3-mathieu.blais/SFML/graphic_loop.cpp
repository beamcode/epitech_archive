#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Sprite.hpp"
#include "window.hpp"


int openGraphicDisplay()
{
    Window *win = new Window();
    win->initializeObject();
    while (win->window.isOpen()) {
        win->time = win->clock.getElapsedTime().asSeconds();
        if (win->time >= 1) {
            win->refreshModule();
            win->clock.restart();
            win->time = 0;
        }
        while (win->window.pollEvent(win->event))
            win->getEvent();
        win->drawObject();
    }
    win->closeWindow(win);
    return 0;
}
