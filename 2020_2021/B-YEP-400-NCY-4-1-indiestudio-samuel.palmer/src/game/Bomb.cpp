/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** bomb
*/

#include "Bomb.hpp"

Bomb::Bomb(const std::string &obj, const std::string &_texture, int _index) : _Model(obj, _texture, _index)
{
    index = _index;
    time = GetTime();
    std::shared_ptr<_Sound> _sound(new _Sound("resources/audio/tnt.ogg"));
    sound = _sound;
}

Bomb::~Bomb()
{
}

void Bomb::playSound()
{
    sound->play_sound();
}

bool Bomb::timeToDestroy()
{
    float t = GetTime();
    if (t > time + 3)
        return (true);
    return (false);
}

bool Bomb::destroy()
{
    this->scale.x += 0.002;
    this->scale.z += 0.002;
    if (this->scale.x > 0.35)
        return (true);
    return (false);
}

int Bomb::getIndex() const
{
    return (index);
}
