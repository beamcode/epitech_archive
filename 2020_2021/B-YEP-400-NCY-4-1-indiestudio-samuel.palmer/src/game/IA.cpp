/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** ia
*/

#include "IA.hpp"

IA::IA(const std::string &obj, const std::string &_texture) : Player(obj, _texture)
{
    t = rand() % 4;
    tmp = 0;
}

IA::~IA()
{
}

void IA::moveIA()
{
    float angle = -1.0f;

    if (tmp == 50) {
        t = rand() % 4;
        tmp = 0;
    }
    if (t == 0) {
        angle = 270.0f;
        if (check_collision(position.x, position.z + move)) {
            position.z += move;
            tmp++;
        }
        else
            tmp++;
    }
    if (t == 1) {
        angle = 180.0f;
        if (check_collision(position.x - move, position.z)) {
            position.x -= move;
            tmp++;
        }
        else
            tmp++;
    }
    if (t == 2) {
        angle = 90.0f;
        if (check_collision(position.x, position.z - move)) {
            position.z -= move;
            tmp++;
        }
        else
            tmp++;
    }
    if (t == 3) {
        angle = 0.0f;
        if (check_collision(position.x + move, position.z)) {
            position.x += move;
            tmp++;
        }
        else
            tmp++;
    }
    if (angle > -1.0f)
        set_angle(angle);
    if (t < 4 && t > 0)
        play_animation(1);
    else
        play_animation(0);
}
