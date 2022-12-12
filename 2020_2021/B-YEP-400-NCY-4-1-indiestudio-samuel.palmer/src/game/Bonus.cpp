/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** bonus
*/

#include "Bonus.hpp"

Bonus::Bonus(const std::string &obj, const std::string &_texture, int index) : _Model(obj, _texture, index)
{
    set_scale(0.4, 0.4, 0.4);
    set_angle(90);
}

Bonus::~Bonus()
{
}

bool Bonus::hasPlayerOn(std::shared_ptr<Player> player)
{
    Vector3 pos = player->get_pos();
    float posx = static_cast<int>(pos.x) + 0.5;
    float posz = static_cast<int>(pos.z) + 0.5;

    if (posx == position.x && posz == position.z) {
        time = GetTime();
        return (true);
    }
    return (false);
}
