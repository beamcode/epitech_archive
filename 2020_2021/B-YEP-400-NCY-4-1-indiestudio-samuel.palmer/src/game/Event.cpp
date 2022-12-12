/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Event
*/

#include "Event.hpp"

Event::Event()
{
}

Event::~Event()
{
}

bool Event::hasClicked(int button)
{
    return (IsMouseButtonPressed(button));
}

Vector2 Event::getMousePosition()
{
    Vector2 _mousePos;
    _mousePos = GetMousePosition();
    return (_mousePos);
}

bool Event::hasClickOnSprite(std::shared_ptr<Sprite> sprite, int xminshift, int xmaxshift, int yminshift, int ymaxshift)
{
    Vector2 pos = getMousePosition();

    if (pos.x > sprite->getXPosition() - xminshift && pos.x < sprite->getXPosition() + xmaxshift
    && pos.y > sprite->getYPosition() - yminshift && pos.y < sprite->getYPosition() + ymaxshift)
        return (true);
    return (false);
}

bool Event::hasMouseOnSprite(std::shared_ptr<Sprite> sprite, int xminshift, int xmaxshift, int yminshift, int ymaxshift)
{
    Vector2 pos = getMousePosition();

    if (pos.x > sprite->getXPosition() - xminshift && pos.x < sprite->getXPosition() + xmaxshift
    && pos.y > sprite->getYPosition() - yminshift && pos.y < sprite->getYPosition() + ymaxshift)
        return (true);
    return (false);
}
