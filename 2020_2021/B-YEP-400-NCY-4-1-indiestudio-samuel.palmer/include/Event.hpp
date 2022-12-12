/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** Event
*/

#ifndef EVENT_HPP_
#define EVENT_HPP_

#include <raylib.h>
#include <string>
#include <memory>
#include "Sprite.hpp"

class Event {
    public:
        Event();
        virtual ~Event();
        Vector2 getMousePosition();
        bool hasClicked(int button);
        bool hasClickOnSprite(std::shared_ptr<Sprite> sprite, int xminshift, int xmaxshift, int yminshift, int ymaxshift);
        bool hasMouseOnSprite(std::shared_ptr<Sprite> sprite, int xminshift, int xmaxshift, int yminshift, int ymaxshift);
    protected:
    private:
};

#endif /* !EVENT_HPP_ */
